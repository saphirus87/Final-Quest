#include "stdafx.h"
#include "ultimate.h"


ultimate::ultimate()
{
}


ultimate::~ultimate()
{
}

HRESULT ultimate::init(const char * imageName, float x, float y, float currentHP, float maxHP, float width, float height)
{
	IMAGEMANAGER->addFrameImage("ultimate_none", "images/ultimate_none.bmp", 140, 120, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ultimate_move", "images/ultimate_move.bmp", 800, 100, 15, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ultimate_jump", "images/ultimate_jump.bmp", 440, 140, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ultimate_dash", "images/ultimate_dash.bmp", 420, 100, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ultimate_skill", "images/ultimate_skill.bmp", 910, 140, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ultimate_move_shoot", "images/ultimate_move_shoot.bmp", 900, 120, 15, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ultimate_appearance", "images/ultimate_appearance.bmp", 700, 180, 10, 1, true, RGB(255, 0, 255));

	return S_OK;
}

void ultimate::release()
{

}

void ultimate::update()
{
	frameUpdate();


	//ÃÑ¾Ë
	bullet_fire();
	bullet_move();
}

void ultimate::render()
{

}

void ultimate::jump()
{

}

void ultimate::move()
{

}

void ultimate::frameUpdate()
{

}


void ultimate::bullet_fire()
{

}

void ultimate::bullet_move()
{

}
