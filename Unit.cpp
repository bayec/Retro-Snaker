#include <iostream>
#include "Unit.h"
#include "Tools.h"
#include <Windows.h>

using namespace std;

CUnit::CUnit(int x, int y, char pic)
{
	m_x = x;
	m_y = y;
	m_pic = pic;
}

CUnit::~CUnit()
{

}


void CUnit::show()
{
	CTools::gotoxy(m_x, m_y);
	cout << m_pic;
}

void CUnit::erase()
{
	CTools::gotoxy(m_x, m_y);
	cout << " ";
}