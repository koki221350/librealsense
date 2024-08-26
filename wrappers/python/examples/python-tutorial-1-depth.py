## License: Apache 2.0. See LICENSE file in root directory.
## Copyright(c) 2015-2017 Intel Corporation. All Rights Reserved.

#####################################################
## librealsense tutorial #1 - Accessing depth data ##
#####################################################

# First import the library
import pyrealsense2 as rs


try:
    # Create a context object. This object owns the handles to all connected realsense devices
     # Name rs.pipeline() as "pipeline"
     # Pipeline is an object to manage stream, which allows data deprivation and setting changes
    pipeline = rs.pipeline()

    # Configure streams(setting of streams)
    
    config = rs.config()
    # stream setting 640*480 pixels, bit depth of each pixel(16 bits), 30fps(frame rate)
    config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)

    # Start streaming
    pipeline.start(config)

    while True:
        # This call waits until a new coherent set of frames is available on a device
        # Calls to get_frame_data(...) and get_frame_timestamp(...) on a device will return stable values until wait_for_frames(...) is called
        frames = pipeline.wait_for_frames()
        # get depth frame
        depth = frames.get_depth_frame()
        # Skip iteration if depth frame doesn't exist
        if not depth: continue

        # Print a simple text-based representation of the image, by breaking it into 10x20 pixel regions and approximating the coverage of pixels within one meter
        # create 64 0 factors 
        coverage = [0]*64
        
        # in range 0~479
        for y in range(480):
         # in range 0~639
            for x in range(640):
              # get depth data in designated (x,y)range
                dist = depth.get_distance(x, y)
                # if 0<dist,1
                if 0 < dist and dist < 1:
                    # sort depending on the distance(in 10 pixel range) and add to coverage list
                    coverage[x//10] += 1
                    
            # do the following process each per 20 pixels
            if y%20 is 19:
                # make vacant low
                line = ""
                for c in coverage:
                    #split coverage into 8 categories(".~W")
                    # since the numbers in coverage[] are within a range between 0~200 devide by 25 
                    line += " .:nhBXWW"[c//25]
                #reset coverage list and prepare for next 20 pixels, iterate 24 times
                coverage = [0]*64
                # output characters(have added characters in "line" ) 
                print(line)
    exit(0)
#except rs.error as e:
#    # Method calls agaisnt librealsense objects may throw exceptions of type pylibrs.error
#    print("pylibrs.error was thrown when calling %s(%s):\n", % (e.get_failed_function(), e.get_failed_args()))
#    print("    %s\n", e.what())
#    exit(1)
except Exception as e:
    print(e)
    pass
