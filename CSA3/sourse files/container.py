from plantTypeEnum import *
from plant import *
from tree import *
from shrub import *
from flower import *
from rnd import *


# ----------------------------------------------
class Container:
    def __init__(self):
        self.store = []

    # Записать текущее состояние контейнера в поток
    def print(self):
        print("Container contains {} elements".format(len(self.store)))
        pass

    # Записать текущее состояние контейнера в поток
    def write(self, ostream):
        ostream.write("Container is store {} plants:\n".format(len(self.store)))
        i = 1
        for plant in self.store:
            ostream.write("{}: {}\n".format(i, plant.toString()))
            i+=1
        pass

    # Заполнить контейнер растениями из файла
    def readFromFile(self, file):
        for line in file:
            self.appnedPlantFromString(line)
        pass

    # Создать растение из строки и добавить в контейнер
    def appnedPlantFromString(self, str):
        strArray = str.split(" ")
        key = int(strArray[0])
        if PlantType(key) == PlantType.TREE.value:
            plant = Tree(strArray[1], int(strArray[2]))
            self.store.append(plant)
        elif PlantType(key) == PlantType.SHRUB.value:
            plant = Shrub(strArray[1], int(strArray[2]))
            self.store.append(plant)
        else:
            plant = Flower(strArray[1], int(strArray[2]))
            self.store.append(plant)
        pass

    # Заполнить контейнер определенным количеством случайных растений
    def setRandomPlants(self, num):
        for x in range(num):
            self.appnedRandomPlant()
        pass

    # Добавление случайного растерия в контейнер
    def appnedRandomPlant(self):
        key = RandomGenerator.getRandomPlantType()
        if PlantType(key) == PlantType.TREE.value:
            plant = Tree(RandomGenerator.getRandomTreeName(), RandomGenerator.getRandomAge())
            self.store.append(plant)
        elif PlantType(key) == PlantType.SHRUB.value:
            plant = Shrub(RandomGenerator.getRandomShrubName(), RandomGenerator.getRandomMonth())
            self.store.append(plant)
        else:
            plant = Flower(RandomGenerator.getRandomFlowerName(), RandomGenerator.getRandomFlowerType())
            self.store.append(plant)
        pass

    def partition(self, elements, low, high):
        # Выбираем средний элемент в качестве опорного
        # Также возможен выбор первого, последнего
        # или произвольного элементов в качестве опорного
        pivot = elements[(low + high) // 2]
        i = low - 1
        j = high + 1
        while True:
            i += 1
            while elements[i].getPartOfVowels() < pivot.getPartOfVowels():
                i += 1

            j -= 1
            while elements[j].getPartOfVowels() > pivot.getPartOfVowels():
                j -= 1

            if i >= j:
                return j

            # Если элемент с индексом i (слева от опорного) больше, чем
            # элемент с индексом j (справа от опорного), меняем их местами
            elements[i], elements[j] = elements[j], elements[i]
        pass

    def quick_sort(self):
        # Создадим вспомогательную функцию, которая вызывается рекурсивно
        def _quick_sort(items, low, high):
            if low < high:
                split_index = self.partition(items, low, high)
                _quick_sort(items, low, split_index)
                _quick_sort(items, split_index + 1, high)

        _quick_sort(self.store, 0, len(self.store) - 1)
        pass
