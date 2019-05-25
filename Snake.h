#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <vector>
#include "Unit.h"
#include "Food.h"

using namespace std;

typedef enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}Directions;

class CSnake
{
public:
	CSnake(int x = 30, 
		int y = 8, 
		int length = 4, 
		Directions direction = RIGHT, 
		int speed = 100, 
		char pic = '*');
	virtual ~CSnake();

	void showSnake();
	void eraseSnake();
	void growup();
	void changeDirection(int key);
	void move();
	bool eatFood(CFood *pFood);

public:
	int m_length;
	int m_headx;
	int m_heady;
	int m_speed;
	char m_pic;
	Directions m_curDirection;
	vector<CUnit> m_vecBody;
};

#endif

