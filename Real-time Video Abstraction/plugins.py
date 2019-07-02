import cv2

class Record:
	def __init__(self, output_name='output.mp4'):
		self.output_name = output_name

	def start(self, parent):
		self.recording = False
		self.width, self.height = 0, 0
		self.frame_rate = parent.frame_rate

	def run(self, parent, frame):
		if not self.width or not self.height:
			self.height, self.width, _ = frame.shape
		if self.recording: self.output.write(frame)
		return frame

	def start_record(self):
		self.output = cv2.VideoWriter(self.output_name, cv2.VideoWriter_fourcc(*'X264'), self.frame_rate, (self.width, self.height), True)
		self.recording = True
		print('Recording Started.')

	def stop_record(self):
		self.recording = False
		self.output.release()
		print('Recording Stopped.')

	def key_func(self, key):
		if key == 32:    # space
			if self.recording:
				self.stop_record()
			else:
				self.start_record()

	def stop(self):
		if self.recording: self.stop_record()
