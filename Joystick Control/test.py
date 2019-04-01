import serial
import struct

LOW = "LOW"
HIGH = 'HIGH'

class Controller():

    def __init__(self, COMPort, BaudRate = 19200): #Makes the Controller class
        assert type(COMPort) == str  #Confirms that COMPort is the correct type
        assert type(BaudRate) == int  #Asserts that BaudRate is an int

        Controller.arduino = serial.Serial(COMPort, BaudRate, timeout=.1)

    class Stepper():

        def __init__(self):
            self.arduino = Controller.arduino

        def get_positivity(self, number):
            if number > 0: 
                output = 1 
            elif number <= 0:
                output = 0
            else:
                assert True == False, 'Something isn\'t right'
            return output

        def update_axes(self, axes, vertAxisIndex, horAxisIndex):
            assert type(axes) == list, 'not list'
            assert type(horAxisIndex) == int, 'Not int'
            assert type(vertAxisIndex) == int, 'Not Int'

            vertAxis = axes[vertAxisIndex] #get vertical axis curently
            horAxis = axes[horAxisIndex] # get horizontal axis currently 
            
            vertDir = self.get_positivity(vertAxis) #Test to see if vert axis is positive or negative. return 1 if positive, return 0 if negative

            horDir = self.get_positivity(horAxis) 

            vertSpeed = int(round(vertAxis, 3)*15) #Convert the axis to speed for arduino
            horSpeed = int(round(horAxis, 3)*15)


            self.write_to_arduino(vertSpeed, vertDir, horSpeed, horDir)

        def write_to_arduino(self, vertSpeed, vertDir, horSpeed, horDir):
            #template [verticalSpeed, upOrDown(1 or 0), horizontalSpeed, leftOrRight(1 or 0)]
            outputList = [vertSpeed, vertDir, horSpeed, horDir]
            outputBytes = bytearray()
            print(outputList)

            if outputList == [0,0,0,0]:
                return

            for i in outputList:
                print(type(i))
                outputBytes.append(struct.pack('>b', i))

            print(outputList)
            print(outputBytes)
            for i in outputBytes:
                self.arduino.write(i)
            self.arduino.write('\n'.encode('utf-8'))
            print(self.arduino.read())


    class Servo():

        def __init__(self):
            self.arduino = Controller.arduino


        def up(self, rate):
            print(rate)
            rate = int(round(rate, 3)*15)
            print(rate)
            if rate == 10:
                rate = 9
            rateSend = struct.pack('>BB', rate)
            print(rateSend)
            self.arduino.write(rateSend)
            print(self.arduino.read())