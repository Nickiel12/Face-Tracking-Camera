import serial
import time

from queue import Queue
from threading import Thread

if (__name__  == "__main__"):
    import logging 
    from logging import debug

    logging.basicConfig(level=logging.DEBUG, format= '%(asctime)s - %(levelname)s - %(message)s')

class SerialHandeler():

    threadRun = False

    serialQueue = Queue(maxsize=300)

    def __init__(self, ComPort, BaudRate, timeout):
        self.SerialPort = serial.Serial(ComPort, BaudRate, timeout=timeout)
        self.write_thread = Thread(target=self.threaded_write, args=(self,))

    def start(self):
        self.threadRun = True
        self.write_thread.start()

    def stop(self):
        self.threadRun = False

    def write(self, value):
        self.serialQueue.put(value)

    def threaded_write(self, *args, **kwargs):
        while self.threadRun == True:
            currentItem = self.serialQueue.get()
                debug(currentItem)

def scheduled_queue_additions(delay, serialInstance):
    nextEvent = time.time() + delay
    loopNum = 0
    serialInstance.start()
    while loopNum < 100:
        if nextEvent < time.time():
            serialInstance.write(str(loopNum) + " times looped")
            nextEvent = time.time() + delay
            loopNum += 1
    serialInstance.stop()

if (__name__ == "__main__"):
    Serial = SerialHandeler("/dev/ttyACM0", 9600, timeout=.1)
    scheduled_queue_additions(.5, Serial)
