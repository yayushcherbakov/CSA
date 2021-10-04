//------------------------------------------------------------------------------
// flower.cpp - содержит функции обработки цветка
//------------------------------------------------------------------------------

#include "flower.h"

//------------------------------------------------------------------------------
// Преобразование int к flower type
flower::type IntToFlowerType(int value) {
    switch (value) {
    case flower::type::HOME:
        return flower::type::HOME;
    case flower::type::WILD:
        return flower::type::WILD;
    case flower::type::GARDEN:
        return flower::type::GARDEN;
    default:
        throw std::invalid_argument("Invalid flower type");
    }
}


//------------------------------------------------------------------------------
// Ввод параметров цветка из потока
void In(flower& f, ifstream& ifst) {
	int type;
	ifst >> f.name >> type;
	f.flowerType = IntToFlowerType(type);
}

//------------------------------------------------------------------------------
// Преобразование flower type к string
string flowerTypetoString(flower::type value) {
    switch (value) {
    case flower::type::HOME:
        return "HOME";
    case flower::type::WILD:
        return "WILD";
    case flower::type::GARDEN:
        return "GARDEN";
    default:
        throw std::invalid_argument("Invalid flower type");
    }
}

// Случайный ввод параметров цветка
void InRnd(flower& f) {
	f.name = RandomFlowerName();
    f.flowerType = IntToFlowerType(RandomNumber() % 3 + 1);
}

//------------------------------------------------------------------------------
// Вывод параметров цветка в поток
void Out(flower& f, ofstream& ofst) {
    ofst << "It is flower: name = " << f.name 
        << ", Flower type = " << flowerTypetoString(f.flowerType)
        <<". Part of Vowels = " << GetPartOfVowels(f);
}

//------------------------------------------------------------------------------
// Получение частного от деления числа гласных букв в названии на общую длину названия
double GetPartOfVowels(flower& f) {
	return GetPartOfVowels(f.name);
}
