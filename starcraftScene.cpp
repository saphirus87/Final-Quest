#include "stdafx.h"
#include "starcraftScene.h"
#include "battle.h"
#include "aviator.h"
#include "guardian.h"

starcraftScene::starcraftScene()
{
}


starcraftScene::~starcraftScene()
{

}

HRESULT starcraftScene::init()
{
	_battle = new battle;
	_battle->init("battle", WINSIZEX / 2, WINSIZEY / 2);

	_aviator = new aviator;
	_aviator->init("aviator", WINSIZEX / 2, WINSIZEY / 2);

	_guardian = new guardian;
	_guardian->init("guardian", WINSIZEX / 2, WINSIZEY / 2);

	return S_OK;
}

void starcraftScene::release()
{

}

void starcraftScene::update() 
{
	_battle->update();
	_aviator->update();
	_guardian->update();

	if (KEYMANAGER->isOnceKeyDown(VK_F1)) SCENEMANAGER->changeScene("셀렉트씬");
}

void starcraftScene::render() 
{
	_battle->render();
	_aviator->render();
	_guardian->render();

	TextOut(getMemDC(), WINSIZEX / 2 - 50, WINSIZEY - 100, "게임씬이요!", strlen("게임씬이요!"));
}
