#ifndef __tree__
#define __tree__

//------------------------------------------------------------------------------
// tree.h - содержит описание дерева
//------------------------------------------------------------------------------

#include "plant.h"

using namespace std;
//------------------------------------------------------------------------------
// Дерево
//------------------------------------------------------------------------------
class Tree : public Plant {
public:
	// Конструктор дерева.
	Tree(std::string name, long age);

	// Отформатированный вывод информации о дереве в виде строки.
	std::string ToString() override;

private:
	long age;
};

#endif //__tree__
