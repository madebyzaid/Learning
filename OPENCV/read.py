import cv2 as cv
img=cv.imread("farlands.webp")
print(img.dtype)
print(img.shape)
print(img[100,200])
print(type(img))

cv.imshow("farlands photo", img)
cv.waitKey(0)