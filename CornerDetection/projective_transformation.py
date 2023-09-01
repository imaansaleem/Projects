import numpy as np
import matplotlib.pyplot as plt
import cv2


def applying_transformation(image, h_matrix):
    rows = image.shape[0]
    cols = image.shape[1]
    output_mat = np.zeros((rows, cols, 3), dtype=image.dtype)
    for i in range(rows):  # no of rows
        for j in range(cols):  # no of columns
            array = np.array([i, j, 1], dtype=np.float32)
            matrix = np.dot(h_matrix, array)

            # if index is out of range
            if int(matrix[0]) >= 0 and int(matrix[0]) < cols and int(matrix[1]) >= 0 and int(matrix[1]) < rows:
                output_mat[int(matrix[0])][int(matrix[1])] = image[i][j]
    plt.imshow(output_mat)
    plt.title("Output")
    plt.show()


def backward_transformation(image, h_matrix):
    rows = image.shape[0]
    cols = image.shape[1]
    output_mat = np.zeros((rows, cols, 3), dtype=image.dtype)
    h_matrix = np.linalg.inv(h_matrix)
    for i in range(rows):  # no of rows
        for j in range(cols):  # no of columns
            array = np.array([i, j, 1], dtype=np.float32)
            matrix = np.dot(h_matrix, array)

            # if index is out of range
            if int(matrix[0]) >= 0 and int(matrix[0]) < cols and int(matrix[1]) >= 0 and int(matrix[1]) < rows:
                output_mat[i][j] = image[int(matrix[0])][int(matrix[1])]
    plt.imshow(output_mat)
    plt.title("Output")
    plt.show()


def findHomography(s, d):

    # Convert points to a matrix
    s = np.asarray(s, dtype=np.float32)
    d = np.asarray(d, dtype=np.float32)

    # Create an empty homography matrix
    H = np.zeros((3, 3), np.float32)

    # Transformation Matrix
    A = np.zeros((8, 9), np.float32)

    j = 0
    # Compute the homography matrix
    for i in range(s.shape[0]):
        x, y = s[i][0], s[i][1]
        u, v = d[i][0], d[i][1]
        A[j][0] = x
        A[j][1] = y
        A[j][2] = 1
        A[j][3] = 0
        A[j][4] = 0
        A[j][5] = 0
        A[j][6] = -u * x
        A[j][7] = -u * y
        A[j][8] = -u
        A[j + 1][0] = 0
        A[j + 1][1] = 0
        A[j + 1][2] = 0
        A[j + 1][3] = x
        A[j + 1][4] = y
        A[j + 1][5] = 1
        A[j + 1][6] = -v * x
        A[j + 1][7] = -v * y
        A[j + 1][8] = -v
        j += 2

    # Normalize the homography matrix
    A /= s.shape[0]

    # Compute the SVD of the homography matrix
    S, V, D = np.linalg.svd(A)

    # converting 9*1 matrix to 3 by 3 matrix
    H = D[-1].reshape((3, 3))

    # dividing with scaling factor last element of array
    H /= H[2, 2]

    return H


def projective_transform(img1, img2):
    # Display images

    plt.imshow(img1)
    plt.title("Image 1")
    plt.show()
    plt.imshow(img2)
    plt.title("Image 2")
    plt.show()

    # points from the first image
    points1 = np.array([[477.1, 246.6], [443.0, 384.2], [241.6, 279.0], [118.8, 388.9]])

    # points from the second image
    points2 = np.array([[422.7, 249.4], [390.3, 387.3], [189.9, 276.2], [65.3, 378.8]])

    # Compute the projective transformation matrix
    H = findHomography(points1, points2)

    # Return the projective transformation matrix
    return H


# Load the images into the workspace
img1 = cv2.imread("Image-1.png")
img2 = cv2.imread("Image-2.png")

# Compute the projective transformation matrix
H = projective_transform(img1, img2)

# Print the projective transformation matrix
print("Projective Transformation Matrix: \n")
applying_transformation(img1, H)
backward_transformation(img1, H)