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
	IMAGEMANAGER->addImage("스테이지배경", ".//images//background.bmp", 2095, 1410, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("스테이지바닥", ".//images//ground.bmp", 2095, 1410, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("바닥배경", ".//images//downground.bmp", 2095, 186, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("픽셀충돌", ".//images//crash.bmp", 2095, 1410, true, RGB(255, 0, 255));

	CAMERAMANAGER->addImage("스테이지카메라", 2095, 1410);
	_alpha = 0;
	_loofx = 0;
	camerax = 0;
	cameray = 0;
	_zero = new zero;
	_zero->init();

	_em = new enemyManager;
	_em->init();

	return S_OK;
}

void gameScene::release()
{

}

void gameScene::update() 
{
	if (_alpha < 255)_alpha += 5;
	++_loofx;
	_zero->update();
	camerax = *_zero->getPlayerX() - WINSIZEX / 2;
	//cameray = *_zero->getPlayerY() - WINSIZEY / 2;

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		cameray += 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		cameray -= 5;
	}

	if (camerax < 0)camerax = 0;
	if (cameray < 0)cameray = 0;

	if (camerax > 2095 - WINSIZEX)camerax = 2095 - WINSIZEX;
	if (cameray > 1410 - WINSIZEY)cameray = 1410 - WINSIZEY;

	for (; crash(_zero->getPlayerX(), _zero->getPlayerY());)
	{
		_zero->Gravityzero();
		_zero->Jumpzero();
	}

	_em->chaseplayer(*_zero->getPlayerX(), *_zero->getPlayerY());
	_em->update();
}
void gameScene::render() 
{
	IMAGEMANAGER->findImage("스테이지배경")->render(CAMERAMANAGER->findImage("스테이지카메라")->getMemDC());
	IMAGEMANAGER->findImage("바닥배경")->loopRender(CAMERAMANAGER->findImage("스테이지카메라")->getMemDC(), &RectMake(0, 1224, 2095, 186), _loofx, 0);
	IMAGEMANAGER->findImage("스테이지바닥")->render(CAMERAMANAGER->findImage("스테이지카메라")->getMemDC());

	_zero->render(CAMERAMANAGER->findImage("스테이지카메라")->getMemDC());

	_em->render(CAMERAMANAGER->findImage("스테이지카메라")->getMemDC());

	CAMERAMANAGER->findImage("스테이지카메라")->alpharender(getMemDC(), 0, 0, 1280, 720, camerax, cameray, 1, _alpha);

}

bool gameScene::crash(float* x, float* y)
{
	COLORREF color = GetPixel(IMAGEMANAGER->findImage("픽셀충돌")->getMemDC(), *x, *y);

	int r = GetRValue(color);
	int g = GetGValue(color);
	int b = GetBValue(color);

	if (r == 0 && g == 0 && b == 255)
	{
 		--*y;
		return true;
	}
	return false;
}