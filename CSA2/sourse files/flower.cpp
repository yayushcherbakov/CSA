//------------------------------------------------------------------------------
// flower.cpp - содержит реализацию класса flower
//------------------------------------------------------------------------------

#include "flower.h"
#include <stdexcept>

//------------------------------------------------------------------------------
// Преобразование int к flower type
Flower::type Flower::IntToFlowerType(int value) {
	switch (value) {
	case Flower::type::HOME:
		return Flower::type::HOME;
	case Flower::type::WILD:
		return Flower::type::WILD;
	case Flower::type::GARDEN:
		return Flower::type::GARDEN;
	default:
		throw std::invalid_argument("Invalid flower type");
	}
}

//------------------------------------------------------------------------------
// Преобразование flower type к string
string Flower::FlowerTypetoString(Flower::type value) {
	switch (value) {
	case Flower::type::HOME:
		return "HOME";
	case Flower::type::WILD:
		return "WILD";
	case Flower::type::GARDEN:
		return "GARDEN";
	default:
		throw std::invalid_argument("Invalid flower type");
	}
}

//------------------------------------------------------------------------------
// Конструктор цветка. 
Flower::Flower(std::string name, int flowerTypeNumber) :Plant(name) {
	flowerType = IntToFlowerType(flowerTypeNumber);
}

//------------------------------------------------------------------------------
// Отформатированный вывод данных. 
std::string Flower::ToString() {
	return "It is Flower: name = " + Name
		+ ", Flower type = " + FlowerTypetoString(flowerType)
		+ ". Part of Vowels = " + std::to_string(GetPartOfVowels());
};
