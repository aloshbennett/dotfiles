#!/usr/bin/python

import subprocess
import sys

brightness_str=subprocess.getoutput("xrandr --verbose | grep -i bright | sed 's/.*: //'");
brightness = float(brightness_str)
if (sys.argv[1] == 'UP') :
    brightness = brightness + 0.1
elif (sys.argv[1] == 'DOWN') :
    brightness = brightness - 0.1
if (brightness > 1) :
    brightness = 1
elif (brightness < 0) :
    brightness = 0;
op=subprocess.getoutput("xrandr --output eDP-1 --brightness " + str(brightness));
# print(op)

