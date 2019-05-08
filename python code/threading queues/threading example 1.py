#should push write, write, read order to queue where it is handed to another thread which when executes the FIFO queue in order
#might need to implement a queue for the print funcition (start with this to test the idea) to handle the print(outgoing) and print(incoming)

#what am I trying to read from the arduino again?????
# ahh yes, the stepper motor positions so I can see how they work

#https://docs.python.org/3/library/queue.html

import logging 
from logging import debug
logging.basicConfig(level=logging.DEBUG, format= '%(asctime)s - %(levelname)s - %(message)s')

import time

import threading
from queue import Queue

outgoingQueue = Queue()

timeBetween = 2

def logQueue(debugBool=False):
    debug(debugBool)
    while True:
        item = outgoingQueue.get()
        if item == "stop":
            break
        if item != None:
            debug(item)
    debug("stopped log queue")

logThread = threading.Thread(target=logQueue, args=(True,))
logThread.start()

def addToQueue(queueNumber):
    mycurrentTime = time.time()
    mynextAddTime = time.time() + timeBetween

    loopNum = 0
    while True:
        mycurrentTime = time.time()
        if mycurrentTime > mynextAddTime:
            if loopNum == 10:
                break
            else:
                mycurrentTime = time.time()
                mynextAddTime = time.time() + timeBetween
                loopNum += 1
                outgoingQueue.put(f"{queueNumber}threaded loop number {loopNum}")
    debug("stopped addToQueue")

outgoingQueue.put("first input")

addThread = threading.Thread(target=addToQueue, args=("first",))
secondAddThread = threading.Thread(target=addToQueue, args=("second",))

currentTime = time.time()
nextAddTime = time.time() + timeBetween

loopNum = 0

secondAddThread.start()
addThread.start()

while True:
    currentTime = time.time()
    if currentTime > nextAddTime:
        if loopNum == 10:
            outgoingQueue.put("stop")
            break
        else:
            currentTime = time.time()
            nextAddTime = time.time() + timeBetween
            loopNum += 1
            outgoingQueue.put(f"loop number {loopNum}")
