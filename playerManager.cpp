#include "stdafx.h"
#include "playerManager.h"


playerManager::playerManager()
{
}


playerManager::~playerManager()
{

}

//�ʱ�ȭ�� ����!
HRESULT playerManager::init(const char* imageName, string strKey, float x, float y, float currentHP, float maxHP, float width, float height)
{
	_strkey = strKey;						//�̹��� Ű��
	_currentHP = currentHP;					//ü��
	_maxHP = maxHP;							//ü��
	_width = width;							//ü�¹� ����
	_height = height;						//ü�¹� ����
	_x = x;									//�÷��̾� ��ǥ (left)
	_y = y;									//�÷��̾� ��ǥ (top)

	_currentFrameX = 0;
	_currentFrameY = 0;
	_frame = 0;

	//��Ʈ
	_rc = RectMake(x, y, _player->getFrameWidth(), _player->getFrameHeight());

	_player = IMAGEMANAGER->findImage(imageName);

	//_hpBar = new progressBar;
	//_hpBar->init(_string, _rc.left, _rc.bottom,)

	return S_OK;
}

void playerManager::release()
{

}

void playerManager::update()
{
	playerMove();
}

void playerManager::render()
{
	playerDraw();
}


//������ �Լ�
void playerManager::playerMove()
{

}


//�׷��ִ� �Լ�
void playerManager::playerDraw()
{

}
