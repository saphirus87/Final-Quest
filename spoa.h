#pragma once
#include "enemy.h"

#define SPOA_HP				1						// 체력값
#define SPOA_DAMAGE			1						// 공격력
#define SPOA_FIND			200					//절대 탐지 범위

class spoa : public enemy
{
private:

public:
	spoa();
	~spoa();

	virtual HRESULT init(const char* imageName, POINT position, int Lx, int Rx, float speed);
	virtual void update(void);
	virtual void render(HDC hdc);
};

