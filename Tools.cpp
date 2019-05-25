#include <Windows.h>
#include "Tools.h"

CTools::CTools()
{

}

CTools::~CTools()
{

}

void CTools::gotoxy(int x, int y)
{
	COORD coor;
	coor.X = x;
	coor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
}
