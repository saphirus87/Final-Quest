#pragma once
#include "enemy.h"

#define SPOA_HP				1						// ü�°�
#define SPOA_DAMAGE			1						// ���ݷ�
#define SPOA_FIND			200					//���� Ž�� ����

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

