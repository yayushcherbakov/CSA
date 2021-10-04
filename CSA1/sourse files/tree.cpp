//------------------------------------------------------------------------------
// tree.cpp - содержит процедуры обработки дерева
//------------------------------------------------------------------------------

#include "tree.h"

//------------------------------------------------------------------------------
// Ввод параметров дерева из потока
void In(tree& t, ifstream& ifst) {
	
	try {
		string age;
		ifst >> t.name >> age;
		t.age = stol(age);
	}
	catch (const std::invalid_argument& e) {
		throw std::invalid_argument("Invalid tree age");
	}
	
}

// Случайный ввод параметров дерева
void InRnd(tree& t) {
	t.name = RandomTreeName();
	t.age = RandomNumber();
}

//------------------------------------------------------------------------------
// Вывод параметров дерева в поток
void Out(tree& t, ofstream& ofst) {
	ofst << "It is Tree: name = " << t.name << ", age = " << t.age << ". Part of Vowels = " << GetPartOfVowels(t);
}

//------------------------------------------------------------------------------
// Получение частного от деления числа гласных букв в названии на общую длину названия
double GetPartOfVowels(tree& t) {
	return GetPartOfVowels(t.name);
}
