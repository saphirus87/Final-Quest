#pragma once
#include "gameNode.h"
#include "zero.h"

class gameScene : public gameNode
{
private:
	zero* _zero;

public:
	gameScene();
	~gameScene();
	
	HRESULT init();
	void release();
	void update();
	void render();
};