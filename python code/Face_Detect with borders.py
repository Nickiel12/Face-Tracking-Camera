import cv2
import numpy as np
import pathlib

def check_within(imgSize, baseMultiplier, currentX, currentY, currentW, currentH):
    
    baseYbottom = imgSize[0] * baseMultiplier
    baseXRight = imgSize[1] * baseMultiplier
    upperMultiplier = 1 - baseMultiplier
    baseYTop = imgSize[0] * upperMultiplier
    baseXLeft = imgSize[1] * upperMultiplier
    currentBottomY = currentY + currentH
    currentRightX = currentX + currentW

    print(str(baseYbottom) + "    " + str(currentY))

    if baseYbottom > currentY: # to the top
        return (255, 255, 255)
    elif baseYTop < currentBottomY: #to the bottom
        return (0, 0, 0)
    elif baseXRight > currentX: #to the right
        return (255, 0, 0)
    elif baseXLeft < currentRightX: #to the left
        return (0, 0, 255)
    else:
        return(0, 255, 0)

cap = cv2.VideoCapture(0, cv2.IMREAD_GRAYSCALE) # instead of grayscale you can also use -1, 0, or 1.
faceCascade = cv2.CascadeClassifier(r"C:\Users\nicho\OneDrive\Documents\GitHub\Face-Tracking-Camera\python code\Cascades\haarcascade_frontalface_default.xml") # CHECK THIS FIRST TROUBLE SHOOTING

tmp, frm = cap.read()
height, width, channels = frm.shape
print(f"{height*.25}, {width}")
del tmp, frm

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
        color = check_within([height, width], .1, x, y, w, h)
        cv2.rectangle(frame, (int(width*.1), int(height*.1)), (int(width*.9), int(height*.9)), (150, 0 , 150))
        cv2.rectangle(frame, (x, y), (x+w, y+h), color)
    cv2.imshow('frame', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cap.destroyAllWindows()



