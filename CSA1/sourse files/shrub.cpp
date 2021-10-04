//------------------------------------------------------------------------------
// shrub.cpp - содержит процедуру ввода параметров 
// для уже созданного кустарника
//------------------------------------------------------------------------------

#include "shrub.h"

//------------------------------------------------------------------------------
// Преобразование int к month
shrub::month IntToMonth(int value) {
    switch (value) {
    case 1:
        return shrub::month::JANUARY;
    case 2:
        return shrub::month::FEBRUARY;
    case 3:
        return shrub::month::MARCH;
    case 4:
        return shrub::month::APRIL;
    case 5:
        return shrub::month::MAY;
    case 6:
        return shrub::month::JUNE;
    case 7:
        return shrub::month::JULY;
    case 8:
        return shrub::month::AUGUST;
    case 9:
        return shrub::month::SEPTEMBER;
    case 10:
        return shrub::month::OCTOBER;
    case 11:
        return shrub::month::NOVEMBER;
    case 12:
        return shrub::month::DECEMBER;
    default:
        throw std::invalid_argument("Invalid month");
    }
}

//------------------------------------------------------------------------------
// Ввод параметров кустарника из файла
void In(shrub &s, ifstream &ifst) {
    int type;
    ifst >> s.name >> type;
    s.floweringMonth = IntToMonth(type);
}

//------------------------------------------------------------------------------
// Преобразование month к string
string MonthToString(shrub::month value) {
    switch (value) {
    case shrub::month::JANUARY:
        return "JANUARY";
    case shrub::month::FEBRUARY:
        return "FEBRUARY";
    case shrub::month::MARCH:
        return "MARCH";
    case shrub::month::APRIL:
        return "APRIL";
    case shrub::month::MAY:
        return "MAY";
    case shrub::month::JUNE:
        return "JUNE";
    case shrub::month::JULY:
        return "JULY";
    case shrub::month::AUGUST:
        return "AUGUST";
    case shrub::month::SEPTEMBER:
        return "SEPTEMBER";
    case shrub::month::OCTOBER:
        return "OCTOBER";
    case shrub::month::NOVEMBER:
        return "NOVEMBER";
    case shrub::month::DECEMBER:
        return "DECEMBER";
    default:
        throw std::invalid_argument("Invalid flowering month");
    }
}
// Случайный ввод параметров кустарника
void InRnd(shrub &s) {
    s.name = RandomShrubName();
    s.floweringMonth = IntToMonth(RandomNumber() % 12 + 1);
}

//------------------------------------------------------------------------------
// Вывод параметров кустарника в форматируемый поток
void Out(shrub &s, ofstream &ofst) {
    ofst << "It is Shrub: name = " << s.name
        << ", flowering month = " << MonthToString(s.floweringMonth)
        << ". Part of Vowels = " << GetPartOfVowels(s);
}

//------------------------------------------------------------------------------
// Получение частного от деления числа гласных букв в названии на общую длину названия
double GetPartOfVowels(shrub& s) {
    return GetPartOfVowels(s.name);
}
