#ifndef _FOOD_H_
#define _FOOD_H_

#include <vector>
#include "Unit.h"

using namespace std;

class CFood: public CUnit
{
public:
	CFood(int x = 0, int y = 0, char pic = '@');
	virtual ~CFood();

	void createPos(vector<CUnit> *vec);
};

#endif

