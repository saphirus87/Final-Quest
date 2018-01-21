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
	IMAGEMANAGER->findImage("���۹��")->alphaRender(getMemDC(),_alpha);
	IMAGEMANAGER->findImage("����Ű")->alphaRender(getMemDC(), WINSIZEX / 2 - 250, WINSIZEY - 200, _fadeIn);

}