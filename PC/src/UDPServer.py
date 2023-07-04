import socket
from typing import Callable


def start(HOST: str, PORT: int, handle: Callable):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind((HOST, PORT))
    while True:
        _, address = server_socket.recvfrom(1024)
        server_socket.sendto(handle(), address)
