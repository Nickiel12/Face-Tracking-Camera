import serial

LOW = "LOW"
HIGH = 'HIGH'

class Controller():

    def __init__(self, COMPort, BaudRate = 9600): #Makes the Controller class
        assert type(COMPort) == str  #Confirms that COMPort is the correct type
        assert type(BaudRate) == int  #Asserts that BaudRate is an int

        Controller.arduino = serial.Serial(COMPort, BaudRate)

    class Servo():

        L1TiltUp = bytes('a', 'utf-8')
        L2TiltUp = bytes('b', 'utf-8')
        L3TiltUp = bytes('c', 'utf-8')
        L4TiltUp = bytes('d', 'utf-8')

        L1TiltDwn = bytes('e', 'utf-8')
        L2TiltDwn = bytes('f', 'utf-8')
        L3TiltDwn = bytes('g', 'utf-8')
        L4TiltDwn = bytes('h', 'utf-8')

        L1TurnRht = bytes('1', 'utf-8')
        L2TurnRht = bytes('2', 'utf-8')
        L3TurnRht = bytes('3', 'utf-8')
        L4TurnRht = bytes('4', 'utf-8')

        L1TurnLft = bytes('5', 'utf-8')
        L2TurnLft = bytes('6', 'utf-8')
        L3TurnLft = bytes('7', 'utf-8')
        L4TurnLft = bytes('8', 'utf-8')
        

        def __init__(self):
            self.arduino = Controller.arduino
        
        def up(self, level):
            assert type(level) == str, 'Not a string'
            if level == '1':
                self.arduino.write(self.L1TiltUp)
            elif level == '2':
                self.arduino.write(self.L2TiltUp)
            elif level == '3':
                self.arduino.write(self.L3TiltUp)
            elif level == '4':
                self.arduino.write(self.L4TiltUp)
            else:
                assert True == False, 'Unknown Level'

        def down(self, level):
            assert type(level) == str, 'Not a string'
            if level == '1':
                self.arduino.write(self.L1TiltDwn)
            elif level == '2':
                self.arduino.write(self.L2TiltDwn)
            elif level == '3':
                self.arduino.write(self.L3TiltDwn)
            elif level == '4':
                self.arduino.write(self.L4TiltDwn)
            else:
                assert True == False, 'Unknown Level'

        def right(self, level):
            assert type(level) == str, 'Not a string'
            if level == '1':
                self.arduino.write(self.L1TurnRht)
            elif level == '2':
                self.arduino.write(self.L2TurnRht)
            elif level == '3':
                self.arduino.write(self.L3TurnRht)
            elif level == '4':
                self.arduino.write(self.L4TurnRht)
            else:
                assert True == False, 'Unknown Level'

        def left(self, level):
            assert type(level) == str, 'Not a string'
            if level == '1':
                self.arduino.write(self.L1TurnLft)
            elif level == '2':
                self.arduino.write(self.L2TurnLft)
            elif level == '3':
                self.arduino.write(self.L3TurnLft)
            elif level == '4':
                self.arduino.write(self.L4TurnLft)
            else:
                assert True == False, 'Unknown Level'