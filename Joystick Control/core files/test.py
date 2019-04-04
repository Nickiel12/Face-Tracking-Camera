import serial
import struct
import pygame
import logging
from commandDict import commandDictLower, commandDictUpper # import the arduino commands

logging.basicConfig(level=logging.DEBUG, format= '%(asctime)s - %(levelname)s - %(message)s')

class Joystick():
    """
    A class that uses a joystick to control an arduino
    'StepperInstance', takes an instance of Controller().Stepper()
    """
    def __init__(self, StepperInstance, JoystickIndex):
        self.Stepper = StepperInstance
        pygame.init()
        self.PygameJoystick = pygame.joystick.Joystick(JoystickIndex)
        self.PygameJoystick.init()

    def get_axes(self, horizontal_axis, vertical_axis, zoom_axis):
        logging.debug(self.PygameJoystick.get_axis(vertical_axis))
        
        horiAxis = self.PygameJoystick.get_axis(horizontal_axis)
        vertAxis = self.PygameJoystick.get_axis(vertical_axis)
        zoomAxis = self.PygameJoystick.get_axis(zoom_axis)
        return (horiAxis, vertAxis, zoom_axis)

    def begin_joystick(self, loop = True, horizontal_axis = 0, vertical_axis = 1, zoom_axis = 3):

        currentHorizontalAxis, currentVerticalAxis, currentZoomAxis = self.get_axes(horizontal_axis, vertical_axis, zoom_axis)

        logging.debug(currentHorizontalAxis)
        
        self.Stepper.write_axes(currentVerticalAxis, currentHorizontalAxis)

        if self.PygameJoystick.get_button(0) == 1:
            loop = False
        if loop == True:
            self.begin_joystick(loop, horizontal_axis, vertical_axis, zoom_axis)

class Controller():
    """
    Create an instance of Controller to access the Stepper and Servo classes
    'COMPort', the serial port that the arduino is connected to 
    'BaudRate', default set to 19200, change if you use a different baudrate 
    """
    def __init__(self, COMPort, BaudRate = 19200): #Makes the Controller class
        assert type(COMPort) == str  #Confirms that COMPort is the correct type
        assert type(BaudRate) == int  #Asserts that BaudRate is an int

        Controller.arduino = serial.Serial(COMPort, BaudRate, timeout=.1) #Open the serial port, and set it to a variable
                                                #that is able to be accessed by the other classes

    class Stepper(): 
        """
        A class that contains functions to control stepper motors
        """
                    
        def __init__(self):
            self.arduino = Controller.arduino

        def write_axes(self, vertAxis, horAxis):
            assert type(horAxis) == float, 'Not int'
            assert type(vertAxis) == float, 'Not Int'

            vertSpeed = int(round((vertAxis*10), 2)) #Convert the axis to speed for arduino
            horSpeed = int(round((horAxis*10), 2))

            self.write_to_arduino(vertSpeed, horSpeed)

        def write_to_arduino(self, vertSpeed, horSpeed):
            outputBytes = []
            logging.debug(vertSpeed)
            logging.debug('')
            logging.debug(horSpeed)

            if vertSpeed == 0:
                outputBytes.append(struct.pack('>B', 0))
            else:
                outputBytes.append(commandDictLower[vertSpeed])
            if horSpeed == 0:
                outputBytes.append(struct.pack('>B', 0))
            else:
                outputBytes.append(commandDictUpper[horSpeed])
            
            for i in outputBytes:
                self.arduino.write(i)
            print(self.arduino.read())
