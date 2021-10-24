#ifndef __shrub__
#define __shrub__

//------------------------------------------------------------------------------
// shrub.h - содержит описание кустарника
//------------------------------------------------------------------------------

#include "plant.h"

using namespace std;

// Кустарник
class Shrub : public Plant {
public:
	enum month {
		JANUARY = 1,
		FEBRUARY = 2,
		MARCH = 3,
		APRIL = 4,
		MAY = 5,
		JUNE = 6,
		JULY = 7,
		AUGUST = 8,
		SEPTEMBER = 9,
		OCTOBER = 10,
		NOVEMBER = 11,
		DECEMBER = 12
	};

	// Конструктор кустарника.
	Shrub(std::string name, int month);

	// Отформатированный вывод параметров кустарника в виде строки
	std::string ToString() override;

private:
	month floweringMonth;

	// Преобразование int к month
	month IntToMonth(int value);

	// Преобразование month к string
	std::string MonthToString(month value);
};

#endif //__shrub__
