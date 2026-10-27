import cv2 as cv
from ultralytics import YOLO

model = YOLO('yolo11n_ncnn_model')
vid = cv.VideoCapture("telegram_pe_dekh")

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
