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

	IMAGEMANAGER->addImage("시작배경", ".//sceneImage//readyBackGround.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("시작키", ".//sceneImage//pressButton.bmp", 500, 46, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("셀렉트씬록맨", ".//sceneImage//셀렉트씬3.BMP", 1280, 720, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("셀렉트씬제로", ".//sceneImage//셀렉트씬2.BMP", 1280, 720, true, RGB(255, 0, 255));


	IMAGEMANAGER->addFrameImage("셀렉트얼티메이트록맨", ".//sceneImage//rockManSelectMoving.bmp", 1600, 100, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("셀렉트제로", ".//sceneImage//zeroSelectMoving.bmp", 1600, 100, 16, 1, true, RGB(255, 0, 255));


	IMAGEMANAGER->addFrameImage("버튼", ".//sceneImage//button.bmp", 0, 0, 122, 62, 1, 2, true, RGB(255, 0, 255));

	SOUNDMANAGER->addSound("셀렉트아나운서", ".//effectSound//playerSelect.wav", false, false);
	SOUNDMANAGER->addSound("플레이어확정", ".//effectSound//playerClick.wav", false, false);
	SOUNDMANAGER->addSound("셀렉트", ".//effectSound//selectSound.wav", false, false);

	_select = new characterSelectScene;
	_start = new gameStartScene;
	_mainGame = new gameScene;


	SCENEMANAGER->addScene("시작", _start);
	SCENEMANAGER->addScene("선택", _select);
	SCENEMANAGER->addScene("메인", _mainGame);

	SCENEMANAGER->changeScene("시작");


	return S_OK;
}

//메모리 관련 삭제
void playGround::release(void)
{
	gameNode::release();

}

//연산
void playGround::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();

		
}

//그리는거.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== 이 위는 손대지 마시오 ========================

	SCENEMANAGER->render();
	
	//SetTextColor(getMemDC(), RGB(255, 255, 255));
	TIMEMANAGER->render(getMemDC());

	//================== 이 아래는 손대지 마시오 ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc영역에 그려준다 
}
