//------------------------------------------------------------------------------
// tree.cpp - содержит реализацию класса дерева
//------------------------------------------------------------------------------

#include "tree.h"

Tree::Tree(std::string name, long treeAge)
	:Plant(name)
{
	age = treeAge;
}

//------------------------------------------------------------------------------
// Вывод параметров дерева в виде строки
std::string Tree::ToString() {
	return "It is Tree: name = " + Name
		+ ", age = " + std::to_string(age)
		+ ". Part of Vowels = " + std::to_string(GetPartOfVowels());
};
