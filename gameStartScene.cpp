#include "stdafx.h"
#include "gameStartScene.h"


gameStartScene::gameStartScene()
{
}


gameStartScene::~gameStartScene()
{

}

HRESULT gameStartScene::init()
{
	_fadeIn = 0;
	_count = 0;
	_alpha = 255;
	_isStart = false;

	CAMERAMANAGER->addImage("��ŸƮ", 1280, 720);
	return S_OK;
}
void gameStartScene::release()
{

}
void gameStartScene::update() 
{

	_count++;

	if (_count % 10 == 0)
	{

		if (_fadeIn == 0)
		{
			_fadeIn = 255;
		}
		else if (_fadeIn == 255)
		{
			_fadeIn = 0;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && !_isStart)
	{
		_isStart = true;
		SOUNDMANAGER->play("�÷��̾�Ȯ��");
	}

	if (_isStart)
	{
		_alpha -= 5;
		if (_alpha <= 0)
		{
			SCENEMANAGER->changeScene("����");
		}
	}
}
void gameStartScene::render() 
{
	IMAGEMANAGER->findImage("���۹��")->alphaRender(CAMERAMANAGER->findImage("��ŸƮ")->getMemDC(),255);
	IMAGEMANAGER->findImage("����Ű")->alphaRender(CAMERAMANAGER->findImage("��ŸƮ")->getMemDC(), WINSIZEX / 2 - 250, WINSIZEY - 200, _fadeIn);
	CAMERAMANAGER->findImage("��ŸƮ")->alpharender(getMemDC(), 0, 0, 1280, 720, 0, 0, 1, _alpha);
}