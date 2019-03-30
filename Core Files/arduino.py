import serial

LOW = "LOW"
HIGH = 'HIGH'

class Controller():

    def __init__(self, COMPort, BaudRate = 9600): #Makes the Controller class
        assert type(COMPort) == str  #Confirms that COMPort is the correct type
        assert type(BaudRate) == int  #Asserts that BaudRate is an int

        Controller.arduino = serial.Serial(COMPort, BaudRate)

    class Servo():
        
        upSlowStr = 'u'.encode('utf-8')
        upFastStr = '1'.encode('utf-8')

        downSlowStr = 'd'.encode('utf-8')
        downFastStr = '2'.encode('utf-8')

        leftSlowStr = 'l'.encode('utf-8')
        leftFastStr = '3'.encode('utf-8')

        rightSlowStr = 'r'.encode('utf-8')
        rightFastStr = '4'.encode('utf-8')
        

        def __init__(self):
            self.arduino = Controller.arduino
        
        def up(self, level):
            assert type(level) == str, 'Not a string'
            if level == 'LOW':
                self.arduino.write(self.upSlowStr)
            elif level == "HIGH":
                self.arduino.write(self.upFastStr)

        def down(self, level):
            assert type(level) == str, 'Not a string'
            if level == 'LOW':
                self.arduino.write(self.downSlowStr)
            elif level == "HIGH":
                self.arduino.write(self.downFastStr)

        def right(self, level):
            assert type(level) == str, 'Not a string'
            if level == 'LOW':
                self.arduino.write(self.rightSlowStr)
            elif level == "HIGH":
                self.arduino.write(self.rightFastStr)

        def left(self, level):
            assert type(level) == str, 'Not a string'
            if level == 'LOW':
                self.arduino.write(self.leftSlowStr)
            elif level == "HIGH":
                self.arduino.write(self.leftFastStr)