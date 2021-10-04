#ifndef __shrub__
#define __shrub__

//------------------------------------------------------------------------------
// shrub.h - содержит описание кустарника
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"
#include "stringHelper.h"

// кустарник
struct shrub {
	enum month {
		JANUARY = 1,
		FEBRUARY = 2,
		MARCH = 3,
		APRIL = 4,
		MAY = 5,
		JUNE = 6,
		JULY = 7,
		AUGUST = 8,
		SEPTEMBER = 9,
		OCTOBER = 10,
		NOVEMBER = 11,
		DECEMBER = 12
	};
	month floweringMonth;
	string name;

};

// Ввод параметров кустарника из файла
void In(shrub& s, ifstream& ifst);

// Случайный ввод параметров кустарника
void InRnd(shrub& s);

// Вывод параметров кустарника в форматируемый поток
void Out(shrub& s, ofstream& ofst);

// Получение частного от деления числа гласных букв в названии на общую длину названия
double GetPartOfVowels(shrub& s);
#endif //__shrub__
