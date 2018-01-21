#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{

}

HRESULT playGround::init()
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("���۹��", ".//sceneImage//readyBackGround.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����Ű", ".//sceneImage//pressButton.bmp", 500, 46, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("����Ʈ���ϸ�", ".//sceneImage//����Ʈ��3.BMP", 1280, 720, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����Ʈ������", ".//sceneImage//����Ʈ��2.BMP", 1280, 720, true, RGB(255, 0, 255));


	IMAGEMANAGER->addFrameImage("����Ʈ��Ƽ����Ʈ�ϸ�", ".//sceneImage//rockManSelectMoving.bmp", 1600, 100, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����Ʈ����", ".//sceneImage//zeroSelectMoving.bmp", 1600, 100, 16, 1, true, RGB(255, 0, 255));


	IMAGEMANAGER->addFrameImage("��ư", ".//sceneImage//button.bmp", 0, 0, 122, 62, 1, 2, true, RGB(255, 0, 255));

	SOUNDMANAGER->addSound("����Ʈ�Ƴ��", ".//effectSound//playerSelect.wav", false, false);
	SOUNDMANAGER->addSound("�÷��̾�Ȯ��", ".//effectSound//playerClick.wav", false, false);
	SOUNDMANAGER->addSound("����Ʈ", ".//effectSound//selectSound.wav", false, false);

	_select = new characterSelectScene;
	_start = new gameStartScene;
	_mainGame = new gameScene;


	SCENEMANAGER->addScene("����", _start);
	SCENEMANAGER->addScene("����", _select);
	SCENEMANAGER->addScene("����", _mainGame);

	SCENEMANAGER->changeScene("����");


	return S_OK;
}

//�޸� ���� ����
void playGround::release(void)
{
	gameNode::release();

}

//����
void playGround::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();

		
}

//�׸��°�.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== �� ���� �մ��� ���ÿ� ========================

	SCENEMANAGER->render();
	
	//SetTextColor(getMemDC(), RGB(255, 255, 255));
	TIMEMANAGER->render(getMemDC());

	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc������ �׷��ش� 
}
