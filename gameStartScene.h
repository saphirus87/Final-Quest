#pragma once
#include "gameNode.h";

class gameStartScene : public gameNode
{
private:
	int _fadeIn;

	int _count;

	int _alpha;

	bool _isStart;
public:
	gameStartScene();
	~gameStartScene();

	HRESULT init();
	void release();
	void update();
	void render();
};