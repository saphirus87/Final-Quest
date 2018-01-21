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

	IMAGEMANAGER->addFrameImage("zero_appearance", "images/zero_appearance.bmp", 1330, 170, 19, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zero_move", "images/zero_move.bmp", 800, 100, 16, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zero_none", "images/zero_none.bmp", 300, 100, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zero_jump_up", "images/zero_jump_up.bmp", 350, 150, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zero_jump_down", "images/zero_jump_down.bmp", 400, 180, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zero_at1", "images/zero_at1.bmp", 696, 100, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zero_at2", "images/zero_at2.bmp", 824, 120, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zero_at3", "images/zero_at3.bmp", 1300, 200, 13, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zero_dash_on", "images/zero_dash_on.bmp", 560, 100, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zero_dash_off", "images/zero_dash_off.bmp", 200, 100, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zero_hit", "images/zero_hit.bmp", 233, 140, 4, 2, true, RGB(255, 0, 255));

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


	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
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
