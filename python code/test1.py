from queue import Queue

print("hello")
theQueue = Queue()
print(theQueue)
item = theQueue.get(False)
print(item)
print(type(item))