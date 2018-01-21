#pragma once
#include "enemy.h"

#define REDSNAIL_HP			1					// 체력값
#define REDSNAIL_DAMAGE		1					// 공격력
#define FIND				200					//절대 탐지 범위

class redSnail : public enemy
{
private:


public:
	redSnail();
	~redSnail();

	virtual HRESULT init(const char* imageName, POINT position, int Lx, int Rx, float speed);
	virtual void update(void);
	virtual void render(void);
};

