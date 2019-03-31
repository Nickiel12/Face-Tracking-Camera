import cv2
import numpy as np
import arduino
import logging

logging.basicConfig(level=logging.DEBUG, format= '%(asctime)s - %(levelname)s - %(message)s') # begins the logging (might not be used)

Low = arduino.LOW # Just a consitency check
High = arduino.HIGH

ComPort = 'COM5' # Change this accordingly to your arduino's COM port

Servo = arduino.Controller(ComPort, BaudRate= 9600).Servo() # Begin an instance of the servo controller

def check_within(imgSize, baseMultiplier, secondMultiplier, currentX, currentY, currentW, currentH): # The code that determines if the face is within the borders
    
    baseYbottom = imgSize[0] * baseMultiplier # These next 2 blocks of code calculates the edges of the faces and the boundries
    baseXRight = imgSize[1] * baseMultiplier
    centerYbottom = imgSize[0] * secondMultiplier
    centerXRight = imgSize[1] * secondMultiplier

    upperMultiplier = 1 - baseMultiplier
    secondUpperMultiplier = 1 - secondMultiplier
    baseYTop = imgSize[0] * upperMultiplier
    baseXLeft = imgSize[1] * upperMultiplier
    centerYTop = imgSize[0] * secondUpperMultiplier
    centerXLeft = imgSize[1] * secondUpperMultiplier

    currentBottomY = currentY + currentH
    currentRightX = currentX + currentW

    print(str(baseYbottom) + "    " + str(currentY))
    logging.debug(f'{baseYTop}    {centerYTop}')  

    if centerYbottom > currentY: # to the top
        if baseYbottom > currentY: 
            Servo.up(High)
            return (150, 150, 150)
        else:
            Servo.up(Low)
            return (255, 255, 255)

    elif centerYTop < currentBottomY:
        if baseYTop < currentBottomY: #to the bottom
            Servo.down(High)
            return (0, 0, 0)
        else:
            Servo.down(Low)
            return (0, 0, 0)

    elif centerXRight > currentX:
        if baseXRight > currentX: #to the right
            Servo.right(High)
            return (150, 0, 0)
        else:
            Servo.right(Low)
            return (255, 0, 0)

    elif centerXLeft < currentRightX:
        if baseXLeft < currentRightX: #to the left
            Servo.left(High)
            return (0, 0, 255)
        else:
            Servo.left(Low)
        return (0, 0, 255)

cap = cv2.VideoCapture(1, cv2.IMREAD_GRAYSCALE) # instead of grayscale you can also use -1, 0, or 1.
faceCascade = cv2.CascadeClassifier(r"C:\Users\nicho\OneDrive\Documents\GitHub\Face-Tracking-Camera\Cascades\haarcascade_frontalface_default.xml") # CHECK THIS FIRST TROUBLE SHOOTING
faceCascadeAlt = cv2.CascadeClassifier(r'C:\Users\nicho\OneDrive\Documents\GitHub\Face-Tracking-Camera\Cascades\haarcascade_profileface.xml')

assert type(cap) != None, 'No Camera'
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
    minNeighbors=4,
    minSize=(50, 50)
    )

    if len(faces) == 0:
        faces = faceCascadeAlt.detectMultiScale(
            gray,
            scaleFactor = 1.1,
            minNeighbors = 4,
            minSize=(50,50)
        )

    print("Found {0} faces!".format(len(faces)))

    # Draw a rectangle around the faces
    for (x, y, w, h) in faces:
        color = check_within([height, width], .1, .25, x, y, w, h)

        cv2.rectangle(frame, (x, y), (x+w, y+h), color)

    cv2.rectangle(frame, (int(width*.1), int(height*.1)), (int(width*.9), int(height*.9)), (150, 0 , 150))
    cv2.rectangle(frame, (int(width*.25), int(height*.25)), (int(width*.75), int(height*.75)), (150, 0 , 150))

    cv2.imshow('frame', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cap.destroyAllWindows()
