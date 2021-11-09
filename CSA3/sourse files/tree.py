from plant import *


# ----------------------------------------------
class Tree(Plant):
    age = 0

    def __init__(self, name, age):
        super().__init__(name)
        self.age = age

    # Возвращает строковое представление растения
    def toString(self):
        return "It is Tree: name = {}, age = {}. Part of Vowels = {}".format(self.name, self.age,
                                                                             self.getPartOfVowels())
