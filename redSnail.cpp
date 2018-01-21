#include "stdafx.h"
#include "redSnail.h"


redSnail::redSnail()
{
}


redSnail::~redSnail()
{
}

HRESULT redSnail::init(const char* imageName, POINT position, int Lx, int Rx, float speed)
{
	enemy::init(imageName, position, Lx, Rx, speed);

	_img = IMAGEMANAGER->addFrameImage("redSnail", ".//image_enemy//redSanil.bmp", 164, 68, 4, 2, true, RGB(255, 0, 255));
	_currentHP = _maxHP = REDSNAIL_HP;
	_damage = REDSNAIL_DAMAGE;
	_find = FIND;

	return  S_OK;
}

void redSnail::update(void)
{
	enemy::update();
}

void redSnail::render(void)
{
	enemy::render();
}