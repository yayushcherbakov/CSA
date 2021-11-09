from plant import *
from flowerTypeEnum import *


# ----------------------------------------------
class Flower(Plant):
    flower_type = FlowerType.HOME

    def __init__(self, name, flower_type_int):
        super().__init__(name)
        self.flower_type == FlowerType(flower_type_int);

    def toString(self):
        return "It is Flower: name = {}, Flower type month = {}. Part of Vowels = {}".format(self.name,
                                                                                             self.flower_type.name,
                                                                                             self.getPartOfVowels())
