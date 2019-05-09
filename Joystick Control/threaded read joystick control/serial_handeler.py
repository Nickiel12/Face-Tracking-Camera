import serial
import time

import queue
from queue import Queue
from threading import Thread

import re

import logging 
from logging import debug

logging.basicConfig(level=logging.DEBUG, format= '%(asctime)s - %(levelname)s - %(message)s')

class SerialHandeler():

    regex = ["!","\r\n"]

    serialQueue = Queue(maxsize=300)

    threadRun = False

    vertical = 0
    horizontal = 0
    read = 0

    def __init__(self, ComPort, BaudRate, timeout):
        self.SerialPort = serial.Serial(ComPort, BaudRate, timeout=timeout)
        self.write_thread = Thread(target=self.threaded_write, args=(self,))

    def start(self):
        self.threadRun = True
        self.write_thread.start()

    def stop(self):
        self.threadRun = False

    def write(self, value):
        self.vertical = value["Vert"]
        self.horizontal = value["Hor"]
        self.read = value["read"]

#TODO fix the latency
    def threaded_write(self, *args, **kwargs):

        while True:
            
            if self.threadRun == False:
                return
        
            self.SerialPort.write(self.vertical)
            self.SerialPort.write(self.horizontal)

            if self.read == "read":
                self.SerialPort.write(b"y")

                port_read = self.SerialPort.read_until(terminator=b"!!!")
                port_read = port_read.decode("utf-8")

                port_read.replace("!","").splitlines()

                for i in port_read:
                    if i == " " or i == "\n" or i == "\r" or i == "!":
                        continue
                    debug(i)

