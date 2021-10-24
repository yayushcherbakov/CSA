#ifndef __rnd__
#define __rnd__

#include <cstdlib>
#include <string>

//------------------------------------------------------------------------------
// rnd.h - �������� ��������� ��������� ��������
//------------------------------------------------------------------------------
static class rnd {
public:
	// ���������� ��������� ����� �������� - �������.
	static int RandomAge();

	// ���������� ��������� ����� ������������ ��������.
	static int RandomPlantType();

	// ���������� ��������� ����� - ��� ������. 
	static int RandomFlowerType();

	// ���������� ��������� �����. 
	static int RandomMonth();

	// ���������� �������� ������.
	static std::string RandomTreeName();

	// ���������� �������� ����������.
	static std::string RandomShrubName();

	// ���������� �������� ������.
	static std::string RandomFlowerName();
};

#endif