import imutils
import cv2

cap = cv2.VideoCapture(0, cv2.IMREAD_GRAYSCALE)

face_cascade = cv2.CascadeClassifier(r'C:\Python37-84-64\Lib\site-packages\cv2\data\haarcascade_frontalface_default.xml')
face_side_cascade = cv2.CascadeClassifier(r"C:\Python37-84-64\Lib\site-packages\cv2\data\haarcascade_profileface.xml")

totalTime = 0
timeDivid = 0
faceGrab = 0
framecounter = 5


while True:
    e1 = cv2.getTickCount()
    ret, frame = cap.read()

    #if framecounter % 5 == 0:
    if ret:
        # Capture frame-by-frame
        #use this to resize the image
        frame = imutils.resize(frame, width=450)
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 1.5, 5)
        if len(faces) != 0:
            for (x,y,w,h) in faces:
                cv2.rectangle(frame,(x,y),(x+w,y+h),(255,0,0),2)

        if len(faces) == 0:
            sideFace = face_side_cascade.detectMultiScale(gray, 1.5, 5)
            for (x,y,w,h) in sideFace:
                cv2.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),2)

    cv2.imshow('frame',frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    
    if len(faces) != 0:
        faceGrab += 1
    elif len(sideFace) !=0:
        faceGrab += 1
    e2 = cv2.getTickCount()
    time = (e2 - e1)/ cv2.getTickFrequency()
    print(time)
    totalTime += time
    timeDivid += 1 

print('number of faces grabbed out of total is ' + str(faceGrab) + ' of ' + str(timeDivid))
avgTime = totalTime/timeDivid
print('total ticks = ' + str(timeDivid))
print('tick avg = ' + str(avgTime))

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()