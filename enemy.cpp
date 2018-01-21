#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{
}


enemy::~enemy()
{
}


HRESULT enemy::init(const char* imageName, POINT position, int Lx, int Rx, float speed)
{
	//_img = IMAGEMANAGER->addFrameImage("spoa", ".//image_enemy//spoa.bmp", 156, 72, 4, 2, true, RGB(255, 0, 255));
	_dir = true;
	_LRchange = true;
	//_currentHP = _maxHP = SPOA_HP;
	//_damage = SPOA_DAMAGE;
	_speed = speed;
	_Lx = Lx;
	_Rx = Rx;

	_x = position.x;
	_y = position.y;

	_frameX = 0;
	_frameY = 0;
	_count = 0;

	//_find = SPOA_FIND;

	return  S_OK;
}
void enemy::release(void)
{

}
void enemy::update(void)
{
	_distance = getDistance(_ptMouse.x, _ptMouse.y, _x, _y);

	//ÁÂ¿ì º¯µ¿ ÆÇ´Ü
	if (_x < _Lx)
	{
		_LRchange = false;
	}
	if (_x > _Rx)
	{
		_LRchange = true;
	}

	//¹«ºê
	if (_LRchange)
	{
		_x -= _speed;
		_frameDirection = LEFT_FRAME;
	}
	if (!_LRchange)
	{
		_x += _speed;
		_frameDirection = RIGHT_FRAME;
	}

	// Å½»ö
	if (_distance <= _find && _ptMouse.x < _x)
	{
		_LRchange = true;



	}
	if (_distance <= _find && _ptMouse.x > _x)
	{
		_LRchange = false;
	}
	_count++;

	if (_count == 10)
	{
		_count = 0;
		if (_frameX < _img->getMaxFrameX()) _frameX++;
		else _frameX = 0;
	}
}
void enemy::render(HDC hdc)
{
	_img->frameRender(hdc, _x, _y, _frameX, _frameDirection);
}