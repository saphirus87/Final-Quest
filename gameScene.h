#pragma once
#include "gameNode.h"
#include "zero.h"
#include "enemyManager.h"

class gameScene : public gameNode
{
private:
	int camerax, cameray;
	int _alpha;
	int _loofx;

	enemyManager* _em;

	zero* _zero;

public:
	gameScene();
	~gameScene();
	
	HRESULT init();
	void release();
	void update();
	void render();

	bool crash(float* x, float* y);
};