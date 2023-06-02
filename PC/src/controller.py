import json
from dataclasses import dataclass

from singleton import Singleton


@dataclass
class Controller(Singleton):
    leftX: int = 0
    leftY: int = 0
    rightX: int = 0
    rightY: int = 0

    def json(self):
        return json.dumps(self.__dict__)