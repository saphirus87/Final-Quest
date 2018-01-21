#pragma once
#include "redSnail.h"
#include "spoa.h"
#include <vector>
#include <map>

#define enemyCount 5

class enemyManager : public gameNode
{
private:
	typedef vector<enemy*> vRedSnail;
	typedef vector<enemy*>::iterator viRedSnail;

	typedef vector<enemy*> vSpoa;
private:

	vRedSnail  _vRedSnail;
	viRedSnail _viRedSnail;
	redSnail* _snail;


	vSpoa _vSpoa;
	spoa* _spoa;

public:
	enemyManager();
	~enemyManager();
	
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);
};


