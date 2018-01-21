#include "stdafx.h"
#include "gameScene.h"


gameScene::gameScene()
{
}


gameScene::~gameScene()
{
}

HRESULT gameScene::init()
{
	_zero = new zero;
	_zero->init();

	return S_OK;
}
void gameScene::release()
{
}
void gameScene::update() 
{
	_zero->update();

}
void gameScene::render() 
{
	_zero->render();
}