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
	//��ư �ʱ�ȭ(��ư�̹��� Ű��, X, Y��ǥ, ������X, Y ��ǥ, �ݹ������ �Լ��̸�)
	_btnSceneChange[0]->init("��ư", 150, WINSIZEY - 100,
		PointMake(0, 1), PointMake(0, 0), reallySceneChange);
	_btnSceneChange[3] = new button;
	_btnSceneChange[3]->init("��ư", 150, 100, PointMake(0, 1), PointMake(0, 0), cbSceneChange);

	_btnSceneChange[1] = new button;
	//��ư �ʱ�ȭ(��ư�̹��� Ű��, X, Y��ǥ, ������X, Y ��ǥ, �ݹ������ �Լ��̸�)
	_btnSceneChange[1]->init("��ư", 400, WINSIZEY - 100,
		PointMake(0, 1), PointMake(0, 0), reallySceneChange);

	_btnSceneChange[2] = new button;
	//��ư �ʱ�ȭ(��ư�̹��� Ű��, X, Y��ǥ, ������X, Y ��ǥ, �ݹ������ �Լ��̸�)
	_btnSceneChange[2]->init("��ư", 650, WINSIZEY - 100,
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
	TextOut(getMemDC(), WINSIZEX / 2 - 50, 50, "����Ʈ ���̿�!", strlen("����Ʈ ���̿�!"));
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
	SCENEMANAGER->changeScene("��Ÿ��");
}

void selectScene::reallySceneChange()
{
	SCENEMANAGER->changeScene("������?��");
}