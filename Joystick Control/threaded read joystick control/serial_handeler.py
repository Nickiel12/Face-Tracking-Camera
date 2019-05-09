import serial
import time

from queue import Queue
from threading import Thread

import logging 
from logging import debug

logging.basicConfig(level=logging.DEBUG, format= '%(asctime)s - %(levelname)s - %(message)s')

serialQueue = Queue(maxsize=300)

class SerialHandeler():

    threadRun = False

    def __init__(self, ComPort, BaudRate, timeout):
        self.SerialPort = serial.Serial(ComPort, BaudRate, timeout=timeout)
        self.write_thread = Thread(target=self.threaded_write, args=(self,))

    def start(self):
        self.threadRun = True
        self.write_thread.start()

    def stop(self):
        self.threadRun = False

    def write(self, value):
        serialQueue.put(value)

    def threaded_write(self, *args, **kwargs):
        with serialQueue.mutex:
            serialQueue.queue.clear()
            
        while self.threadRun == True:
            currentItem = serialQueue.get()
        
            if currentItem == "Read":
                self.SerialPort.write(b"y")

                port_read = self.SerialPort.read_until(terminator=b"\r\n")
        
                if port_read == b"":
                    del port_read
                    continue
                port_read = port_read[:-2]
                port_read = str(port_read)
                debug(port_read)
            else:
                self.SerialPort.write(currentItem)
                debug(f"Writing {currentItem} to Serial")

