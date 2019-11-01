#!/usr/bin/env python3 
import os
import random
import sys
from PIL import Image

imagePath = "babbage.jpg" 

if len(sys.argv) > 1:
   imagePath = sys.argv[1]

if not os.path.isfile(imagePath):
    print("Error: Can't find {0}".format(imagePath))
    sys.exit(1)

try:
    im = Image.open(imagePath)
    imAnd = im.copy()
    imOr = im.copy()
    imXor = im.copy()
    imAndPix = imAnd.load()
    imOrPix = imOr.load()
    imXorPix = imXor.load()
    for x in range(im.size[0]):
        for y in range(im.size[1]):
            a = im.getpixel((x,y))    
            b = random.randint(0, 255)
            imAndPix[x,y] = a & b
            imOrPix[x,y] = a | b
            imXorPix[x,y] = a ^ b 
    imAnd.save("AND-{0}".format(imagePath))
    imOr.save("OR-{0}".format(imagePath))
    imXor.save("XOR-{0}".format(imagePath))
except IOError as ex:
    print(ex)
    sys.exit(1)

