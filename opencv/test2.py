import cv2 as cv

cv.namedWindow("Mountains Video", cv.WINDOW_NORMAL)
cv.setWindowProperty("Mountains Video", cv.WND_PROP_FULLSCREEN, cv.WINDOW_FULLSCREEN)

vid = cv.VideoCapture("mountains.mp4")

fps = vid.get(cv.CAP_PROP_FPS)
total = int(vid.get(cv.CAP_PROP_FRAME_COUNT))
delay = int(1000 / fps) if fps > 0 else 30
print("fps:", fps, "| total frames:", total)

count = 0
while True:
    success, frame = vid.read()
    if not success:
        break
    count += 1
    cv.imshow("Mountains Video", frame)
    if (cv.waitKey(delay) & 0xFF) == ord('q'):
        break

print("stopped at frame", count, "of", total)
vid.release()
cv.destroyAllWindows()
