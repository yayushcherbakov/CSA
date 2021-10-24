//------------------------------------------------------------------------------
// rnd.cpp - �������� ���������� ������ ���������� ���������� ��������
// ��� ��� ���������� ����������
//------------------------------------------------------------------------------

#include "rnd.h"

//------------------------------------------------------------------------------
// ���������� ��������� ����� �������� - �������.
int rnd::RandomAge() {
	return rand() % 1000 + 1;
}

//------------------------------------------------------------------------------
// ���������� ��������� ����� ������������ ��������. 
int rnd::RandomPlantType() {
	return rand() % 3 + 1;
}

//------------------------------------------------------------------------------
// ���������� ��������� ����� - ��� ������. 
int rnd::RandomFlowerType() {
	return rand() % 3 + 1;
}

//------------------------------------------------------------------------------
// ���������� ��������� �����. 
int rnd::RandomMonth() {
	return rand() % 12 + 1;
}

//------------------------------------------------------------------------------
// ���������� �������� ������.
std::string rnd::RandomTreeName() {
	std::string treeNames[10] = { "acacia", "birch" , "walnut" , "oak" , "willow" , "chestnut" , "olive" , "palm" , "pine" , "poplar" };
	std::string name = treeNames[rand() % 10];
	return name;
}

//------------------------------------------------------------------------------
// ���������� �������� ����������.
 std::string rnd::RandomShrubName() {
	std::string shrubNames[10] = { "elder", "heather" , "jasmine" , "sea-buckthorn" , "nut-grove" , "ivy" , "blackthorn" , "dog-rose" , "box-tree" , "honey-suckle" };
	std::string name = shrubNames[rand() % 10];
	return name;
}

 //------------------------------------------------------------------------------
 // ���������� �������� ������.
std::string rnd::RandomFlowerName() {
	std::string flowerNames[10] = { "pansies", "cornflower" , "carnation" , "dahlia" , "gladiolus" , "iris" , "bluebell" , "lavender" , "lily" , "poppy" };
	std::string name = flowerNames[rand() % 10];
	return name;
}