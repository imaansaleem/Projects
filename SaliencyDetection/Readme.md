# Saliency Detection Using Textural Contrast
Luminous contrast is a measure of how much one area of an image stands out from another due to differences in their brightness levels. The basic idea is that areas of an image that have high luminous contrast are more likely to be salient, or attention-grabbing, to viewers.
Luminous contrast can be defined mathematically as the absolute difference in luminance between two regions of an image, divided by the maximum possible luminance difference in that image. This gives a value between 0 and 1, where higher values indicate greater contrast.

## Functions description 
### 1. def find_mean(img):
This function, find_mean(img), takes an input image img and returns the mean by adding all the values and then dividing by the number of pixels in the image.

### 2. def luminance_contrast(img, n):
This code is implementing a function called luminance_contrast, which takes an input image img and a parameter n. The function returns a matrix S of the same size as the input image, which represents the luminance contrast at each pixel.
The function works by first computing the mean luminance of the input image using the find_mean function. This mean luminance value is denoted as I_bar.
Then, the function computes the luminance contrast at each pixel using a sliding window approach. For each 5x5 window in the input image, the function computes the average luminance within the window, and takes the absolute difference between the average and the overall mean luminance I_bar. This difference is raised to the power of n and stored in the corresponding location in the output matrix S.
By raising the luminance difference to the power of n, the function is able to emphasize areas of the image with higher contrast. the exact value of n can be adjusted to control the sensitivity of the function to different levels of contrast.

### 3. def normalize(img):
This code is defining a function named normalize which takes an input image as a parameter and returns a normalized version of that image.
The normalization process includes creating a new numpy array of zeros with the same dimensions as the input image. Then, it computes the minimum and maximum values of the input image using np.min and np.max functions.
After that, it uses the np.interp function to map the input image values from the minimum and maximum range to the new range between 0 and 255. This function performs a linear interpolation to rescale the input values to the desired range. 
Finally, the normalized image is returned by the function. The main purpose of this code is to normalize an image's pixel values to a new range of 0-255.

### 4. def tensor_index(I1, I2):
This code defines a function named tensor_index that takes two input images I1 and I2 as parameters and returns a 2D numpy array containing the tensor index values computed from these images.
The tensor_index function first computes the number of rows and columns of the input images using the shape method of numpy arrays. It then creates a new numpy array of zeros with the same dimensions as the input images.
Next, the function iterates over all possible 5x5 pixel neighborhoods in the input images using nested for loops. For each pixel neighborhood, it computes the tensor index by multiplying corresponding pixel values of I1 and I2 element-wise and then summing up these products. The computed tensor index is then stored in the output array.
After processing all pixel neighborhoods, the function returns the resulting tensor index array.


### 5. def structure_tensor(img):
This code defines a function named structure_tensor that takes an input image img as a parameter and computes the structure tensor of the image. The function returns three 2D numpy arrays containing the elements of the structure tensor.
The structure_tensor function first applies Gaussian blur to the input image using the cv2.GaussianBlur function with a kernel size of 3x3 and sigma value of 3. This step helps to reduce noise in the image.
Then, the function computes the first-order partial derivatives of the image in x and y directions using the Sobel operator implemented by the cv2.Sobel function. The ksize argument sets the size of the Sobel kernel to 3x3.
Next, the function calls the tensor_index function (which was explained earlier) three times to compute the elements of the structure tensor. The resulting tensor index arrays are then returned by the structure_tensor function.

### 6. def Epsilon_calculation(Ix, Iy, IxIy):
This code defines a function named Epsilon_calculation that takes three input images Ix, Iy, and IxIy as parameters and computes the squared difference of the eigenvalues of the structure tensor at each pixel location. The function returns a 2D numpy array containing the resulting values.
The Epsilon_calculation function first creates a 2x2 numpy array A to hold the structure tensor elements for each pixel location. It also computes the number of rows and columns of the input images using the shape method of numpy arrays and creates a new numpy array Epsilon of zeros with the same dimensions as the input images.
Next, the function iterates over all pixel locations using nested for loops. For each pixel location, it sets the elements of the structure tensor A based on the corresponding values in the Ix, Iy, and IxIy input images. It then computes the eigenvalues and eigenvectors of A using the np.linalg.eig function.
Finally, the function computes the squared difference between the eigenvalues of A and stores the resulting value in the Epsilon array for the current pixel location.
After processing all pixel locations, the function returns the resulting Epsilon array.
This value, called the saliency measure, is used to identify regions of interest in an image.

### 7. def orientation_contrast(E1):
This code defines a function named orientation_contrast that takes a single input image E as a parameter and computes the orientation contrast measure for each pixel location in the image. The function returns a 2D numpy array containing the resulting values.
The orientation_contrast function first computes the number of rows and columns of the input image using the shape method of numpy arrays and creates a new numpy array S of zeros with the same dimensions as the input image.
Next, the function iterates over all pixel locations using nested for loops. For each pixel location, it computes the orientation contrast measure as the sum of the absolute differences between the saliency measure at the current pixel location and the saliency measure at all neighboring pixel locations within a 7x7 window centered at the current pixel location.
The saliency measure is obtained from the input image E, which is assumed to contain the squared difference of the eigenvalues of the structure tensor at each pixel location, as computed by the Epsilon_calculation function.
Finally, the function stores the resulting orientation contrast measure in the S array for the current pixel location.
After processing all pixel locations, the function returns the resulting S array. This measure can be used to identify edges and corners in an image, which are regions of high orientation contrast.

### 8. def combination(SL, SD):
This code defines a function combination that takes in two parameters SL and SD. The function performs the following operations:
It retrieves the dimensions of SL and creates a new 2D array of zeros S with the same dimensions as SL.
It normalizes SL and SD by calling a normalize function
It then iterates over each pixel in SL and SD arrays and multiplies the corresponding pixel values together to create a new array S.
Finally, the function returns S. This function performs a pixel-wise multiplication of two images represented by SL and SD, respectively. The resulting image S represents the combination of the two input images.
