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