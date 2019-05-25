#include <stdlib.h>
#include <time.h>
#include "Food.h"
#include "Game.h"

CFood::CFood(int x, int y, char pic):CUnit(x, y, pic)
{
	srand((unsigned int)time(NULL));
}

CFood::~CFood()
{

}

void CFood::createPos(vector<CUnit> *vec)
{
	while (true)
	{
		int x = CGame::KLEFT + 1 + rand() % (CGame::KWIDTH - 2);
		int y = CGame::KUP + 3 + rand() % (CGame::KHEIGHT - 2);

		size_t i = 0;
		for (i = 0; i < vec->size(); i++)
		{
			if (x == vec->at(i).m_x && y == vec->at(i).m_y)
			{
				//代表食物当前生成的位置在蛇身上
				break;
			}
		}

		if (i == vec->size())
		{
			m_x = x;
			m_y = y;
			return;
		}
	}
}
