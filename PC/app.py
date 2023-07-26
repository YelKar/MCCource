import time
from threading import Thread

import eel
from loguru import logger

from src.controller import Controller

logger.level("SENT DATA", no=20, color="<cyan><bold>")

ctrl = Controller()


def client():
    import socket

    UDP_IP = "192.168.1.20"
    UDP_PORT = 9999

    sock = socket.socket(socket.AF_INET,  # Internet
                         socket.SOCK_DGRAM)  # UDP
    while True:
        sock.sendto(MESSAGE := Controller.__it__.json().encode(), (UDP_IP, UDP_PORT))
        logger.log("SENT DATA", MESSAGE.decode())
        time.sleep(.25)


logger.info("Start server thread")
start_server = Thread(target=client)
start_server.start()

# @dataclass
# class Keys:
#     forward: str = 'w'
#     backward: str = 's'
#     right: str = 'a'
#     left: str = 'f'
#     r_right: str = 'e'
#     r_left: str = 'q'
#
#
# @keyboard.on_press
# def kb_ctrl(key: keyboard.KeyboardEvent):
#     match key.name:
#         case Keys.forward:
#             Controller.__it__.leftY = Controller.__it__.rightY = 255
#             keyboard.wait(key.name, True, True)
#             Controller.__it__.leftY = Controller.__it__.rightY = 0
#         case Keys.backward:
#             Controller.__it__.leftY = Controller.__it__.rightY = -255
#             keyboard.wait(key.name, True, True)
#             Controller.__it__.leftY = Controller.__it__.rightY = 0


logger.info("Initializing application")
eel.init(".")


@eel.expose
def log(*args, **kwargs):
    print(*args, **kwargs)


@eel.expose
def send_data(*data):
    """
    Эта функция будет выполняться из Frontend'а,
    с помощью JavaScript,
    и будет получать данные и записывать из в экземпляр-синглтон src.controller.Controller
    :param data:
    :return:
    """
    Controller(*data)


logger.info(f"Set browser - {(browser := 'edge')}")
logger.info("Launching application")
eel.start("main.html", port="5000", mode=browser)
