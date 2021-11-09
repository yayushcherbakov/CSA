from plant import *
from monthEnum import *


# ----------------------------------------------
class Shrub(Plant):
    flowering_month = Month.JANUARY

    def __init__(self, name, flowering_month_int):
        super().__init__(name)
        self.flowering_month = Month(flowering_month_int)

    # Возвращает строковое представление растения
    def toString(self):
        return "It is Shrub: name = {}, flowering month = {}. Part of Vowels = {}".format(self.name,
                                                                                          self.flowering_month.name,
                                                                                          self.getPartOfVowels())
