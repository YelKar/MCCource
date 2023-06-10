import json
from dataclasses import dataclass

from src.singleton import Singleton


@dataclass
class Controller(Singleton):
    """
    Класс является синглтоном:
    его экземпляр единственный на всю программу.
    В этот класс записываются данные с Frontend'а
    """
    leftX: int = 0
    leftY: int = 0
    rightX: int = 0
    rightY: int = 0

    def json(self) -> str:
        return json.dumps(self.__dict__)