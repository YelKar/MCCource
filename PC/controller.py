import json
from dataclasses import dataclass


@dataclass
class Controller:
    left: int = 0
    rightX: int = 0
    rightY: int = 0

    def set(self, lt=left, rx=rightX, ry=rightY):
        assert isinstance(lt, (int, float)), "args must be integer"
        assert isinstance(rx, (int, float)), "args must be integer"
        assert isinstance(ry, (int, float)), "args must be integer"
        self.left, self.rightX, self.rightY = int(lt), int(rx), int(ry)

    def json(self):
        return json.dumps(self.__dict__)
