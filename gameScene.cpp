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
	IMAGEMANAGER->addImage("�����������", ".//images//background.bmp", 2095, 1410, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���������ٴ�", ".//images//ground.bmp", 2095, 1410, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ٴڹ��", ".//images//downground.bmp", 2095, 186, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ȼ��浹", ".//images//crash.bmp", 2095, 1410, true, RGB(255, 0, 255));

	CAMERAMANAGER->addImage("��������ī�޶�", 2095, 1410);
	_alpha = 0;
	_loofx = 0;
	camerax = 0;
	cameray = 0;

	_em = new enemyManager;
	_em->init();

	Character = SCENEMANAGER->getUnitNum();

	if (Character)
	{
		_player = new ultimate;
	}
	else
	{
		_player = new zero;
	}
	_player->init();


	return S_OK;
}

void gameScene::release()
{

}

void gameScene::update() 
{
	if (_alpha < 255)_alpha += 5;
	++_loofx;

	_player->update();
	camerax = *_player->getPlayerX() - WINSIZEX / 2;

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

	for (; crash(_player->getPlayerX(), _player->getPlayerY());)
	{
		_player->Gravityzero();
		_player->Jumpzero();
	}

	_em->chaseplayer(*_player->getPlayerX(), *_player->getPlayerY());
	_em->update();
}
void gameScene::render() 
{
	IMAGEMANAGER->findImage("�����������")->render(CAMERAMANAGER->findImage("��������ī�޶�")->getMemDC());
	IMAGEMANAGER->findImage("�ٴڹ��")->loopRender(CAMERAMANAGER->findImage("��������ī�޶�")->getMemDC(), &RectMake(0, 1224, 2095, 186), _loofx, 0);
	IMAGEMANAGER->findImage("���������ٴ�")->render(CAMERAMANAGER->findImage("��������ī�޶�")->getMemDC());

	_player->render(CAMERAMANAGER->findImage("��������ī�޶�")->getMemDC());

	_em->render(CAMERAMANAGER->findImage("��������ī�޶�")->getMemDC());

	CAMERAMANAGER->findImage("��������ī�޶�")->alpharender(getMemDC(), 0, 0, 1280, 720, camerax, cameray, 1, _alpha);

}

bool gameScene::crash(float* x, float* y)
{
	COLORREF color = GetPixel(IMAGEMANAGER->findImage("�ȼ��浹")->getMemDC(), *x, *y);

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