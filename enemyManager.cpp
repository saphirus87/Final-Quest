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
	//_snail = new redSnail;
	//_snail->init("redSnail", PointMake(WINSIZEX / 2, WINSIZEY/2));

	for (int i = 0; i <5; i++)
	{
		redSnail* _snail1 = new redSnail;
		_snail1->init("redSnail", PointMake(WINSIZEX / 2, 50 + i * 100), WINSIZEX / 2 - 100, WINSIZEX / 2 + (i + 1) * 100, (i+1) *2);

		_vRedSnail.push_back(_snail1);
	}

	for (int i = 0; i < 5; i++)
	{
		_spoa = new spoa;
		_spoa->init("spoa", PointMake(WINSIZEX / 2 - 200 , 50 + i * 100), WINSIZEX / 2 - 300, WINSIZEX / 2 + (i + 1) * 100, (i+1) *2 );
		_vSpoa.push_back(_spoa);
	}
	
	
	return S_OK;
}
void enemyManager::release(void)
{

}
void enemyManager::update(void)	
{
	for (int i = 0; i < _vRedSnail.size(); ++i)
	{
		_vRedSnail[i]->update();
	}
	for (int i = 0; i < _vSpoa.size(); ++i)
	{
		_vSpoa[i]->update();
	}
	//_snail->update();
	
}
void enemyManager::render(void)	
{
	for (int i = 0; i < _vRedSnail.size(); ++i)
	{
		_vRedSnail[i]->render();
	}
	for (int i = 0; i < _vSpoa.size(); ++i)
	{
		_vSpoa[i]->render();
	}
	//_snail->render();
}





