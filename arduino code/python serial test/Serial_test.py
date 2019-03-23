import serial

arduino = serial.Serial('COM10', 9600, timeout=.1)
while True:
    print('checking')
    data = arduino.readline()[:-2] #for this to work, the arduino must be 'printing' to the serial port
    if data:
        print(data)