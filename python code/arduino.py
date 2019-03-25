import serial

class Controller():

    def __init__(self, COMPort, BaudRate = 9600): #Makes the Controller class
        assert type(COMPort) == str  #Confirms that COMPort is the correct type
        assert type(BaudRate) == int  #Asserts that BaudRate is an int

        Controller.arduino = serial.Serial(COMPort, BaudRate)

    class Servo():
        
        upStr = 'u'.encode('utf-8')
        downStr = 'd'.encode('utf-8')
        leftStr = 'l'.encode('utf-8')
        rightStr = 'r'.encode('utf-8')
        stopStr = 's'.encode('utf-8')

        def __init__(self):
            self.arduino = Controller.arduino
        
        def up(self):
            self.arduino.write(self.upStr)

        def down(self):
            self.arduino.write(self.downStr)

        def right(self):
            self.arduino.write(self.rightStr)

        def left(self):
            self.arduino.write(self.leftStr)

        def stop(self):
            self.arduino.write(self.stopStr)