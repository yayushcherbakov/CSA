#ifndef __flower__
#define __flower__

//------------------------------------------------------------------------------
// flower.h - содержит описание цветка
//------------------------------------------------------------------------------


#include "plant.h"

using namespace std;

//------------------------------------------------------------------------------
// Цветок
class Flower : public Plant {
public:
	enum type {
		HOME = 1,
		WILD = 2,
		GARDEN = 3
	};
	Flower(std::string name, int flowerType);
	std::string ToString() override;

private:
	type flowerType;

	// Конвертация int to flowerType
	type IntToFlowerType(int value);

	// Конвертация flowerType to string
	string FlowerTypetoString(Flower::type value);
};

#endif //__flower__
