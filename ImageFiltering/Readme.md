# Image Filtering

## Task 1
Implement the sliding-sum-of-products for a grayscale image. Name the function myConvolution(k,im,‘b’) ; where ‘k’ , ‘im’ , and ‘b’ are the kernel, image, and the boundary augmentation handling code, respectively. 
### Note: 
You should implement this function from scratch, providing user with an option to input the following boundary handling techniques: 
1. Zero padding
2. Reflection
3. Replication.
If the user does not provide the boundary code, it should default to zero padding

## Task 2
Use your code above to filter the provided image, img - 1, using square kernels of the following sizes: 3,5, and 7. Compare your results

## Task3
Implement a piecewise linear transformation function myPWL(.) to enhance contrast of a given 8 - bit grayscal e image (im - 2) . Let the user input the coordinates (r1,s1) and (r2,s2) so they can experiment with various possibilities. If the user doesn’t provide the coordinates, let them default to (rmin,0) and (rmax,255).
