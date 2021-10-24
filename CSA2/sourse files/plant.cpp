//------------------------------------------------------------------------------
// plant.cpp - содержит реализацию класса растения
//------------------------------------------------------------------------------

#include "plant.h"

//------------------------------------------------------------------------------
// Конструктор для создания растения по имени
Plant::Plant(std::string name) {
    Name = name;
}

//------------------------------------------------------------------------------
// Получение частного от деления числа гласных букв в названии на общую длину названия
double Plant::GetPartOfVowels() {
    int i, vow = 0;

    for (i = 0; Name[i]; i++)
    {
        if (Name[i] == 'a' || Name[i] == 'e' || Name[i] == 'i' || Name[i] == 'o' || Name[i] == 'u'
            || Name[i] == 'A' || Name[i] == 'E' || Name[i] == 'I' || Name[i] == 'O' || Name[i] == 'U')
        {
            vow++;
        }
    }
    return ((double)vow) / i;
}
