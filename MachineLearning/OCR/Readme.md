## Optical Character Recognition using Naive Bayes
This project demonstrates the implementation of Optical Character Recognition (OCR) using the Naive Bayes classifier. The goal of this project is to recognize characters from binary images, where each pixel is represented by either a 0 (absence of pixel) or a 1 (presence of pixel).

## Overview
The Optical Character Recognition (OCR) process involves recognizing characters or text from images. In this project, we use the Naive Bayes classifier to classify binary images of characters. Each character is represented by a 16x16 binary array, where the presence of a pixel is denoted by 1 and the absence by 0.

## Results
Naive Bayes is a reliable tool for this OCR because it can work efficiently and handle various features. One of its advantages is that it can filter out unnecessary details and focus on what really matters. In this OCR, Naive Bayes had enough examples to learn from. Moreover, in this OCR, the dimensions of images are very low, that's why there isn't much of the noise. That's why Naive Bayes worked best in this OCR.
However, Naive Bayes has some limitations. It assumes that each feature is independent, which means it may not understand complex relationships between different aspects of characters. This can be a challenge when certain details, like the shape or arrangement of pixels, are crucial for accurate OCR. Naive Bayes might give wrong results in this scenario.
