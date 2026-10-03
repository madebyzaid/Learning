import numpy as np
import cv2 as cv

#images are used as numpy arrays

img = np.array([
    [[0, 0, 0], [85, 85, 85], [170, 170, 170], [255, 255, 255]],
    [[0, 0, 255], [0, 0, 190], [0, 0, 125], [0, 0, 60]],
    [[0, 255, 0], [0, 190, 0], [0, 125, 0], [0, 60, 0]],
    [[255, 0, 0], [190, 0, 0], [125, 0, 0], [60, 0, 0]],
    [[255, 255, 255], [190, 190, 190], [125, 125, 125], [60, 60, 60]],
], dtype=np.uint8)

#every pixel is given as [B, G, R] where B, G, and R are color intensities

#nth list contains pixels of nth row

#color intensity is uint8 so can take values from 0 to 255

print(img.shape) #img.shape of form (h, w, c) so this prints (5, 4, 3)

#c: channel: number of integers giving info about each pixel

#observe the displayed image and colors in every row

cv.imshow("Test Image With Less Pixels", img)
cv.waitKey(0)
cv.destroyAllWindows()