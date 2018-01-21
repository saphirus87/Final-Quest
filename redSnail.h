#pragma once
#include "enemy.h"

#define REDSNAIL_HP			1					// 체력값
#define REDSNAIL_DAMAGE		1					// 공격력
#define FIND				200					//절대 탐지 범위
enum frameDirection1
{
	REDSNAIL_LEFT_FRAME,
	REDSNAIL_RIGHT_FRAME,
	REDSNAIL_END
};

class redSnail : public enemy
{
private:
	image * _redSnail;

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

	frameDirection1 _frameDirection;

public:
	redSnail();
	~redSnail();


	HRESULT init(const char* imageName, POINT position, int Lx, int Rx, float speed);
	void release(void);
	void update(void);
	void render(void);

	void found(void);		// 탐색함수
};

