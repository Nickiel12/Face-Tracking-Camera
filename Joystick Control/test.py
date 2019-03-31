import serial

LOW = "LOW"
HIGH = 'HIGH'

class Controller():

    def __init__(self, COMPort, BaudRate = 9600): #Makes the Controller class
        assert type(COMPort) == str  #Confirms that COMPort is the correct type
        assert type(BaudRate) == int  #Asserts that BaudRate is an int

        Controller.arduino = serial.Serial(COMPort, BaudRate, timeout=.1)

    class Servo():

        def __init__(self):
            self.arduino = Controller.arduino

        def up(self, rate):
            rate = str(rate*100)
            upStr = bytes('u', 'utf-8')
            rate = bytes(rate, 'utf-8')
            self.arduino.write(upStr)
            self.arduino.write(rate)
            print(self.arduino.read())