#include "stdafx.h"
#include "guardian.h"


guardian::guardian()
{
}


guardian::~guardian()
{
}

HRESULT guardian::init(const char* imageName, int x, int y)
{
	ship::init(imageName, x, y);

	_missile = new missilePF;
	_missile->init("missilePF", 30, 400);

	return S_OK;
}

void guardian::release(void)
{

}

void guardian::update(void)
{
	ship::update();

	keyControl();

	missileMove();
}

void guardian::render(void)
{
	ship::render();

	missileDraw();
}


void guardian::keyControl(void)
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_angle -= 0.04f;
		if (_angle <= 0) _angle += PI2;
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_angle += 0.04f;
		if (_angle >= PI2) _angle -= PI2;
	}
	if (KEYMANAGER->isStayKeyDown('W')) _speed += 0.04f;
	if (KEYMANAGER->isStayKeyDown('S')) _speed -= 0.04f;

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) bulletFire();
	if (KEYMANAGER->isOnceKeyDown('X')) missileFire();
}

void guardian::missileFire()
{
	float x = _x + cosf(_angle) * 50;
	float y = _y + -sinf(_angle) * 50;

	_missile->fire(x, y, _angle, 400);
}

void guardian::missileMove()
{
	_missile->update();
}

void guardian::missileDraw()
{
	_missile->render();
}
