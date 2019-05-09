import arduinoController as ardCon

controller = ardCon.Controller('/COM5')
stepper = controller.Stepper()
joystick = ardCon.Joystick(stepper, 0)

joystick.begin_joystick()