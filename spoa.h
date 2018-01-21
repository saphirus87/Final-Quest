#pragma once
#include "enemy.h"


#define SPOA_HP				1						// 체력값
#define SPOA_DAMAGE			1						// 공격력
#define SPOA_FIND				200					//절대 탐지 범위

enum frameDirection
{
	SPOA_LEFT_FRAME,
	SPOA_RIGHT_FRAME,
	SOPA_END
};

class spoa : public enemy
{
private:

	image * _spoa;

	// 디렉션바꾸기
	bool _dir;
	// 움직임 좌우 변환
	bool _LRchange;
	// 이동 범위
	int _Lx, _Rx;
	int _x, _y;
	//이동속도
	float _speed;
	//대미지
	int _damage;
	//Hp
	int _currentHP, _maxHP;
	//거리
	int _distance;
	//인식 범위
	int _find;

	int _count;

	int _frameX, _frameY;

	frameDirection _frameDirection;
public:
	spoa();
	~spoa();

	HRESULT init(const char* imageName, POINT position, int Lx, int Rx, float speed);
	void release(void);
	void update(void);
	void render(void);
};

