from typing import Self


class Singleton(object):
    """
    Метакласс-Синглтон для класса src.controller.Controller
    """
    id: int = 0
    __it__: Self

    def __new__(cls, *args, **kwargs):
        cls.id += 1
        it = cls.__dict__.get("__it__")
        if it is not None:
            return it
        cls.__it__ = it = object.__new__(cls)
        it.init(*args, **kwargs)
        return it

    def init(self, *args, **kwargs):
        pass
