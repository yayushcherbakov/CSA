//------------------------------------------------------------------------------
// shrub.cpp - содержит реализацию класса кустарника
// для уже созданного кустарника
//------------------------------------------------------------------------------

#include "shrub.h"
#include <stdexcept>

//------------------------------------------------------------------------------
// Преобразование int к month
Shrub::month Shrub::IntToMonth(int value) {
    switch (value) {
    case Shrub::month::JANUARY:
        return Shrub::month::JANUARY;
    case Shrub::month::FEBRUARY:
        return Shrub::month::FEBRUARY;
    case Shrub::month::MARCH:
        return Shrub::month::MARCH;
    case Shrub::month::APRIL:
        return Shrub::month::APRIL;
    case Shrub::month::MAY:
        return Shrub::month::MAY;
    case Shrub::month::JUNE:
        return Shrub::month::JUNE;
    case Shrub::month::JULY:
        return Shrub::month::JULY;
    case Shrub::month::AUGUST:
        return Shrub::month::AUGUST;
    case Shrub::month::SEPTEMBER:
        return Shrub::month::SEPTEMBER;
    case Shrub::month::OCTOBER:
        return Shrub::month::OCTOBER;
    case Shrub::month::NOVEMBER:
        return Shrub::month::NOVEMBER;
    case Shrub::month::DECEMBER:
        return Shrub::month::DECEMBER;
    default:
        throw std::invalid_argument("Invalid month");
    }
}


//------------------------------------------------------------------------------
// Конструктор кустарника.
Shrub::Shrub(std::string name, int month)
    :Plant(name)
{
    floweringMonth = IntToMonth(month);
}

//------------------------------------------------------------------------------
// Преобразование month к string
string Shrub::MonthToString(Shrub::month value) {
    switch (value) {
    case Shrub::month::JANUARY:
        return "JANUARY";
    case Shrub::month::FEBRUARY:
        return "FEBRUARY";
    case Shrub::month::MARCH:
        return "MARCH";
    case Shrub::month::APRIL:
        return "APRIL";
    case Shrub::month::MAY:
        return "MAY";
    case Shrub::month::JUNE:
        return "JUNE";
    case Shrub::month::JULY:
        return "JULY";
    case Shrub::month::AUGUST:
        return "AUGUST";
    case Shrub::month::SEPTEMBER:
        return "SEPTEMBER";
    case Shrub::month::OCTOBER:
        return "OCTOBER";
    case Shrub::month::NOVEMBER:
        return "NOVEMBER";
    case Shrub::month::DECEMBER:
        return "DECEMBER";
    default:
        throw std::invalid_argument("Invalid flowering month");
    }
}


//------------------------------------------------------------------------------
// Отформатированный вывод параметров кустарника в виде строки
std::string Shrub::ToString() {
    return "It is Shrub: name = " + Name
        + ", flowering month = " + MonthToString(floweringMonth)
        + ". Part of Vowels = " + std::to_string(GetPartOfVowels());
};
