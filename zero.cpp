#include "stdafx.h"
#include "zero.h"


zero::zero()
{
}


zero::~zero()
{
}

HRESULT zero::init()
{
	player::init();

	return S_OK;
}

void zero::release()
{
}

void zero::update()
{
	//player::update();

	count++;
	frameUpdate();
	if (KEYMANAGER->isOnceKeyDown('X'))
	{	
		zero_state = ZERO_AT1;
		zero_atk1();
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		zero_state = ZERO_LEFT;
		IMAGEMANAGER->findImage("zero_move")->setFrameY(1);
		_x -= 2;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		zero_state = ZERO_NONE;
	}


	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		zero_state = ZERO_RIGHT;
		IMAGEMANAGER->findImage("zero_move")->setFrameY(0);
		_x += 2;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 2;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		zero_state = ZERO_NONE;
	}
}

void zero::render()
{
	RectangleMake(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	switch (zero_state)
	{
	case ZERO_AT1:
		IMAGEMANAGER->findImage("zero_at1")->frameRender(getMemDC(),_x,_y,
			IMAGEMANAGER->findImage("zero_at1")->getFrameX(), IMAGEMANAGER->findImage("zero_at1")->getFrameY());
		break;
	case ZERO_HIT:
		IMAGEMANAGER->findImage("zero_hit")->frameRender(getMemDC(), _x, _y,
			IMAGEMANAGER->findImage("zero_hit")->getFrameX(), IMAGEMANAGER->findImage("zero_hit")->getFrameY());
		break;
	case ZERO_SKILL:
		IMAGEMANAGER->findImage("zero_skill")->frameRender(getMemDC(), _x,_y,
			IMAGEMANAGER->findImage("zero_skill")->getFrameX(), IMAGEMANAGER->findImage("zero_skill")->getFrameY());
		break;
	case ZERO_LEFT:
		IMAGEMANAGER->findImage("zero_move")->frameRender(getMemDC(), 300, 300,
			IMAGEMANAGER->findImage("zero_move")->getFrameX(), IMAGEMANAGER->findImage("zero_move")->getFrameY());
		break;
	case ZERO_RIGHT:
		IMAGEMANAGER->findImage("zero_move")->frameRender(getMemDC(), 300, 300,
			IMAGEMANAGER->findImage("zero_move")->getFrameX(), IMAGEMANAGER->findImage("zero_move")->getFrameY());
	default:
		break;
	}
}

void zero::frameUpdate()
{
	if (zero_state == ZERO_AT1)
	{
		if (IMAGEMANAGER->findImage("zero_at1")->getFrameY() == 0)
		{
			if (count % 10 == 0)
			{
				at1_count++;
				if (at1_count > IMAGEMANAGER->findImage("zero_at1")->getMaxFrameX()) //¿À¸¥ÂÊ
				{
					at1_count = 0;
				}
				IMAGEMANAGER->findImage("zero_at1")->setFrameX(at1_count);
			}
		}
		else
		{
			if (count % 10 == 0)
			{
				at1_count--;
				if (at1_count < 0)
				{
					at1_count = IMAGEMANAGER->findImage("zero_at1")->getMaxFrameX();
				}
				IMAGEMANAGER->findImage("zero_at1")->setFrameX(at1_count);
			}
		}
		
	}
}


void zero::zero_atk1()
{
	att.x = _x;
	att.y = _y;
	att.arc = RectMake(_x,_y, 30, 30);
	vAtk.push_back(att);
}
