import numpy as np
import matplotlib.pyplot as plt
import cv2


def apply_guassian(img, sigma):
    # Smoothing image with kernal size 3 by 3 with sigma
    k = (3, 3)
    gaussian_filter = cv2.getGaussianKernel(k[0], sigma)
    gaussian_filter = gaussian_filter * gaussian_filter.T
    image = cv2.filter2D(img, -1, gaussian_filter)
    return image


def mark_corners(img, cornerness):
    # Get the coordinates of the corners
    corner_indices = np.argwhere(cornerness > 0)

    # Draw a circle on each corner
    for corner in corner_indices:
        x, y = corner[1], corner[0]
        cv2.circle(img, (x, y), 5, (0, 255, 0), -1)

    return img


def corner_detection(option):
    img = cv2.imread('img.jpeg', cv2.IMREAD_GRAYSCALE)
    plt.imshow(img)
    plt.title("Image 1")
    plt.show()

    image = apply_guassian(img, 1)

    # Derivative in x-direction
    sobel_x = cv2.Sobel(image, cv2.CV_64F, 1, 0, ksize=3)

    # Derivative in y-direction
    sobel_y = cv2.Sobel(image, cv2.CV_64F, 0, 1, ksize=3)

    rows = img.shape[0]
    cols = img.shape[1]
    R = np.zeros((rows, cols), dtype=img.dtype)

    # calculating Ix square and smoothing with larger guassian
    squared_matrix_x = sobel_x * sobel_x
    squared_matrix_x = apply_guassian(squared_matrix_x, 3)

    # calculating Iy square and smoothing with larger guassian
    squared_matrix_y = sobel_y * sobel_y
    squared_matrix_x = apply_guassian(squared_matrix_y, 3)

    # calculating IyIy
    IxIy = sobel_x * sobel_y

    A = np.zeros((2, 2), np.float32)

    for i in range(rows):
        for j in range(cols):
            A[0][0] = squared_matrix_x[i][j]
            A[0][1] = IxIy[i][j]
            A[1][0] = IxIy[i][j]
            A[1][1] = squared_matrix_y[i][j]

            # eignen values is a matrix 1 by 2
            eigenvalues = np.linalg.eigvals(A)
            if option == 1:
                # lambda1 * lambda2 - aplpha*square((lambda1+lambda2))
                R[i][j] = (eigenvalues[0] * eigenvalues[1]) - (
                        0.06 * ((eigenvalues[0] + eigenvalues[1]) * (eigenvalues[0] + eigenvalues[1])))

            elif option == 2:
                # lambda1
                R[i][j] = eigenvalues[0]

            elif option == 3:
                # (lambda1 * lambda2) / (lambda1 + lambda2)
                R[i][j] = (eigenvalues[0] * eigenvalues[1]) / (eigenvalues[0] + eigenvalues[1])

            elif option == 4:
                # lambda1*lambda2
                R[i][j] = eigenvalues[0] * eigenvalues[1]

            elif option == 5:
                # lambda1 - (0.06)*lambda2
                R[i][j] = eigenvalues[0] - (0.06) * eigenvalues[1]

    percentile = np.percentile(R, 98)
    for i in range(rows):
        for j in range(cols):
            if R[i][j] < percentile:
                R[i][j] = 0

    cornerness = cv2.cornerHarris(np.float32(img), 2, 3, 0.04)
    marked_img = mark_corners(img, cornerness)
    plt.imshow(marked_img)
    plt.title("Output")
    plt.show()


print("Select a cornerness metrix: ")
a = int(input("\n1 for Harris\n2 for Shi & Tomasi\n3 for Szeliski\n4 for Rohr\n5 for triggs\n"))
corner_detection(a)
