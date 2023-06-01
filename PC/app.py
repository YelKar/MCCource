import time
from copy import copy
from threading import Thread, Event

import eel

from controller import Controller

ctrl = Controller()

stop = Event()


def print_ctrl():
    last = copy(ctrl)
    while not stop.is_set():
        if last != ctrl:
            print(ctrl, stop.is_set())
            last = copy(ctrl)
            # eel.log(ctrl.__repr__())
        time.sleep(0.1)


t = Thread(target=print_ctrl)
t.start()

eel.init(".")

eel.expose(ctrl.set)


@eel.expose()
def left(val: int):
    assert isinstance(val, (int, float))
    print("left", val)
    ctrl.set(val)


@eel.expose
def right_x(val: int):
    assert isinstance(val, (int, float))
    ctrl.rightX = val


@eel.expose
def right_y(val: int):
    assert isinstance(val, (int, float))
    ctrl.rightY = val


try:
    eel.start("main.html")
finally:
    stop.set()
