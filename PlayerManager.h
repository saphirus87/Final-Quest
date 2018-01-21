#pragma once 
#include "gameNode.h"
#include <vector>
#include "zero.h"
#include "ultimate.h"
class PlayerManager : public gameNode
{
private:
	typedef vector<player*> vEnemy;
	typedef vector<player*>::iterator viEnemy;

	vEnemy		vMegaman;
	viEnemy		viMegaman;



public:
	PlayerManager();
	~PlayerManager();
	HRESULT init();
	void release();
	void update();
	void render();


	void zeroSet();
	void ultimateSet();
	void move();

	//이미지 정보
};

