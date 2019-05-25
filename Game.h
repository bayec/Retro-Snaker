#ifndef _GAME_H_
#define _GAME_H_

#include "Food.h"
#include "Snake.h"

class CGame
{
public:
	CGame();
	virtual ~CGame();

	void run();
	void drawGameArea();
	void drawGameInfo();
	bool checkFailed();
	void checkLevel();
	void changeInfo();

public:
	static const int KLEFT;
	static const int KUP;
	static const int KWIDTH;
	static const int KHEIGHT;
	static const int KSCORE_OFFSET;
	static const int KLEVEL_OFFSET;

public:
	CFood* m_food;
	CSnake* m_snake;
	int m_score;
	int m_level;
};

#endif

