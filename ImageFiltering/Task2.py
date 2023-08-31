import cv2
import numpy as np
from numpy import uint8

image = cv2.imread('im-2.tif')
cv2.imshow('Img', image)
image = image[:, :, 0]

def myPWL(img, r1=-1, s1=0, r2=-1, s2=255):
    height, width = img.shape[:2]
    if r1 < 0 or r2 < 0:
        r1 = image.min()
        r2 = image.max()
    slope = 0
    v = 0
    s = 0
    output_mat = np.full((height, width), 0)
    for x in range(height):
        h = 0
        for y in range(width):
            r = img[x][y]
            if r >= 0 and r <= r1:
                slope = s2 / r2
                s = slope * r
            elif r > r1 and r <= r2:
                slope = (s2 - s1) / (r2 - r1)
                s = slope * (r - r1) + s1
            elif r > r2 and r <= 255:
                slope = (255 - s2) / (255 - r2)
                s = slope * (r - r2) + s2
            output_mat[v][h] = s
            h = h + 1
        v = v + 1
    output_mat = output_mat.astype(uint8)
    cv2.imshow("Output", output_mat)
    cv2.waitKey(0)
    return 1
m=myPWL(image)
