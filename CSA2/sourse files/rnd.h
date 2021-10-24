#ifndef __rnd__
#define __rnd__

#include <cstdlib>
#include <string>

//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных значений
//------------------------------------------------------------------------------
static class rnd {
public:
	// Возвращает случайное целое значение - возраст.
	static int RandomAge();

	// Генерирует случайный номер альтернативы растения.
	static int RandomPlantType();

	// Генерирует случайный номер - тип цветка. 
	static int RandomFlowerType();

	// Генерирует случайный месяц. 
	static int RandomMonth();

	// Генерирует название дерева.
	static std::string RandomTreeName();

	// Генерирует название кустарника.
	static std::string RandomShrubName();

	// Генерирует название цветка.
	static std::string RandomFlowerName();
};

#endif