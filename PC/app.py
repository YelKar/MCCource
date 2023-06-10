import socketserver
from threading import Thread

import eel
from loguru import logger

from src.controller import Controller

logger.level("SENT DATA", no=20, color="<cyan><bold>")

ctrl = Controller()


def main_server():
    """Поток сервера
    Сервер будет получать запросы от платформы
    и отправлять JSON из экземпляра класса src.controller.Controller
    :return:
    """

    from src.server import handler

    def handle():
        logger.log("SENT DATA", "{json}", json=(json := f"{Controller.__it__.json()}/"))
        return bytes(json, "ascii")

    HOST, PORT = "0.0.0.0", 9999

    with socketserver.TCPServer((HOST, PORT), handler(handle)) as server:
        server.serve_forever()


logger.info("Start server thread")
start_server = Thread(target=main_server)
start_server.start()

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
