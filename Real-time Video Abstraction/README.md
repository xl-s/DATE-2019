# Real-time Video Abstraction

The base file contains two classes: `Video` and `Stream`.

`Video` directly outputs a video from the first available hardware video source (typically a webcam). 
`Stream` automatically obtains a video stream from an indicated web source.

For either class, simply call `.start()` to begin the output.
A `url` parameter must be specified for `Stream.start()` - this should be the URL of the stream's web source. The resolution can also be specified using the `resolution` parameter (the typical options are `'360p'`, `'480p'`, `'720p'`, `'720p60'`, `'1080p'`, and `'1080p60'`).
A `capture` parameter may also optionally be specified for `Video.start()`. This can be a local video file, or a web source as well (however, you are likely to run into issues if you do this - hence the existence of `Stream`, which you should use for live streaming sources instead).

Finally, an additional parameter, `plugins`, may be specified for either `Video` or `Stream`.
This should be a list of plugin objects. Each plugin class should minimally contain a `Plugin.run(self, parent, frame)` method. This will be called whenever a new frame is loaded on the parent class, and should return a frame as well (with any desired processing performed on it).
Additionally, the following methods may be optionally included:

- `Plugin.start(self, parent)`, which is called when the parent class is initialized.
- `Plugin.key_func(self, key)`, which reads any keyboard inputs passed on from the parent `Video` or `Stream`.
- `Plugin.mouse_event(self, event, x, y, flags, param)`, which reads any mouse event passed on from the parent `Video` or `Stream`.
- `Plugin.stop(self)`, which is called when the parent class stops.

Note that the order of processing will follow the order of the list of plugins.

While it is possible to perform all processing by directly modifying or writing inherited classes of the `Video` and `Stream` classes, it is highly recommended that you write a separate class (or even just a `.run()` function) to be passed to the `plugins` parameter instead for any new operation/processing which you want to come up with. 
This will keep all of the various functions and operations which we come up with more organized and modularized, and will also allow everyone to easily use each others' algorithms and techniques.

The `plugins.py` file will be periodically updated with some of the processing operations which have already been developed.

Usage example:
```python
from rtva_base import Stream
from plugins import Record

# This is all you need to begin a video stream with the Record plugin.
Stream().start(url='https://www.twitch.tv/randomstreamer', plugins=[Record()])
```

## Requirements

- OpenCV (`pip install opencv-python`)
- Streamlink (`pip install streamlink`)
- FFmpeg  (https://ffmpeg.org)

For the `Stream` class to operate properly, you should be able to call `ffmpeg` from your windows command line (add `ffmpeg.exe` to your PATH environment variables).
Alternatively, you can just place `ffmpeg.exe` in your working directory, and change `'ffmpeg'` of the `spcmd` on line 140 to `'ffmpeg.exe'` (I haven't actually tried this, but it should work).

## Plugins

#### `Record`
This plugin enables the recording of whichever video stream is being displayed with the <kbd>SPACE</kbd> key. The output file name may be changed by specify the `output_name` parameter on initialization.

#### `ColourTrack`
Tracks the average position of a colour on the video. This colour is selected by left-clicking on the video.

#### `EdgeDetect`
Find edges on the video using the Canny edge detection algorithm. This may be done either through the red, green, blue, or grayscale channels.

#### `ColourFilter`
Filter the video for a certain range of colours, specified as HSV values in the `lower_hsv` and `upper_hsv` parameters on initialization.

#### `ROIFilter`
Filter the video to a certain range of the image, specified as list/array with format `[[top_left], [bottom_right]]` in the `roi` parameter on initialization. The range of image may be provided as a proportion of the image (set all values <= 1) or as a pixel resolution value (set any value > 1).

#### `ObjectFinder`
Find an object in the video using Haar cascade classification. The `.xml` file of the trained classifier should be provided in the `object_data` parameter on initialization. Otherwise, the plugin defaults to using the built-in OpenCV face detection.

#### `BackgroundSubtractMOG`
Find the foreground objects in the video using OpenCV's built-in background subtraction algorithm.

#### `BackgroundSubtractDirect`
A customized background subtraction algorithm with a more sensitive response, designed to detect UI elements (after inversion). Note that this operates much more slowly than the built-in MOG algorithm.

#### `Invert`
Invert the video.
