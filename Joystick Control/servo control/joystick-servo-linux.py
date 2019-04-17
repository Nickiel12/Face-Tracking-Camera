import arduinoController as ardCon

#if the serial module throws a access denied error, enter the following into the linux terminal to give you user permission
#sudo gpasswd nicholas dialout
#except replace 'nicholas' with your username

controller = ardCon.Controller('/dev/ttyACM0', BaudRate=9600)
servo = controller.Servo()
joystick = ardCon.Joystick(servo, 0)

joystick.begin_joystick() 