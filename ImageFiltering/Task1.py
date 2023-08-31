import cv2
import numpy as np
from numpy import uint8

i = cv2.imread('im-1.tif')
cv2.imshow('Img',i)

# convertion to 2D
i = i[:, :, 0]


def myConvolution(k, im, b):
    kernal = np.full((k, k), 1 / (k * k))

    # transpose of kernal
    kernal = kernal.T

    # padding must be k-1 as height and width in pixels
    pad_width = (k - 1) / 2
    pad_height = (k - 1) / 2

    z = b()

    if z < 0 or z > 2:
        z = 0

    # Using cv2.copyMakeBorder() method
    # image, top, bottom, left, right
    # for zero padding
    if z == 0:
        image = cv2.copyMakeBorder(im, int(pad_height), int(pad_height), int(pad_width), int(pad_width), cv2.BORDER_CONSTANT, value=0)
    elif z == 1:
        image = cv2.copyMakeBorder(im, int(pad_height), int(pad_height), int(pad_width), int(pad_width), cv2.BORDER_REFLECT)
    elif z == 2:
        image = cv2.copyMakeBorder(im, int(pad_height), int(pad_height), int(pad_width), int(pad_width), cv2.BORDER_REPLICATE)

    # the shape of the object holds a tuple (rows, columns, channels).
    height, width = im.shape[:2]

    # resultant matrix will be size of image_row - (kernal_row - 1)
    output_mat = np.full((height, width), 0)
    v = 0
    for x in range(height - (k - 1)):
        h = 0
        for m in range(width - (k - 1)):
            r_count = 0
            sum_of_pixels = 0
            for n in range(k):
                c_count = 0
                for o in range(k):
                    sum_of_pixels = sum_of_pixels + kernal[n][o] * im[x + r_count][m + c_count]
                    c_count = c_count + 1
                r_count = r_count + 1
            if sum_of_pixels>255:
                output_mat[v][h] = 255
            else:
                output_mat[v][h] = sum_of_pixels
            h = h + 1
        v = v + 1
    output_mat = output_mat.astype(uint8)

    # Displaying the image
    cv2.imshow("Output", output_mat)
    cv2.waitKey(0)
    return output_mat


def take_input():
    print("What kind of padding do you want?")
    print("\nEnter:\n")
    print("0 for zero padding")
    print("1 for Reflection padding")
    print("2 for Replication padding")
    option = int(input())
    return option
s = myConvolution(7, i, take_input)