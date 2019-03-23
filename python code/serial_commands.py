import serial

Com = 'COM10' #change this to your arduino's COM port

arduino = serial.Serial(Com, 9600, timeout=.1) #Open the Serial Port
while True:
    personInput = input('>>>') #Get the user input
    writeBytes = personInput.encode('utf-8') #Encode the user input from string to bytes
    arduino.write(writeBytes) #Writes the bytes to the arduino