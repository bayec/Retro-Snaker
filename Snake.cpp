#include <Windows.h>
#include <iostream>
#include "Snake.h"

using namespace std;

CSnake::CSnake(int x, int y, int length, Directions direction, int speed, char pic)
{
	m_headx = x;
	m_heady = y;
	m_length = length;
	m_curDirection = direction;
	m_speed = speed;
	m_pic = pic;
	
	int tmpx = 0;
	int tmpy = 0;

	for (int i = 0; i < m_length; i++)
	{
		switch (m_curDirection)
		{
		case UP:
			tmpx = m_headx;
			tmpy = m_heady + i;
			break;
		case DOWN:
			tmpx = m_headx;
			tmpy = m_heady - i;
			break;
		case LEFT:
			tmpx = m_headx + i;
			tmpy = m_heady;
			break;
		case RIGHT:
			tmpx = m_headx - i;
			tmpy = m_heady;
			break;
		default:
			break;
		}
		CUnit unit(tmpx, tmpy, pic);
		m_vecBody.push_back(unit);
	}
}

CSnake::~CSnake()
{

}

void CSnake::showSnake()
{
	for (int i = 0; i < m_length; i++)
	{
		m_vecBody[i].show();
	}
}

void CSnake::eraseSnake()
{
	for (int i = 0; i < m_length; i++)
	{
		m_vecBody[i].erase();
	}
}

void CSnake::changeDirection(int key)
{
	switch (key)
	{
	case 'w':
		if (m_curDirection == LEFT || m_curDirection == RIGHT)
			m_curDirection = UP;
		break;
	case 's':
		if (m_curDirection == LEFT || m_curDirection == RIGHT)
			m_curDirection = DOWN;
		break;
	case 'a':
		if (m_curDirection == UP || m_curDirection == DOWN)
			m_curDirection = LEFT;
		break;
	case 'd':
		if (m_curDirection == UP || m_curDirection == DOWN)
			m_curDirection = RIGHT;
		break;
	default:
		break;
	}
}

void CSnake::move()
{
	//擦除蛇身
	eraseSnake();

	for (int i = m_length - 2; i >= 0; i--)
	{
		m_vecBody[i + 1].m_x = m_vecBody[i].m_x;
		m_vecBody[i + 1].m_y = m_vecBody[i].m_y;
	}

	switch (m_curDirection)
	{
	case UP:
		m_vecBody[0].m_y--;
		break;
	case DOWN:
		m_vecBody[0].m_y++;
		break;
	case LEFT:
		m_vecBody[0].m_x--;
		break;
	case RIGHT:
		m_vecBody[0].m_x++;
		break;
	default:
		break;
	}

	//展示蛇身
	showSnake();

	Sleep(m_speed);
}

void CSnake::growup()
{
	CUnit unit(0, 0, m_pic);
	m_vecBody.push_back(unit);
	m_length++;
}

bool CSnake::eatFood(CFood *food)
{
	if (m_vecBody[0].m_x == food->m_x && m_vecBody[0].m_y == food->m_y)
	{
		growup();
		return true;
	}

	return false;
}