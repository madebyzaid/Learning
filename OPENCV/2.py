#no need to import numpy cuz we're not defining any array manually

import cv2 as cv

#resizing an image (approximately maintaining the ratio in this example)

img1=cv.imread("itachi.png")

print(img1.shape) #(h, w, c) = (1728, 1152, 3)

#we wanna scale down width and height both by a factor of 100

img2 = cv.resize(img1, (int(1152/100), int(1728/100)), interpolation = cv.INTER_AREA)

#format: img2 = cv.resize(img1, (w, h), interpolation)
#interpolation is INTER_LINEAR by default

#keep in mind that img.shape returns (h, w, c) but cv.resize takes (w, h) and not (h, w)

cv.imshow("Itachi", img1)
cv.imshow("Compressed Itachi", img2)

cv.waitKey(0)
cv.destroyAllWindows()