#一帧一帧读取car.avi
import cv2

print(cv2.getBuildInformation())  # 查找 "Video I/O" 部分

cap = cv2.VideoCapture('./car.mp4')
bg_subtractor = cv2.createBackgroundSubtractorKNN()
count = 0
while cap.isOpened():
    ret, frame = cap.read()
    if ret:
        #对帧进行滤波处理
        frame = cv2.GaussianBlur(frame, (5, 5), 0)
        fg_mask = bg_subtractor.apply(frame)
        cv2.imshow('frame', fg_mask)
        count += 1
        if cv2.waitKey(0) & 0xFF == ord('q'):
            break
    else:
        break
cap.release()
cv2.destroyAllWindows()