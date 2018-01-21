#pragma once
#include "gameNode.h"	
#include <vector>

enum frameDirection
{
	LEFT_FRAME,
	RIGHT_FRAME,
	DIRECTION_END
};

class enemy : public gameNode
{

protected:
	image * _img;

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

	int _chaseX, _chaseY;

	frameDirection _frameDirection;

public:
	enemy();
	~enemy();

	virtual HRESULT init(const char* imageName, POINT position, int Lx, int Rx, float speed);
	void release(void);
	virtual void update(void);
	virtual void render(HDC hdc);

	inline void setChasePt(int chaseX, int chaseY) { _chaseX = chaseX; _chaseY = chaseY; }
};