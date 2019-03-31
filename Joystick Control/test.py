import serial

LOW = "LOW"
HIGH = 'HIGH'

class Controller():

    def __init__(self, COMPort, BaudRate = 9600): #Makes the Controller class
        assert type(COMPort) == str  #Confirms that COMPort is the correct type
        assert type(BaudRate) == int  #Asserts that BaudRate is an int

        Controller.arduino = serial.Serial(COMPort, BaudRate)

    class Servo():

        def __init__(self):
            self.arduino = Controller.arduino

        def up(self, rate):
            rate = bytes(rate, 'utf-8')
            self.arduino.write(rate)