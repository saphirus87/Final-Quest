#pragma once
#include "gameNode.h"
#include "ship.h"

class battle;
class aviator;
class guardian;

class starcraftScene : public gameNode
{
private:
	ship* _battle;
	ship* _aviator;
	ship* _guardian;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	starcraftScene();
	~starcraftScene();
};

