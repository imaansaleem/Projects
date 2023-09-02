import cv2
import numpy as np
from numpy import uint8

img = cv2.imread('im_q2.tif')

cv2.imshow('Input', img)
# cv2.waitKey(0)

# conversion to 2D
img = img[:, :, 0]


def laplacian_90():
    G = np.full((3, 3), 0)
    G[0][0] = 0
    G[0][1] = 1
    G[0][2] = 0
    G[1][0] = 1
    G[1][1] = -4
    G[1][2] = 1
    G[2][0] = 0
    G[2][1] = 1
    G[2][2] = 0
    return G


def laplacian_45():
    G = np.full((3, 3), 0)
    for f in range(3):
        G[0][f] = 1
    G[1][0] = 1
    G[1][1] = -8
    G[1][2] = 1
    for g in range(3):
        G[2][g] = 1
    return G


def normalization(size, mat):
    for f in range(size):
        for g in range(size):
            mat[f][g] = mat[f][g] / (size * size)
    return mat


def myConvolution(k, im, kernel):
    # padding must be k-1 as height and width in pixels
    pad_width = (k - 1) / 2
    pad_height = (k - 1) / 2

    # for zero padding
    image = cv2.copyMakeBorder(im, int(pad_height), int(pad_height), int(pad_width), int(pad_width),
                               cv2.BORDER_CONSTANT, value=0)

    # the shape of the object holds a tuple (rows, columns, channels).
    height, width = im.shape[:2]

    # resultant matrix will be size of image_row - (kernel_row - 1)
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
                    sum_of_pixels = sum_of_pixels + kernel[n][o] * im[x + r_count][m + c_count]
                    c_count = c_count + 1
                r_count = r_count + 1
            if sum_of_pixels > 255:
                output_mat[v][h] = 255
            output_mat[v][h] = sum_of_pixels
            h = h + 1
        v = v + 1
    return output_mat


def scaling(matrix):
    minimum = matrix.min()
    maximum = matrix.max()


def show_img(output_mat):
    output_mat = output_mat.astype(uint8)

    # Displaying the image
    cv2.imshow("Output", output_mat)
    cv2.waitKey(0)
    return 1


# L = laplacian_90()
# print(L)

L = laplacian_45()
print(L)
