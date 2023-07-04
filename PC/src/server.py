import socketserver
from typing import Callable


def handler(handle: Callable[..., bytes]):
    return type(
        "Handler",
        (socketserver.BaseRequestHandler,),
        {
            "handle": lambda self: self.request.sendall(handle())
        }
    )


def start(HOST, PORT, handle):

    with socketserver.TCPServer((HOST, PORT), handler(handle)) as server:
        server.serve_forever()


if __name__ == "__main__":
    HOST, PORT = "0.0.0.0", 9999

    with socketserver.TCPServer((HOST, PORT), handler(lambda: b"{a: 0}}")) as server:
        server.serve_forever()
