#include "stdafx.h"
#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

HRESULT PlayerManager::init()
{
	return S_OK;
}

void PlayerManager::release()
{

}

void PlayerManager::update()
{
	move();
	for (viMegaman = vMegaman.begin(); viMegaman != vMegaman.end(); viMegaman++)
	{
		(*viMegaman)->update();
	}
}

void PlayerManager::render()
{
	for (viMegaman = vMegaman.begin(); viMegaman != vMegaman.end(); viMegaman++)
	{
		(*viMegaman)->render();
	}
}

void PlayerManager::zeroSet()
{
	player* _zero;
	_zero = new zero;
	vMegaman.push_back(_zero);
	//¼à¶ó¼à¶ó
}

void PlayerManager::ultimateSet()
{
	player* _ultimate;
	_ultimate = new ultimate;
	//_ultimate->init("ultimate_appearance", RND->getFromIntTo(0, WINSIZEX), 0, 100, 100, 50, 50);
	vMegaman.push_back(_ultimate);
	//¼à¶ó¼à¶ó
}

void PlayerManager::move()
{
	for (viMegaman = vMegaman.begin(); viMegaman != vMegaman.end(); viMegaman++)
	{
		(*viMegaman)->playerMove();
	}
}

