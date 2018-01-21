#include "stdafx.h"
#include "characterSelectScene.h"


characterSelectScene::characterSelectScene()
{
}


characterSelectScene::~characterSelectScene()
{

}


HRESULT characterSelectScene::init()
{
	_alpha = 0;
	_selectUnit = 0;
	_isStart = false;

	_zeroIndex = IMAGEMANAGER->findImage("����Ʈ����")->getMaxFrameX() - 1;//�����ӿ�
	IMAGEMANAGER->findImage("����Ʈ����")->setFrameX(_zeroIndex);
	_rockManIndex = 0; //�����ӿ�
	_indexCount = 0; //�����Ӽӵ� ������

	SOUNDMANAGER->play("����Ʈ�Ƴ��");

	CAMERAMANAGER->addImage("����Ʈ", 1280, 720);
	return S_OK;
}
void characterSelectScene::release()
{

}
void characterSelectScene::update()	
{

	sceneChange();//���� ���ξ����� �ٲ��ִ� �Լ� ���İ��� 0���� ����߸� ������ �Լ��� �����Ѵ�
	charactorInput(); //���� �����ʴ����� ĳ���� �������ִ� �Լ�
	selectUnitFrame();//�������� �������ִ� �Լ�


}
void characterSelectScene::render()	
{
	if (_selectUnit == 0)
	{
		IMAGEMANAGER->alphaRender("����Ʈ���ϸ�", CAMERAMANAGER->findImage("����Ʈ")->getMemDC(), 255);
	}
	else if (_selectUnit == 1)
	{
		IMAGEMANAGER->alphaRender("����Ʈ������", CAMERAMANAGER->findImage("����Ʈ")->getMemDC(), 255);
	}


	IMAGEMANAGER->findImage("����Ʈ��Ƽ����Ʈ�ϸ�")->frameRender(CAMERAMANAGER->findImage("����Ʈ")->getMemDC(), 50, WINSIZEY - 300);
	IMAGEMANAGER->findImage("����Ʈ����")->frameRender(CAMERAMANAGER->findImage("����Ʈ")->getMemDC(), WINSIZEX - 150, WINSIZEY - 300);

	CAMERAMANAGER->findImage("����Ʈ")->alpharender(getMemDC(), 0, 0, 1280, 720, 0, 0, 1, _alpha);
}

void characterSelectScene::charactorInput()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && (_selectUnit>0))
	{
		_rockManIndex = 0;
		_zeroIndex = IMAGEMANAGER->findImage("����Ʈ����")->getMaxFrameX()-1;
		_selectUnit = 0;

		IMAGEMANAGER->findImage("����Ʈ����")->setFrameX(_zeroIndex);
		SOUNDMANAGER->play("����Ʈ");

	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && (_selectUnit<2))
	{
		_zeroIndex = IMAGEMANAGER->findImage("����Ʈ����")->getMaxFrameX();
		_rockManIndex = 0;
		_selectUnit = 1;
		IMAGEMANAGER->findImage("����Ʈ��Ƽ����Ʈ�ϸ�")->setFrameX(_rockManIndex);
		SOUNDMANAGER->play("����Ʈ");
	}
}

void characterSelectScene::sceneChange()
{
	if (_alpha < 255&&!_isStart)
	{
		_alpha += 5;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_isStart = true;
		SCENEMANAGER->setUnitNum(_selectUnit);
		SOUNDMANAGER->play("�÷��̾�Ȯ��");
	}
 	if (_isStart)
	{
		if (_alpha <= 255)
		{
			_alpha -= 5;
		}
		if (_alpha <= 6)
		{
			SCENEMANAGER->changeScene("����");
		}
	}
}


void characterSelectScene::selectUnitFrame()
{
	_indexCount++;


	if (_selectUnit == 0)
	{
		IMAGEMANAGER->findImage("����Ʈ��Ƽ����Ʈ�ϸ�")->setFrameX(_rockManIndex);
		if (_indexCount % 4 == 0)
		{
			_rockManIndex++;
			_indexCount = 0;
		}
		if (_rockManIndex > IMAGEMANAGER->findImage("����Ʈ��Ƽ����Ʈ�ϸ�")->getMaxFrameX())
		{
			_rockManIndex = 1;
		}
	}
	if (_selectUnit == 1)
	{
		if (_indexCount % 4 == 0)
		{
			_zeroIndex--;
			_indexCount = 0;
		}


		IMAGEMANAGER->findImage("����Ʈ����")->setFrameX(_zeroIndex);

		if (_zeroIndex < 0)
		{
			_zeroIndex = IMAGEMANAGER->findImage("����Ʈ����")->getMaxFrameX() - 2;
		}
	}
}