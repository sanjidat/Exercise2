# Python 3.3.3 and 2.7.6
# python fo.py
import threading
from threading import Thread
lock=threading.Lock()

# Potentially useful thing:
#   In Python you "import" a global variable, instead of "export"ing it when you declare it
#   (This is probably an effort to make you feel bad about typing the word "global")
i = 0

def incrementingFunction():
    global i
    with lock:
    # TODO: increment i 1_000_000 times
        for j in range(1000000):
            j -= 1

def decrementingFunction():
    global i
    with lock:
    # TODO: decrement i 1_000_000 times
        for j in range(1000000):
            j -= 1


def main():
    global i

    incrementing = Thread(target = incrementingFunction, args = (),)
    decrementing = Thread(target = decrementingFunction, args = (),)

    # TODO: Start both threads
    incrementing.start()
    decrementing.start()

    incrementing.join()
    decrementing.join()

    print("The magic number is %d" % (i))


main()
