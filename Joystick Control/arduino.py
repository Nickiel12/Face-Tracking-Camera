import serial

LOW = "LOW"
HIGH = 'HIGH'

class Controller():

    def __init__(self, COMPort, BaudRate = 9600): #Makes the Controller class
        assert type(COMPort) == str  #Confirms that COMPort is the correct type
        assert type(BaudRate) == int  #Asserts that BaudRate is an int

        Controller.arduino = serial.Serial(COMPort, BaudRate)

    class Servo():
        
        upStr = bytes('u', 'utf8')
        downStr = bytes('d', 'utf-8')
        leftStr = bytes('l', 'utf-8')
        rightStr = bytes('r', 'utf-8')

        L1Tilt = bytes('1', 'utf-8')
        L2Tilt = bytes('3', 'utf-8')
        L3Tilt = bytes('5', 'utf-8')
        L4Tilt = bytes('7', 'utf-8')

        L1Turn = bytes('2', 'utf-8')
        L2Turn = bytes('4', 'utf-8')
        L3Turn = bytes('6', 'utf-8')
        L4Turn = bytes('8', 'utf-8')
        

        def __init__(self):
            self.arduino = Controller.arduino
        
        def up(self, level):
            assert type(level) == str, 'Not a string'
            if level == '1':
                self.arduino.write(self.L1Tilt)
                self.arduino.write(self.upStr)
            elif level == '2':
                self.arduino.write(self.L2Tilt)
                self.arduino.write(self.upStr)
            elif level == '3':
                self.arduino.write(self.L3Tilt)
                self.arduino.write(self.upStr)
            elif level == '4':
                self.arduino.write(self.L4Tilt)
                self.arduino.write(self.upStr)
            else:
                assert True == False, 'Unknown Level'

        def down(self, level):
            assert type(level) == str, 'Not a string'
            if level == '1':
                self.arduino.write(self.L1Tilt)
                self.arduino.write(self.downStr)
            elif level == '2':
                self.arduino.write(self.L2Tilt)
                self.arduino.write(self.downStr)
            elif level == '3':
                self.arduino.write(self.L3Tilt)
                self.arduino.write(self.downStr)
            elif level == '4':
                self.arduino.write(self.L4Tilt)
                self.arduino.write(self.downStr)
            else:
                assert True == False, 'Unknown Level'

        def right(self, level):
            assert type(level) == str, 'Not a string'
            if level == '1':
                self.arduino.write(self.L1Turn)
                self.arduino.write(self.rightStr)
            elif level == '2':
                self.arduino.write(self.L2Turn)
                self.arduino.write(self.rightStr)
            elif level == '3':
                self.arduino.write(self.L3Turn)
                self.arduino.write(self.rightStr)
            elif level == '4':
                self.arduino.write(self.L4Turn)
                self.arduino.write(self.rightStr)
            else:
                assert True == False, 'Unknown Level'

        def left(self, level):
            assert type(level) == str, 'Not a string'
            if level == '1':
                self.arduino.write(self.L1Turn)
                self.arduino.write(self.leftStr)
            elif level == '2':
                self.arduino.write(self.L2Turn)
                self.arduino.write(self.leftStr)
            elif level == '3':
                self.arduino.write(self.L3Turn)
                self.arduino.write(self.leftStr)
            elif level == '4':
                self.arduino.write(self.L4Turn)
                self.arduino.write(self.leftStr)
            else:
                assert True == False, 'Unknown Level'