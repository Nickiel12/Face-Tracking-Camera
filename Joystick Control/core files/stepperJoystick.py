import test_1 as test

controller = test.Controller('COM5')
stepper = controller.Stepper()
joystick = test.Joystick(stepper, 0)

joystick.begin_joystick() 