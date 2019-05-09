import cv2
import numpy as np
from matplotlib import pyplot as plt

cap = cv2.VideoCapture(0 ,cv2.IMREAD_GRAYSCALE) # instead of grayscale you can also use -1, 0, or 1.
faceCascade = cv2.CascadeClassifier(r"C:\Users\nicho\OneDrive\Documents\GitHub\Face-Tracking-Camera\Cascades\haarcascade_profileface.xml")

#Color is 1, grayscale is 0, and the unchanged is -1
while(True):
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
 
    # Detect faces in the image
    faces = faceCascade.detectMultiScale(
    gray,
    scaleFactor=1.1,
    minNeighbors=5,
    minSize=(30, 30)
    )

    print("Found {0} faces!".format(len(faces)))

    # Draw a rectangle around the faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)

    cv2.imshow('frame', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cap.destroyAllWindows()


