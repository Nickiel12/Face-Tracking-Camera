import arduinoController as ardCon

controller = ardCon.Controller('COM5', BaudRate=9600)
servo = controller.Servo()
joystick = ardCon.Joystick(servo, 0)

joystick.begin_joystick() 