#pragma once
#include "enemy.h"

#define REDSNAIL_HP			1					// ü�°�
#define REDSNAIL_DAMAGE		1					// ���ݷ�
#define FIND				200					//���� Ž�� ����

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

