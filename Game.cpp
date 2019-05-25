#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Game.h"
#include "Tools.h"

using namespace std;

const int CGame::KLEFT = 5;
const int CGame::KUP = 2;
const int CGame::KWIDTH = 70;
const int CGame::KHEIGHT = 20;
const int CGame::KSCORE_OFFSET = 50;
const int CGame::KLEVEL_OFFSET = 65;

CGame::CGame()
{
	m_food = new CFood();
	m_snake = new CSnake();
	m_score = 0;
	m_level = 1;

	drawGameArea();
	drawGameInfo();
}

CGame::~CGame()
{
	delete m_food;
	delete m_snake;
	m_food = NULL;
	m_snake = NULL;
}

void CGame::drawGameArea()
{
	CTools::gotoxy(KLEFT, KUP);
	for (int i = 0; i < KWIDTH; i++)
	{
		cout << "-";
	}

	for (int j = 0; j < KHEIGHT; j++)
	{
		CTools::gotoxy(KLEFT, KUP + 1 + j);
		cout << "|";
		CTools::gotoxy(KLEFT + KWIDTH - 1, KUP + 1 + j);
		cout << "|";
	}

	CTools::gotoxy(KLEFT, KUP + KHEIGHT + 1);
	for (int k = 0; k < KWIDTH; k++)
	{
		cout << "-";
	}

	CTools::gotoxy(KLEFT + 1, KUP + 2);
	for (int i = 0; i < KWIDTH - 2; i++)
	{
		cout << "-";
	}
}

void CGame::drawGameInfo()
{
	CTools::gotoxy(KLEFT + 1, KUP + 1);
	cout << "游戏名称：贪吃蛇";

	CTools::gotoxy(KLEFT + 20, KUP + 1);
	cout << "编写者：李晨";

	CTools::gotoxy(KLEFT + 40, KUP + 1);
	cout << "当前得分：";

	CTools::gotoxy(KLEFT + KSCORE_OFFSET, KUP + 1);
	cout << m_score;

	CTools::gotoxy(KLEFT + 55, KUP + 1);
	cout << "当前关卡：";

	CTools::gotoxy(KLEFT + KLEVEL_OFFSET, KUP + 1);
	cout << m_level;
}

void CGame::run()
{
	m_food->createPos(&(m_snake->m_vecBody));
	m_food->show();

	m_snake->showSnake();

	int key = 0;
	bool stopFlag = true;
	bool pauseFlag = false;
	while (key != VK_ESCAPE && stopFlag)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == VK_SPACE)
			{
				pauseFlag = !pauseFlag;
			}
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 72:
					key = 'w';
					break;
				case 80:
					key = 's';
					break;
				case 75:
					key = 'a';
					break;
				case 77:
					key = 'd';
					break;
				}
			}
			m_snake->changeDirection(key);
		}
		else
		{
			if (pauseFlag)
			{
				continue;
			}

			m_snake->move();
			if (m_snake->eatFood(m_food))
			{
				m_score += 10;
				//checkLevel();
				changeInfo();
				m_food->createPos(&(m_snake->m_vecBody));
				m_food->show();
			}

			if (checkFailed())
			{
				stopFlag = false;
				CTools::gotoxy(0, 0);
				cout << "对不起，您失败了！！！";
			}
		}
	}
}

bool CGame::checkFailed()
{
	//检测左墙
	if (m_snake->m_vecBody[0].m_x <= CGame::KLEFT)
	{
		return true;
	}
	//检测右墙
	if (m_snake->m_vecBody[0].m_x >= CGame::KLEFT + CGame::KWIDTH - 1)
	{
		return true;
	}
	//检测上墙
	if (m_snake->m_vecBody[0].m_y <= CGame::KUP + 2)
	{
		return true;
	}
	//检测下墙
	if (m_snake->m_vecBody[0].m_y >= CGame::KUP + CGame::KHEIGHT + 1)
	{
		return true;
	}

	//检测是否自残
	for (int i = 4; i < m_snake->m_length; i++)
	{
		if (m_snake->m_vecBody[0].m_x == m_snake->m_vecBody[i].m_x
			&& m_snake->m_vecBody[0].m_y == m_snake->m_vecBody[i].m_y)
		{
			return true;
		}
	}

	return false;
}

void CGame::checkLevel()
{
	int tmp = m_score / 30 + 1;
	if (tmp == m_level)
	{
		return;
	}

	m_level = tmp;
	switch (m_level)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		//通关
		CTools::gotoxy(0, 0);
		cout << "恭喜，您通关了！！！" << endl;
		break;
	}
}

void CGame::changeInfo()
{
	//改变得分
	CTools::gotoxy(KLEFT + KSCORE_OFFSET, KUP + 1);
	cout << " ";

	CTools::gotoxy(KLEFT + KSCORE_OFFSET, KUP + 1);
	cout << m_score;

	//改变level
	/*CTools::gotoxy(KLEFT + KLEVEL_OFFSET, KUP + 1);
	cout << " ";

	CTools::gotoxy(KLEFT + KLEVEL_OFFSET, KUP + 1);
	cout << m_level;*/

	//改变速度
	switch (m_score)
	{
	case 30:
		m_snake->m_speed = 50;
		break;
	case 70:
		m_snake->m_speed = 30;
		break;
	case 150:
		m_snake->m_speed = 20;
		break;
	}
}
