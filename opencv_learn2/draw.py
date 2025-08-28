import cv2
import numpy as np
winName="win"
startPos=(-1,-1)
background=np.full((480,640,3),255,np.uint8)
#展示白色背景 
def cleanWindow():
    global background
    background=np.full((480,640,3),255,np.uint8)
    cv2.imshow(winName,background)
# cv2.line(img,(0,0),(320,240),(0,0,255),5)
# cv2.circle(img,(160,120),100,(0,0,255),3)
# cv2.rectangle(img,(10,10),(100,100),(0,0,255),3)

def leftPressProcess(x,y):
    global startPos
    startPos=(x,y)
    print("leftPressProcess",startPos)

def leftReleaseProcess():
    global startPos
    startPos=(-1,-1)    
    print("leftReleaseProcess",startPos)

def drwaRectangle(x,y):
    cleanWindow()
    print("drwaRectangle",x,y)
    global background
    cv2.rectangle(background,startPos,(x,y),(255,0,0),3)
    cv2.imshow(winName,background)

def mouseCB(event,x,y,flags,param):

    # 左键按下
    if event == cv2.EVENT_LBUTTONDOWN:
        leftPressProcess(x,y)

    # 移动
    elif event == cv2.EVENT_MOUSEMOVE:
        if startPos[0] != -1:
            drwaRectangle(x,y)
    # 左键释放
    elif event == cv2.EVENT_LBUTTONUP:
        leftReleaseProcess()

def main():
    startPos=(-1,-1)
    cleanWindow()
    cv2.setMouseCallback(winName,mouseCB)
    while True:
        key=cv2.waitKey(1)
        if key & 0xFF == ord('q'):
            break

    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()