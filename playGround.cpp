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

	IMAGEMANAGER->addImage("바탕", "우주.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage("battle", "battle.bmp", 0, 0, 1536, 79, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("aviator", "aviator.bmp", 0, 0, 960, 52, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("guardian", "guardian.bmp", 0, 0, 1293, 67, 16, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("bullet", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage("missilePF", "missilePF.bmp", 0, 0, 576, 44, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("버튼", "button.bmp", 0, 0, 122, 62, 1, 2, true, RGB(255, 0, 255));
	
	
	
	SCENEMANAGER->addScene("정말로?씬", new selectScene);

	//방법 1
	_select = new selectScene;
	SCENEMANAGER->addScene("셀렉트씬", _select);

	//방법 2
	SCENEMANAGER->addScene("스타씬", new starcraftScene);

	SCENEMANAGER->changeScene("셀렉트씬");


	
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
	//================== 이 위는 손대지 마시오 =========================

	IMAGEMANAGER->findImage("바탕")->render(getMemDC(),0,0);
	
	SCENEMANAGER->render();
	
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	TIMEMANAGER->render(getMemDC());

	//================== 이 아래는 손대지 마시오 ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc영역에 그려준다 
}
