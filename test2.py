import imutils
import cv2
from threading import Thread

face_cascade = cv2.CascadeClassifier(r'C:\Python37-84-64\Lib\site-packages\cv2\data\haarcascade_frontalface_default.xml')
face_side_cascade = cv2.CascadeClassifier(r"C:\Python37-84-64\Lib\site-packages\cv2\data\haarcascade_profileface.xml")

totalTime = 0
timeDivid = 0
faceGrab = 0
framecounter = 5

class WebcamVideoStream:
	def __init__(self, src=0):
		# initialize the video camera stream and read the first frame
		# from the stream
		self.stream = cv2.VideoCapture(src)
		(self.grabbed, self.frame) = self.stream.read()
 
		# initialize the variable used to indicate if the thread should
		# be stopped
		self.stopped = False

	def start(self):
		# start the thread to read frames from the video stream
		Thread(target=self.update, args=()).start()
		return self
 
	def update(self):
		# keep looping infinitely until the thread is stopped
		while True:
			# if the thread indicator variable is set, stop the thread
			if self.stopped:
				return
 
			# otherwise, read the next frame from the stream
			(self.grabbed, self.frame) = self.stream.read()
 
	def read(self):
		# return the frame most recently read
		return self.frame
 
	def stop(self):
		# indicate that the thread should be stopped
		self.stopped = True

wVS = WebcamVideoStream(src = "http://localhost:8080/test_mevo.webm")
wVS.start()

while True:
    e1 = cv2.getTickCount()

    frame = wVS.read()

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
        wVS.stop()
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
