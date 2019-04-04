import test
import threading

controller = test.Controller('COM5')
stepper = controller.Stepper()
joystick = controller.Joystick(stepper)

threading._start_new_thread(joystick.begin_joystick)