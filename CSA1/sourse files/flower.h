#ifndef __flower__
#define __flower__

//------------------------------------------------------------------------------
// flower.h - содержит описание цветка
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"
#include "stringHelper.h"

//------------------------------------------------------------------------------
// Цветок
struct flower {
    enum type { HOME = 1, WILD = 2, GARDEN = 3};
    type flowerType;
    string name;
};

// Ввод параметров цветка из файла
void In(flower &f, ifstream &ifst);

// Случайный ввод параметров цветка
void InRnd(flower &е);

// Вывод параметров цветка в форматируемый поток
void Out(flower &f, ofstream &ofst);

// Получение частного от деления числа гласных букв в названии на общую длину названия
double GetPartOfVowels(flower &f);

#endif //__flower__
