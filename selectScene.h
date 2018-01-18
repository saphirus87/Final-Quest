#pragma once
#include "gameNode.h"
#include "button.h"
#include "ship.h"

class battle;
class aviator;
class guardian;

class selectScene : public gameNode
{
private:
	//�� �ٲܶ� ����� ��ư
	button* _btnSceneChange[6];

	ship* _selectSceneBattle;
	ship* _selectSceneAviator;
	ship* _selectSceneguardian;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	//�������� �Ǿ��־ static���� �����(�ݹ��Լ��� ���� �Լ�)
	static void cbSceneChange();
	static void reallySceneChange();


	selectScene();
	~selectScene();
};

