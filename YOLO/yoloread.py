import cv2 as cv
from ultralytics import YOLO

model = YOLO('yolo11n_ncnn_model')
vid = cv.VideoCapture("rtsp://admin:L2DETVYB@192.168.0.107:554/cam/realmonitor?channel=1&subtype=1")

while True:
    success, frame = vid.read()
    if not success:
        break
    results = model(frame, imgsz=320, verbose=False)
    cv.imshow('Video', results[0].plot())
    if (cv.waitKey(1) & 0xFF) == ord("q"):
        break

vid.release()
cv.destroyAllWindows()