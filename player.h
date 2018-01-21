#pragma once
#include "gameNode.h"
#include "progressBar.h"

enum playerDirection
{
	LEFT,
	RIGHT
};

enum playerState
{
	PLAYER_RIGHT,
	PLAYER_LEFT,
	PLAYER_JUMP,
	PLAYER_IDLE
};

class player : public gameNode
{
protected:
	progressBar* _hpBar;		//플레이어 체력

	playerState _state;			//플레이어 상태
	playerDirection _dir;		//왼쪽? 오른쪽?

	image* _player;				//플레이어 이미지
	RECT _rc;					//플레이어 렉트

	float _x, _y;				//플레이어 좌표 (left, top)
	float _speed;				//플레이어 이동속도
	float _gravity;				//중력

	float _jumpPower;			//플레이어 점프력
	int   _jumpTime;			//플레이어 점프시간
	int   _jumpCount;			//플레이어 점프 횟수
	bool  _isJump;				//플레이어 점프 했니?
	bool  _isLeft;				//플레이어 왼쪽으로 이동햇뉘?
	bool  _isRight;				//플레이어 오른쪽으로 이동햇뉘?
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
	////				이미지 키값        , 이미지 파일   , 렉트좌표 x,y    ,               체력           , 체력바 가로길이, 체력바 세로길이
	HRESULT init();
	void release();
	void update();
	void render();

	void playerAtk();		//공격 함수
	void playerMove();		//움직임 함수
	void playerDraw();		//그려주는 함수

	void setPlayerX(float x) { _x = x; }			//셋 엑스
	float* getPlayerX() { return &_x; }				//겟 엑스

	void setPlayerY(float y) { _y = y; }			//셋 와이
	float* getPlayerY() { return &_y; }				//겟 와이

	void Gravityzero() { _gravity = 0; }
	void Jumpzero() { _jumpPower = 0; }

	player();
	~player();
};

