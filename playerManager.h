#pragma once
#include "gameNode.h"
#include "progressBar.h"

class playerManager : public gameNode
{
protected:
	progressBar* _hpBar;

	image* _player;				//플레이어 이미지
	RECT _rc;					//플레이어 렉트

	float _x, _y;				//플레이어 좌표 (left, top)

	//플레이어 프레임 이미지를 위한 변수
	int _currentFrameX;
	int _currentFrameY;
	int _frame;
	/////////////////////////////////

	//플레이어 체력 or 체력바 길이
	float _currentHP, _maxHP;	//플레이어 체력
	float _width, _height;		//플레이어 체력바 길이
	string _strkey;				//체력바 키값
	/////////////////////////////////




	//충돌 알고리즘(픽셀), 프레임랜더
	//좌표 : Left Top
	//WINDOW_SIZE 1280 X 720

public:
	HRESULT init(const char* imageName, string strKey, float x, float y, float currentHP, float maxHP, float width, float height);
	void release();
	void update();
	void render();

	void playerMove();		//움직임 함수
	void playerDraw();		//그려주는 함수

	playerManager();
	~playerManager();
};

