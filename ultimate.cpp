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
