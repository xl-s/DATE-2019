import numpy as np
import cv2
from ortools.graph.pywrapgraph import LinearSumAssignment


def get_pairing(ER_matrix):
	solver = LinearSumAssignment()

	for row, line in enumerate(ER_matrix):
		for col, ER in enumerate(line):
			solver.AddArcWithCost(row, col, int(ER))

	solver.Solve()
	total_ER = solver.OptimalCost()
	pairing = [solver.RightMate(i) for i in range(len(ER_matrix))]

	return pairing, total_ER


def get_average_colour(image):
	b = np.average(image[:,:,0])
	g = np.average(image[:,:,1])
	r = np.average(image[:,:,2])
	return round(b), round(g), round(r)


def get_error(image, pixel):
	img = [int(i) for i in image]
	pix = [int(p) for p in pixel]
	db = img[0] - pix[0]
	dg = img[1] - pix[1]
	dr = img[2] - pix[2]
	return (db**2 + dg**2 + dr**2)


def get_avcs(images):
	return [get_average_colour(image) for image in images]


def get_ER_matrix(avcs, ref):
	flat_ref = np.reshape(ref, (-1, 3))
	flat_avcs = np.reshape(avcs, (-1, 3))

	ER_matrix = []
	for a in flat_avcs:
		for r in flat_ref:
			ER_matrix.append(get_error(a, r))

	return np.reshape(ER_matrix, (len(flat_ref), -1))


def get_images(number, folder='images'):
	if type(number) == int:
		number = range(number)
	names = ['{}/{:0>3}.jpg'.format(folder, i) for i in number]
	images = []
	for name in names:
		print("Loading {}...".format(name))
		images.append(cv2.imread(name))
	return images


def crop_images(images):
	print('Cropping all images...')
	cropped_images = []
	for image in images:
		shape = np.shape(image)
		if shape[0] > shape[1]:
			start = int((shape[0] - shape[1]) / 2)
			cropped_image = image[start:start+shape[1],:,:]
		elif shape[1] > shape[0]:
			start = int((shape[1] - shape[0]) / 2)
			cropped_image = image[:,start:start+shape[0],:]
		else:
			cropped_image = image
		cropped_images.append(cropped_image)
	return cropped_images


def resize_images(images, size=0):
	if not size:
		sizes = [np.shape(image)[0] for image in images]
		size = (min(sizes), min(sizes))

	if type(size) == int: size = (size, size)
	print('Resizing images to {}x{} pixels...'.format(size[0], size[1]))

	resized_images = []
	for image in images:
		if np.shape(image)[0] != size:
			resized_image = cv2.resize(image, size, interpolation=cv2.INTER_AREA)
		else:
			resized_image = image
		resized_images.append(resized_image)
	return resized_images


def save_images(images, folder='processed', raw=False, names=0):
	if not names:
		names = [i for i in range(len(images))]
	for name, image in zip(names, images):
		if raw:
			print('Saving {}/{:0>3}.npy...'.format(folder, name))
			np.save('{}/{:0>3}'.format(folder, name), image)
		else:
			print('Saving {}/{:0>3}.jpg...'.format(folder, name))
			cv2.imwrite('{}/{:0>3}.jpg'.format(folder, name), image)


def map_images(pairings, images, shape=(26, 26)):
	pairings = np.reshape(pairings, shape)
	print('Stitching images...')
	lines = []
	for row in pairings:
		lines.append(np.hstack([images[i] for i in row]))

	image = np.vstack(lines)
	return image
