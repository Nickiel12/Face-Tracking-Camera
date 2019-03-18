import cv2
import numpy as np

def check_within(imgSize, baseMultiplier, currentX, currentY, currentW, currentH):
    
    baseYbottom = imgSize[0] * baseMultiplier
    baseXRight = imgSize[1] * baseMultiplier
    upperMultiplier = 1 - baseMultiplier
    baseYTop = imgSize[0] * upperMultiplier
    baseXLeft = imgSize[1] * upperMultiplier
    currentBottomY = currentY + currentH
    currentRightX = currentX + currentW

    print(str(baseYbottom) + "    " + str(currentY))

    if baseYbottom > currentY:
        return (255, 255, 255)
    elif baseYTop < currentBottomY:
        return (0, 0, 0)
    elif baseXRight > currentX:
        return (255, 0, 0)
    elif baseXLeft < currentRightX:
        return (0, 0, 255)
    else:
        return(0, 255, 0)

cap = cv2.VideoCapture(0, cv2.IMREAD_GRAYSCALE) # instead of grayscale you can also use -1, 0, or 1.
faceCascade = cv2.CascadeClassifier(r"C:\Users\Owner\Desktop\Face Detection\haar_frontface.xml") # CHECK THIS FIRST TROUBLE SHOOTING

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


# you can save the image with 
# cv2.imwrite('watchgray.png',img)

'''
instead of the above code you can replace everything below 
img = cv2....
with

plt.imshow(img, cmap = 'gray', interpolation = 'bicubic')
plt.xticks([]), plt.yticks([])  # to hide tick values on X and Y axis
plt.plot([200,300,400],[100,200,300],'c', linewidth=5)
plt.show()

for a matplotlib chart
'''
