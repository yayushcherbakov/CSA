//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>
#include <time.h> // для замеров времени выполнения

#include "container.h"

void errMessage1() {
	cout << "incorrect command line!\n"
		"  Waited:\n"
		"     command -f infile outfile\n"
		"  Or:\n"
		"     command -n number outfile\n";
}

void errMessage2() {
	cout << "incorrect qualifier value!\n"
		"  Waited:\n"
		"     command -f infile outfile\n"
		"  Or:\n"
		"     command -n number outfile\n";
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	if (argc != 4) {
		errMessage1();
		std::getchar();
		return 1;
	}

	cout << "Start" << endl;
	cout << "Conteiner is initializing" << endl;
	Container c;
	cout << "Conteiner is initialized" << endl;

	cout << "Plants are creating" << endl;
	if (!strcmp(argv[1], "-f")) {
		ifstream ifst(argv[2]);
		try {
			c = Container(ifst);
		}
		catch (const std::invalid_argument& e) {
			cout << e.what() << endl;
			cout << "Invalid model in plant number " << c.GetLenght() + 1 << endl;
			cout << "Fix data model and try again";
			std::getchar();
			return 3;
		}
	}
	else if (!strcmp(argv[1], "-n")) {
		auto size = atoi(argv[2]);
		if ((size < 1) || (size > 10000)) {
			cout << "Incorrect numer of plants = "
				<< size
				<< ". Set 0 < number <= 10000\n";
			return 3;
		}
		// системные часы в качестве инициализатора
		srand(static_cast<unsigned int>(time(0)));
		// Заполнение контейнера генератором случайных чисел
		c = Container(size);
	}
	else {
		errMessage2();
		std::getchar();
		return 2;
	}
	cout << "Plants are created" << endl;

	// Вывод содержимого контейнера в файл
	ofstream ofst(argv[3]);
	ofst << "Filled container:\n";
	c.Out(ofst);
	cout << "Container is written to outfile" << endl;

	// The 2nd part of task
	cout << "Container is sorting" << endl;
	clock_t start = clock();
	c.QuickSort();
	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC;
	cout << "Sorting time: " << elapsed << endl;
	ofst << "Sorting time: " << elapsed << endl;

	cout << "Container is sorted" << endl;

	// Вывод содержимого контейнера в файл
	ofst << "Sorted container:\n";
	c.Out(ofst);
	cout << "Sorded container is written to outfile" << endl;

	cout << "Stop" << endl;
	return 0;
}