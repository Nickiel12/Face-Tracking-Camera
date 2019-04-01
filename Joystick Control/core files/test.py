import serial
import struct
from commandDict import commandDictLower, commandDictUpper

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


            vertSpeed = int(round((vertAxis*10), 2)) #Convert the axis to speed for arduino
            horSpeed = int(round((horAxis*10), 2))


            self.write_to_arduino(vertSpeed, horSpeed)

        def write_to_arduino(self, vertSpeed, horSpeed):
            #template [verticalSpeed, upOrDown(1 or 0), horizontalSpeed, leftOrRight(1 or 0)]
            outputList = [vertSpeed, horSpeed]
            outputBytes = []
            print(outputList)

            if outputList[0] == 0:
                outputBytes.append(struct.pack('>B', 0))
            else:
                outputBytes.append(commandDictLower[outputList[0]])
            if outputList[1] == 0:
                outputBytes.append(struct.pack('>B', 0))
            else:
                outputBytes.append(commandDictUpper[outputList[1]])
            
            for i in outputBytes:
                self.arduino.write(i)
            self.arduino.write('\n'.encode('utf-8'))
            print(self.arduino.read())
