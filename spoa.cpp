#include "stdafx.h"
#include "spoa.h"


spoa::spoa()
{
}


spoa::~spoa()
{

}

HRESULT spoa::init(const char* imageName, POINT position, int Lx, int Rx, float speed)
{
	enemy::init(imageName, position, Lx, Rx, speed);

	_img = IMAGEMANAGER->addFrameImage("spoa", ".//image_enemy//spoa.bmp", 156, 72, 4, 2, true, RGB(255, 0, 255));
	_currentHP = _maxHP = SPOA_HP;
	_damage = SPOA_DAMAGE;
	_find = SPOA_FIND;

	return  S_OK;
}
void spoa::update(void)																  
{
	enemy::update();
}
void spoa::render(void)																  
{
	enemy::render();
}