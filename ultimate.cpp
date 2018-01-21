#include "stdafx.h"
#include "ultimate.h"


ultimate::ultimate()
{
}


ultimate::~ultimate()
{
}

HRESULT ultimate::init()
{
	player::init();
	IMAGEMANAGER->addFrameImage("ultimate_none", "images/ultimate_none.bmp", 175, 98, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ultimate_move", "images/ultimate_move.bmp", 800, 100, 16, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ultimate_jump", "images/ultimate_jump.bmp", 440, 140, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ultimate_dash", "images/ultimate_dash.bmp", 420, 100, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ultimate_skill", "images/ultimate_skill.bmp", 910, 140, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ultimate_at", "images/ultimate_at.bmp", 408, 98, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ultimate_appearance", "images/ultimate_appearance.bmp", 700, 180, 10, 1, true, RGB(255, 0, 255));
	isAttack = false;
	ultimate_state = ULTIMATE_NONE;
	count = 0;
	atk_count = 0;
	move_count = 0;
	stay_count = 0;
	skill_count = 0;
	return S_OK;
}

void ultimate::release()
{

}

void ultimate::update()
{
	count++;
	frameUpdate();
	move();	
	
	//총알
	cout << vGun.size() << endl;
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		isAttack = true;
	}
	bullet_fire();
	bullet_move();
}

void ultimate::render(HDC hdc)
{
	switch (ultimate_state)
	{
	case ULTIMATE_NONE:
		IMAGEMANAGER->findImage("ultimate_none")->frameRender(hdc, _x, _y,
			IMAGEMANAGER->findImage("ultimate_none")->getFrameX(), IMAGEMANAGER->findImage("ultimate_none")->getFrameY());
		break;
	case ULTIMATE_LEFT:
		IMAGEMANAGER->findImage("ultimate_move")->frameRender(hdc, _x, _y,
			IMAGEMANAGER->findImage("ultimate_move")->getFrameX(), IMAGEMANAGER->findImage("ultimate_move")->getFrameY());
		break;
	case ULTIMATE_RIGHT:
		IMAGEMANAGER->findImage("ultimate_move")->frameRender(hdc, _x, _y,
			IMAGEMANAGER->findImage("ultimate_move")->getFrameX(), IMAGEMANAGER->findImage("ultimate_move")->getFrameY());
		break;
	case ULTIMATE_AT:
		IMAGEMANAGER->findImage("ultimate_at")->frameRender(hdc, _x, _y,
			IMAGEMANAGER->findImage("ultimate_at")->getFrameX(), IMAGEMANAGER->findImage("ultimate_at")->getFrameY());
		break;
	case ULTIMATE_SKILL:
		break;
		//불릿 이미지
	}
		RectangleMake(getMemDC(), gun.x, gun.y, 10, 10);
}

void ultimate::jump()
{

}

void ultimate::move()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		ultimate_state = ULTIMATE_LEFT;
		IMAGEMANAGER->findImage("ultimate_move")->setFrameY(1);
		IMAGEMANAGER->findImage("ultimate_none")->setFrameY(1);
		IMAGEMANAGER->findImage("ultimate_at")->setFrameY(1);
		_x -= 3;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		ultimate_state = ULTIMATE_NONE;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		ultimate_state = ULTIMATE_RIGHT;
		IMAGEMANAGER->findImage("ultimate_move")->setFrameY(0);
		IMAGEMANAGER->findImage("ultimate_none")->setFrameY(0);
		IMAGEMANAGER->findImage("ultimate_at")->setFrameY(0);
		_x += 3;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		ultimate_state = ULTIMATE_NONE;
	}
}

void ultimate::frameUpdate()
{
	if (ultimate_state == ULTIMATE_NONE)
	{
		if (count % 12 == 0)
		{
			stay_count++;
			if (stay_count > IMAGEMANAGER->findImage("ultimate_none")->getMaxFrameX())
			{
				stay_count = 0;
			}
			IMAGEMANAGER->findImage("ultimate_none")->setFrameX(stay_count);
		}
	}
	if (ultimate_state == ULTIMATE_RIGHT)
	{
		if (count % 5 == 0)
		{
			move_count++;
			if (move_count > IMAGEMANAGER->findImage("ultimate_move")->getMaxFrameX())
			{
				move_count = 2;
			}
			IMAGEMANAGER->findImage("ultimate_move")->setFrameX(move_count);
		}
	}
	if (ultimate_state == ULTIMATE_LEFT)
	{
		if (count % 5 == 0)
		{
			move_count--;
			if (move_count < 0)
			{
				move_count = IMAGEMANAGER->findImage("ultimate_move")->getMaxFrameX()-2;
			}
			IMAGEMANAGER->findImage("ultimate_move")->setFrameX(move_count);
		}
	}
	//총쏘는거 프레임
	if (ultimate_state == ULTIMATE_AT)
	{
		if (IMAGEMANAGER->findImage("ultimate_at")->getFrameY() == 0)
		{
			if (count % 9 == 0)
			{
				atk_count++;
				if (atk_count > IMAGEMANAGER->findImage("ultimate_at")->getMaxFrameX())
				{
					atk_count = 0;
					ultimate_state = ULTIMATE_NONE;
				}
				IMAGEMANAGER->findImage("ultimate_at")->setFrameX(atk_count);
			}
		}
		if (IMAGEMANAGER->findImage("ultimate_at")->getFrameY() == 1)
		{
			if (count % 9 == 0)
			{
				atk_count--;
				if (atk_count<0)
				{
					atk_count = IMAGEMANAGER->findImage("ultimate_at")->getMaxFrameX();
					ultimate_state = ULTIMATE_NONE;
				}
				IMAGEMANAGER->findImage("ultimate_at")->setFrameX(atk_count);
			}
		}
	}
}



void ultimate::bullet_fire()
{
	if (isAttack)
	{
		// img = add
		gun.x = _x;
		gun.y = _y;
		gun.rc_gun = RectMake(gun.x, gun.y, 10, 10);
		vGun.push_back(gun);
		isAttack = false;
		ultimate_state = ULTIMATE_AT;
	}
}

void ultimate::bullet_move()
{
	if (IMAGEMANAGER->findImage("ultimate_move")->getFrameY() == 0) //라이트일때
	{
		for (viGun = vGun.begin(); viGun != vGun.end();)
		{
			gun.x += 10;
			viGun++;
		}
	}
	if (IMAGEMANAGER->findImage("ultimate_move")->getFrameY() == 1) //레프트일때
	{
		for (viGun = vGun.begin(); viGun != vGun.end();)
		{
			gun.x -= 10;
			viGun++;
		}
	}
}
