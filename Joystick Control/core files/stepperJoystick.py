import test
import threading

controller = test.Controller('COM5')
stepper = controller.Stepper()
joystick = test.Joystick(stepper, 0)

loop = True

while loop == True:
    joystick.get_axis(0, 1, 3)