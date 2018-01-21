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

	_zeroIndex = IMAGEMANAGER->findImage("셀렉트제로")->getMaxFrameX() - 1;//프레임용
	IMAGEMANAGER->findImage("셀렉트제로")->setFrameX(_zeroIndex);
	_rockManIndex = 0; //프레임용
	_indexCount = 0; //프레임속도 조절용

	SOUNDMANAGER->play("셀렉트아나운서");

	CAMERAMANAGER->addImage("셀렉트", 1280, 720);
	return S_OK;
}
void characterSelectScene::release()
{

}
void characterSelectScene::update()	
{

	sceneChange();//이제 메인씬으로 바꿔주는 함수 알파값을 0까지 떨어뜨린 다음에 함수를 실행한다
	charactorInput(); //왼쪽 오른쪽누를시 캐릭터 변경해주는 함수
	selectUnitFrame();//프레임을 조절해주는 함수


}
void characterSelectScene::render()	
{
	if (_selectUnit == 0)
	{
		IMAGEMANAGER->alphaRender("셀렉트씬록맨", CAMERAMANAGER->findImage("셀렉트")->getMemDC(), 255);
	}
	else if (_selectUnit == 1)
	{
		IMAGEMANAGER->alphaRender("셀렉트씬제로", CAMERAMANAGER->findImage("셀렉트")->getMemDC(), 255);
	}


	IMAGEMANAGER->findImage("셀렉트얼티메이트록맨")->frameRender(CAMERAMANAGER->findImage("셀렉트")->getMemDC(), 50, WINSIZEY - 300);
	IMAGEMANAGER->findImage("셀렉트제로")->frameRender(CAMERAMANAGER->findImage("셀렉트")->getMemDC(), WINSIZEX - 150, WINSIZEY - 300);

	CAMERAMANAGER->findImage("셀렉트")->alpharender(getMemDC(), 0, 0, 1280, 720, 0, 0, 1, _alpha);
}

void characterSelectScene::charactorInput()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && (_selectUnit>0))
	{
		_rockManIndex = 0;
		_zeroIndex = IMAGEMANAGER->findImage("셀렉트제로")->getMaxFrameX()-1;
		_selectUnit = 0;

		IMAGEMANAGER->findImage("셀렉트제로")->setFrameX(_zeroIndex);
		SOUNDMANAGER->play("셀렉트");

	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && (_selectUnit<2))
	{
		_zeroIndex = IMAGEMANAGER->findImage("셀렉트제로")->getMaxFrameX();
		_rockManIndex = 0;
		_selectUnit = 1;
		IMAGEMANAGER->findImage("셀렉트얼티메이트록맨")->setFrameX(_rockManIndex);
		SOUNDMANAGER->play("셀렉트");
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
		SOUNDMANAGER->play("플레이어확정");
	}
 	if (_isStart)
	{
		if (_alpha <= 255)
		{
			_alpha -= 5;
		}
		if (_alpha <= 6)
		{
			SCENEMANAGER->changeScene("메인");
		}
	}
}


void characterSelectScene::selectUnitFrame()
{
	_indexCount++;


	if (_selectUnit == 0)
	{
		IMAGEMANAGER->findImage("셀렉트얼티메이트록맨")->setFrameX(_rockManIndex);
		if (_indexCount % 4 == 0)
		{
			_rockManIndex++;
			_indexCount = 0;
		}
		if (_rockManIndex > IMAGEMANAGER->findImage("셀렉트얼티메이트록맨")->getMaxFrameX())
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


		IMAGEMANAGER->findImage("셀렉트제로")->setFrameX(_zeroIndex);

		if (_zeroIndex < 0)
		{
			_zeroIndex = IMAGEMANAGER->findImage("셀렉트제로")->getMaxFrameX() - 2;
		}
	}
}