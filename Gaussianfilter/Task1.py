import cv2
import numpy as np
from numpy import uint8
import math

img = cv2.imread('im_q1.tif')

cv2.imshow('Input', img)
# cv2.waitKey(0)

# conversion to 2D
img = img[:, :, 0]


def integer_Approximation(matrix, size):
    minimum = np.min(g)
    to_multiply = 1
    while minimum < 1:
        minimum = minimum * 10
        to_multiply = to_multiply * 10
    for a in range(size):
        for b in range(size):
            matrix[a][b] = matrix[a][b] * to_multiply
    m = np.rint(matrix)
    return m


def my2DGaussian(w, σ):
    r = w // 2
    # denominator
    s = 2 * σ * σ

    # matrix of size rows and size columns
    GKernel = np.full((w, w), 0.0)
    x = -1 * r
    for a in range(w):
        y = -1 * r
        for b in range(w):
            power = x * x + y * y
            y = y + 1
            GKernel[a][b] = math.exp(-1 * (power / s)) / (math.pi * s)
        x = x + 1

    return GKernel


def sum_of_kernel(size, kernel):
    addition = 0
    for c in range(size):
        for d in range(size):
            addition = addition + kernel[c][d]
    return addition


def myConvolution(k, im, kernel):
    # padding must be k-1 as height and width in pixels
    pad_width = (k - 1) / 2
    pad_height = (k - 1) / 2

    # for zero padding
    image = cv2.copyMakeBorder(im, int(pad_height), int(pad_height), int(pad_width), int(pad_width),
                               cv2.BORDER_CONSTANT, value=0)

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
                    sum_of_pixels = sum_of_pixels + kernel[n][o] * im[x + r_count][m + c_count]
                    c_count = c_count + 1
                r_count = r_count + 1
            if sum_of_pixels > 255:
                output_mat[v][h] = 255
            output_mat[v][h] = sum_of_pixels
            h = h + 1
        v = v + 1
    kernel_sum = sum_of_kernel(k, kernel)
    output_mat = output_mat / kernel_sum
    return output_mat


def show_img(output_mat):
    output_mat = output_mat.astype(uint8)

    # Displaying the image
    cv2.imshow("Output", output_mat)
    cv2.waitKey(0)
    return 1


g = my2DGaussian(3, 1)
G_matrix = integer_Approximation(g, 3)
print(G_matrix)
#s = myConvolution(3, img, G_matrix)
#show_img(s)
