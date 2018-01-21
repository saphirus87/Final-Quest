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

	CAMERAMANAGER->addImage("스타트", 1280, 720);
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
		SOUNDMANAGER->play("플레이어확정");
	}

	if (_isStart)
	{
		_alpha -= 5;
		if (_alpha <= 0)
		{
			SCENEMANAGER->changeScene("선택");
		}
	}
}
void gameStartScene::render() 
{
	IMAGEMANAGER->findImage("시작배경")->alphaRender(CAMERAMANAGER->findImage("스타트")->getMemDC(),255);
	IMAGEMANAGER->findImage("시작키")->alphaRender(CAMERAMANAGER->findImage("스타트")->getMemDC(), WINSIZEX / 2 - 250, WINSIZEY - 200, _fadeIn);
	CAMERAMANAGER->findImage("스타트")->alpharender(getMemDC(), 0, 0, 1280, 720, 0, 0, 1, _alpha);
}