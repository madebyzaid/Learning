import cv2 as cv
from ultralytics import YOLO

model = YOLO('yolo11n_ncnn_model', task='detect')

vid = cv.VideoCapture(0, cv.CAP_V4L2)
vid.set(cv.CAP_PROP_FOURCC, cv.VideoWriter_fourcc(*'MJPG'))
vid.set(cv.CAP_PROP_FRAME_WIDTH, 640)
vid.set(cv.CAP_PROP_FRAME_HEIGHT, 480)
vid.set(cv.CAP_PROP_BUFFERSIZE, 1)

while True:
    success, frame = vid.read()
    if not success:
        break
    results = model(frame, verbose=False)
    cv.imshow('Video', results[0].plot())
    if (cv.waitKey(1) & 0xFF) == ord("q"):
        break

vid.release()
cv.destroyAllWindows()