#include "stdafx.h"
#include "playerManager.h"


playerManager::playerManager()
{
}


playerManager::~playerManager()
{

}

//초기화를 하자!
HRESULT playerManager::init(const char* imageName, string strKey, float x, float y, float currentHP, float maxHP, float width, float height)
{
	_strkey = strKey;						//이미지 키값
	_currentHP = currentHP;					//체력
	_maxHP = maxHP;							//체력
	_width = width;							//체력바 길이
	_height = height;						//체력바 길이
	_x = x;									//플레이어 좌표 (left)
	_y = y;									//플레이어 좌표 (top)

	_currentFrameX = 0;
	_currentFrameY = 0;
	_frame = 0;

	//렉트
	_rc = RectMake(x, y, _player->getFrameWidth(), _player->getFrameHeight());

	_player = IMAGEMANAGER->findImage(imageName);

	//_hpBar = new progressBar;
	//_hpBar->init(_string, _rc.left, _rc.bottom,)

	return S_OK;
}

void playerManager::release()
{

}

void playerManager::update()
{
	playerMove();
}

void playerManager::render()
{
	playerDraw();
}


//움직임 함수
void playerManager::playerMove()
{

}


//그려주는 함수
void playerManager::playerDraw()
{

}
