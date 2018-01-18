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

	IMAGEMANAGER->addImage("����", "����.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage("battle", "battle.bmp", 0, 0, 1536, 79, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("aviator", "aviator.bmp", 0, 0, 960, 52, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("guardian", "guardian.bmp", 0, 0, 1293, 67, 16, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("bullet", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage("missilePF", "missilePF.bmp", 0, 0, 576, 44, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ư", "button.bmp", 0, 0, 122, 62, 1, 2, true, RGB(255, 0, 255));
	
	
	
	SCENEMANAGER->addScene("������?��", new selectScene);

	//��� 1
	_select = new selectScene;
	SCENEMANAGER->addScene("����Ʈ��", _select);

	//��� 2
	SCENEMANAGER->addScene("��Ÿ��", new starcraftScene);

	SCENEMANAGER->changeScene("����Ʈ��");


	
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
	//================== �� ���� �մ��� ���ÿ� =========================

	IMAGEMANAGER->findImage("����")->render(getMemDC(),0,0);
	
	SCENEMANAGER->render();
	
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	TIMEMANAGER->render(getMemDC());

	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc������ �׷��ش� 
}
