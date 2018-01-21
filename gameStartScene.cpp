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
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		SCENEMANAGER->changeScene("선택");
	}
}
void gameStartScene::render() 
{
	IMAGEMANAGER->findImage("시작배경")->render(getMemDC());
	IMAGEMANAGER->findImage("시작키")->alphaRender(getMemDC(), WINSIZEX / 2 - 250, WINSIZEY - 200, _fadeIn);

}