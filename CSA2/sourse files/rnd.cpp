//------------------------------------------------------------------------------
// rnd.cpp - содержит реализацию класса случайного генератора значений
// для уже созданного кустарника
//------------------------------------------------------------------------------

#include "rnd.h"

//------------------------------------------------------------------------------
// Возвращает случайное целое значение - возраст.
int rnd::RandomAge() {
	return rand() % 1000 + 1;
}

//------------------------------------------------------------------------------
// Генерирует случайный номер альтернативы растения. 
int rnd::RandomPlantType() {
	return rand() % 3 + 1;
}

//------------------------------------------------------------------------------
// Генерирует случайный номер - тип цветка. 
int rnd::RandomFlowerType() {
	return rand() % 3 + 1;
}

//------------------------------------------------------------------------------
// Генерирует случайный месяц. 
int rnd::RandomMonth() {
	return rand() % 12 + 1;
}

//------------------------------------------------------------------------------
// Генерирует название дерева.
std::string rnd::RandomTreeName() {
	std::string treeNames[10] = { "acacia", "birch" , "walnut" , "oak" , "willow" , "chestnut" , "olive" , "palm" , "pine" , "poplar" };
	std::string name = treeNames[rand() % 10];
	return name;
}

//------------------------------------------------------------------------------
// Генерирует название кустарника.
 std::string rnd::RandomShrubName() {
	std::string shrubNames[10] = { "elder", "heather" , "jasmine" , "sea-buckthorn" , "nut-grove" , "ivy" , "blackthorn" , "dog-rose" , "box-tree" , "honey-suckle" };
	std::string name = shrubNames[rand() % 10];
	return name;
}

 //------------------------------------------------------------------------------
 // Генерирует название цветка.
std::string rnd::RandomFlowerName() {
	std::string flowerNames[10] = { "pansies", "cornflower" , "carnation" , "dahlia" , "gladiolus" , "iris" , "bluebell" , "lavender" , "lily" , "poppy" };
	std::string name = flowerNames[rand() % 10];
	return name;
}