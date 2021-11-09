# ----------------------------------------------
class Plant:
    def __init__(self, name):
        self.name = name

    # Возвращает строковое представление растения
    def toString(self):
        pass

    # Посчитать количество гласных в названии
    def getPartOfVowels(self):
        lowercase = self.name.lower()
        vowel_counts = {}
        for vowel in "aeiou":
            count = lowercase.count(vowel)
            vowel_counts[vowel] = count
        return sum(vowel_counts.values()) / len(self.name)
