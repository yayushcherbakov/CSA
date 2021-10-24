//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Создание пустого контейнера
Container::Container() {
	plants = new Plant * [max_len];
	lenght = 0;
}

//------------------------------------------------------------------------------
// Ввод параметров растения из файла
Plant* GetPlantFromStream(std::ifstream& ifst) {
	int k;
	ifst >> k;
	std::string age_str, name;
	int age = 0;
	switch (k) {
	case Plant::TREE:
		ifst >> name >> age_str;
		try {
			age = stol(age_str);
		}
		catch (const std::invalid_argument& e) {
			throw std::invalid_argument("Invalid tree age");
		}

		return (new Tree(name, age));
	case Plant::SHRUB:
		int type;
		ifst >> name >> type;
		return (new Flower(name, type));
	case Plant::FLOWER:
		int month;
		ifst >> name >> month;
		return (new Flower(name, month));
	default:
		throw std::invalid_argument("Invalid plant type");
	}
}

//------------------------------------------------------------------------------
// Создание контейнера из указанного потока
Container::Container(std::ifstream& ifst) :Container() {
	while (!ifst.eof()) {
		if ((plants[lenght] = GetPlantFromStream(ifst)) != 0) {
			lenght++;
		}
	}
}

//------------------------------------------------------------------------------
// Создание случайного растения
Plant* GetRandomPlant() {
	int k = rnd::RandomPlantType();
	switch (k) {
	case Plant::TREE:
		return (new Tree(rnd::RandomTreeName(), rnd::RandomAge()));
	case Plant::SHRUB:
		return (new Shrub(rnd::RandomShrubName(), rnd::RandomMonth()));
	case Plant::FLOWER:
		return (new Flower(rnd::RandomFlowerName(), rnd::RandomFlowerType()));
	default:
		throw std::invalid_argument("Invalid plant type");
	}
}

//------------------------------------------------------------------------------
// Создание контейнера определенного размера со случайными значениями
Container::Container(int size) :Container() {
	while (lenght < size) {
		if ((plants[lenght] = GetRandomPlant()) != nullptr) {
			lenght++;
		}
	}
}

//------------------------------------------------------------------------------
// Получение количества элементов в контейнере
int Container::GetLenght()
{
	return 0;
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(std::ofstream& ofst) {
	ofst << "Container contains " << lenght << " elements." << std::endl;
	for (int i = 0; i < lenght; i++) {
		ofst << i << ": " << plants[i]->ToString() << std::endl;
	}
}

//------------------------------------------------------------------------------
// Перестановка обьектов местами
void Container::Swap(Plant** a, Plant** b)
{
	Plant* temp = *a;
	*a = *b;
	*b = temp;
}

//------------------------------------------------------------------------------
// Выбираем крайний правый элемент как опорный.
// Разбиение: перераспределение элементов в массиве таким образом,
// что элементы, меньшие опорного, помещаются перед ним, а большие или равные - после.
int Container::Partition(Plant* arr[], int low, int high)
{
	Plant* pivot = arr[high];// опорный элемент
	int i = (low - 1);  // индекс крайнего правого элемента, который меньше опорного

	for (int j = low; j <= high - 1; j++)
	{
		if ((*arr[j]).GetPartOfVowels() < (*pivot).GetPartOfVowels())
		{
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

//------------------------------------------------------------------------------
// Быстрая сортировка массива растений
void Container::QuickSort(Plant* arr[], int low, int high)
{
	if (low < high)
	{
		int pi = Partition(arr, low, high);

		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}
//------------------------------------------------------------------------------
// Быстрая сортировка растений в контейнере
void Container::QuickSort() {
	QuickSort(plants, 0, lenght - 1);
}

