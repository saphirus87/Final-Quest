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
	_redSnail = IMAGEMANAGER->addFrameImage("redSnail", ".//image_enemy//redSanil.bmp", 164, 68, 4, 2, true, RGB(255, 0, 255));
	_dir = true;
	_LRchange = true;
	_currentHP = _maxHP = REDSNAIL_HP;
	_damage = REDSNAIL_DAMAGE;
	_speed = speed;
	_Lx = Lx;
	_Rx = Rx;

	_x = position.x;
	_y = position.y;

	_frameX = 0;
	_frameY = 0;
	_count = 0;
	
	_find = FIND;

	return  S_OK;
}

void redSnail::release(void)
{

}

void  redSnail::update(void)
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
		_frameDirection = REDSNAIL_LEFT_FRAME;
	}
	if (!_LRchange)
	{
		_x += _speed;
		_frameDirection = REDSNAIL_RIGHT_FRAME;
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
		if (_frameX < _redSnail->getMaxFrameX()) _frameX++;
		else _frameX = 0;
	}

}

void redSnail::render(void)	
{
	_redSnail->frameRender(getMemDC(), _x, _y, _frameX, _frameDirection);
}

void redSnail::found(void)
{

}