#include "stdafx.h"
#include "enemyManager.h"


enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{

}
HRESULT enemyManager::init(void)
{
	for (int i = 0; i < 5; ++i)
	{
		redSnail* _snail1 = new redSnail;
		_snail1->init("redSnail", PointMake(RND->getFromIntTo(520, 1530), 344), 520, 1530, RND->getFromIntTo(3, 6));
		_enemys.push_back(_snail1);
		_snail1 = NULL;
		_snail1 = new redSnail;
		_snail1->init("redSnail", PointMake(RND->getFromIntTo(0, 700), 895), 0, 700, RND->getFromIntTo(3, 6));
		_enemys.push_back(_snail1);
		_snail1 = NULL;
		_snail1 = new redSnail;
		_snail1->init("redSnail", PointMake(RND->getFromIntTo(1350, 2054), 895), 1350, 2054, RND->getFromIntTo(3, 6));
		_enemys.push_back(_snail1);
		spoa* _spoa1 = new spoa;
		_spoa1->init("redSnail", PointMake(RND->getFromIntTo(0, 818), 614), 0, 818, RND->getFromIntTo(3, 6));
		_enemys.push_back(_spoa1);
		_spoa1 = NULL;
		_spoa1 = new spoa;
		_spoa1->init("redSnail", PointMake(RND->getFromIntTo(1255, 2056), 614), 1255, 2056, RND->getFromIntTo(3, 6));
		_enemys.push_back(_spoa1);
		_spoa1 = NULL;
		_spoa1 = new spoa;
		_spoa1->init("redSnail", PointMake(RND->getFromIntTo(0, 2056), 1172), 0, 2056, RND->getFromIntTo(3, 6));
		_enemys.push_back(_spoa1);
	}

	
	return S_OK;
}
void enemyManager::release(void)
{

}
void enemyManager::update(void)	
{
	for (int i = 0; i < _enemys.size(); ++i)
	{
		_enemys[i]->update();
	}
}

void enemyManager::render(HDC hdc)	
{
	for (int i = 0; i < _enemys.size(); ++i)
	{
		_enemys[i]->render(hdc);
	}
}

void enemyManager::chaseplayer(int x, int y)
{
	for (int i = 0; i < _enemys.size(); ++i)
	{
		_enemys[i]->setChasePt(x, y);
	}
}



