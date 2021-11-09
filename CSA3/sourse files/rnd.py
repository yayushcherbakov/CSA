import random

# Класс для генерации случайных значений
class RandomGenerator:
    @staticmethod
    def getRandomAge():
        return random.randint(1, 1000)

    @staticmethod
    def getRandomPlantType():
        return random.randint(1, 3)

    @staticmethod
    def getRandomFlowerType():
        return random.randint(1, 3)

    @staticmethod
    def getRandomMonth():
        return random.randint(1, 12)

    @staticmethod
    def getRandomTreeName():
        return random.choice(
            ["acacia", "birch", "walnut", "oak", "willow", "chestnut", "olive", "palm", "pine", "poplar"])

    @staticmethod
    def getRandomShrubName():
        return random.choice(
            ["elder", "heather", "jasmine", "sea-buckthorn", "nut-grove", "ivy", "blackthorn", "dog-rose",
             "box-tree", "honey-suckle"])

    @staticmethod
    def getRandomFlowerName():
        return random.choice(
            ["pansies", "cornflower", "carnation", "dahlia", "gladiolus", "iris", "bluebell", "lavender",
             "lily", "poppy"])
