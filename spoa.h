#pragma once
#include "enemy.h"


#define SPOA_HP				1						// ü�°�
#define SPOA_DAMAGE			1						// ���ݷ�
#define SPOA_FIND				200					//���� Ž�� ����

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

	frameDirection _frameDirection;
public:
	spoa();
	~spoa();

	HRESULT init(const char* imageName, POINT position, int Lx, int Rx, float speed);
	void release(void);
	void update(void);
	void render(void);
};

