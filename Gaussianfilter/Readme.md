# Gaussian filter

### Task 1 
a) **Generate a 2D Symmetric Gaussian Blurring Filter**

Write a function `my2DGaussian(w, σ)` to generate a 2D symmetric Gaussian blurring filter of a given size 'w' and standard deviation 'σ'. The coefficients of the mask you return must be integers with the whole Gaussian shape captured within the size 'w'.

b) **Generate Filters with Specific Sizes**

Generate the filters with the following sizes (assuming unit standard deviation in all cases): 9 × 9, 17 × 17, and 31 × 31.

c) **Convolve and Display**

Convolve the image `im_q1` with all the masks in (b) and display the original image and all the blurred images in juxtaposition.

### Task 2
You can blur an image using a filter ‘B’ and find the gradient using the filter ‘G’, where ‘B’ and ‘G’ are given as 
follows:<br><br>

Filter B:

\[
\frac{1}{9}
\begin{bmatrix}
1 & 1 & 1 \\
1 & 1 & 1 \\
1 & 1 & 1
\end{bmatrix}
\]

Filter B:<br>
1/9 [1 1 1]<br>
[1 1 1]<br>
[1 1 1]<br><br>
Filter 𝐺<br>
[−1 0 1]<br>
[−1 0 1]<br>
[−1 0 1]<br>
    
a) **Linearity of Operations**

Are the above operations linear? If so, why?

b) **Image Blurring and Gradient**

You are asked to apply 'B' to the image `im_q2` to generate a blurred image and then apply 'G' to the result to find the gradient. How would the output change if you apply 'G' first and then 'B'?

c) **Single Filter 'S'**

If you are asked to apply one single filter 'S', instead of two filters in succession, how would you find 'S'?

### Task 3
a) **Laplacian and Scaling**

Using the provided image `im_q3`, do the following:

- Compute the Laplacian of the image with 3 × 3 and 90 degree as well as 45 degree fully isotropic filters and display the results with proper scaling.

b) **Image Sharpening**

Sharpen the original image by using the outputs of (a) above.

c) **Display and Comment**

Display the original as well as the sharpened images from (b) and comment on your results.
