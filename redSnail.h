#pragma once
#include "enemy.h"

#define REDSNAIL_HP			1					// ü�°�
#define REDSNAIL_DAMAGE		1					// ���ݷ�
#define FIND				200					//���� Ž�� ����
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

	// �𷺼ǹٲٱ�
	bool _dir;
	// ������ �¿� ��ȯ
	bool _LRchange;
	// �̵� ����
	int _Lx, _Rx;
	int _x, _y;
	//�̵��ӵ�
	float _speed;
	//�����
	int _damage;
	//Hp
	int _currentHP, _maxHP;
	//�Ÿ�
	int _distance;
	//�ν� ����
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

	void found(void);		// Ž���Լ�
};

