import cv2 as cv

vid=cv.VideoCapture("mountains.mp4")

while True:
    (success, frame) = vid.read()
    if not success:
        break
    cv.imshow("Mountains Video", frame)
    if (cv.waitKey(30) & 0xFF) == ord('q'):
        break

vid.release()
cv.destroyAllWindows()