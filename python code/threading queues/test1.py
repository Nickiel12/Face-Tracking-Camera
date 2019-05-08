import threading
from queue import Queue

#should push write, write, read order to queue where it is handed to another thread which when executes the FIFO queue in order
#might need to implement a queue for the print funcition (start with this to test the idea) to handle the print(outgoing) and print(incoming)

#what am I trying to read from the arduino again?????
# ahh yes, the stepper motor positions so I can see how they work