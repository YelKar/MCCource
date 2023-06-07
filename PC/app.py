import socketserver
from threading import Thread, Event

import eel
from loguru import logger

from src.controller import Controller

ctrl = Controller()

stop = Event()

logger.level("SENT DATA", no=20, color="<cyan><bold>")

#
# def print_ctrl():
#     last = ctrl.json()
#     while not stop.is_set():
#         if last != ctrl.json():
#             print(ctrl)
#             last = ctrl.json()
#             # eel.log(ctrl.__repr__())
#         time.sleep(0.01)
#
#
# t = Thread(target=print_ctrl)
# t.start()


def main_server():
    from src.server import handler

    def handle():
        logger.log("SENT DATA", "{json}", json=(json := f"{Controller.__it__.json()}/"))
        return bytes(json, "ascii")

    HOST, PORT = "0.0.0.0", 9999

    with socketserver.TCPServer((HOST, PORT), handler(handle)) as server:
        server.serve_forever()


start_server = Thread(target=main_server)
start_server.start()

eel.init(".")

eel._expose("log", print)

@eel.expose
def send_data(*data):
    Controller(*data)

try:
    eel.start("main.html", port="5000")
finally:
    stop.set()
