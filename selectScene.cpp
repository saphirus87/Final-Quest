#include "stdafx.h"
#include "selectScene.h"
#include "battle.h"
#include "aviator.h"
#include "guardian.h"

selectScene::selectScene()
{
}


selectScene::~selectScene()
{

}

HRESULT selectScene::init()
{
	_selectSceneBattle = new battle;
	_selectSceneBattle->init("battle", 150, 250);

	_selectSceneAviator = new aviator;
	_selectSceneAviator->init("aviator", 400, 250);

	_selectSceneguardian = new guardian;
	_selectSceneguardian->init("guardian", 650, 250);

	_btnSceneChange[0] = new button;
	//버튼 초기화(버튼이미지 키값, X, Y좌표, 프레임X, Y 좌표, 콜백적용될 함수이름)
	_btnSceneChange[0]->init("버튼", 150, WINSIZEY - 100,
		PointMake(0, 1), PointMake(0, 0), reallySceneChange);
	_btnSceneChange[3] = new button;
	_btnSceneChange[3]->init("버튼", 150, 100, PointMake(0, 1), PointMake(0, 0), cbSceneChange);

	_btnSceneChange[1] = new button;
	//버튼 초기화(버튼이미지 키값, X, Y좌표, 프레임X, Y 좌표, 콜백적용될 함수이름)
	_btnSceneChange[1]->init("버튼", 400, WINSIZEY - 100,
		PointMake(0, 1), PointMake(0, 0), reallySceneChange);

	_btnSceneChange[2] = new button;
	//버튼 초기화(버튼이미지 키값, X, Y좌표, 프레임X, Y 좌표, 콜백적용될 함수이름)
	_btnSceneChange[2]->init("버튼", 650, WINSIZEY - 100,
		PointMake(0, 1), PointMake(0, 0), reallySceneChange);


	return S_OK;
}

void selectScene::release()
{

}

void selectScene::update() 
{
	_btnSceneChange[0]->update();
	_btnSceneChange[1]->update();
	_btnSceneChange[2]->update();
	_btnSceneChange[3]->update();

	_selectSceneBattle->update();
	_selectSceneAviator->update();
	_selectSceneguardian->update();
}

void selectScene::render() 
{
	TextOut(getMemDC(), WINSIZEX / 2 - 50, 50, "셀렉트 씬이요!", strlen("셀렉트 씬이요!"));
	_btnSceneChange[0]->render();
	_btnSceneChange[1]->render();
	_btnSceneChange[2]->render();
	_btnSceneChange[3]->render();

	_selectSceneBattle->render();
	_selectSceneAviator->render();
	_selectSceneguardian->render();
}

void selectScene::cbSceneChange()
{
	SCENEMANAGER->changeScene("스타씬");
}

void selectScene::reallySceneChange()
{
	SCENEMANAGER->changeScene("정말로?씬");
}