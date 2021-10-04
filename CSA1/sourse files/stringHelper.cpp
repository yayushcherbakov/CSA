//------------------------------------------------------------------------------
// stringHelper.cpp - содержит описпние процедур обработки строк
//------------------------------------------------------------------------------

#include "stringHelper.h"

double GetPartOfVowels(string str)
{
	int i, vow = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
			|| str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
		{
			vow++;
		}
	}
	return ((double)vow) / i;
}