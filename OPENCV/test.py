import cv2 as cv, time
from ultralytics import YOLO

model = YOLO('yolo11n_ncnn_model')
vid = cv.VideoCapture("rtsp://admin:L2DETVYB@192.168.0.107:554/cam/realmonitor?channel=1&subtype=1")

for i in range(60):
    t0 = time.time()
    ok, frame = vid.read()
    t1 = time.time()
    r = model(frame, imgsz=320, verbose=False)[0]
    print(r.speed)
    t2 = time.time()
    img = r.plot()
    cv.imshow('Video', img)
    cv.waitKey(1)
    t3 = time.time()
    print(f"read {1000*(t1-t0):.0f} ms | yolo {1000*(t2-t1):.0f} ms | show {1000*(t3-t2):.0f} ms")

vid.release()
cv.destroyAllWindows()