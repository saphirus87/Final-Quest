#include "stdafx.h"
#include "player.h"


player::player()
{
}


player::~player()
{

}

//�ʱ�ȭ�� ����!
//								�̹��� Ű��        , �̹��� ����   , ��Ʈ��ǥ x,y    ,               ü��           , ü�¹� ���α���, ü�¹� ���α���
HRESULT player::init()
{
	//_strkey = strKey;							//�̹��� Ű��
	//_currentHP = currentHP;					//ü��
	//_maxHP = maxHP;							//ü��
	//_width = width;							//ü�¹� ����
	//_height = height;							//ü�¹� ����
	//_x = x;									//�÷��̾� ��ǥ (left)
	//_y = y;									//�÷��̾� ��ǥ (top)

	_x = 200;
	_y = WINSIZEY / 2;

	_speed = 3.5f;							//�÷��̾� �̵��ӵ�
	_gravity = 0.0f;						//�߷�
	
	_dir = RIGHT;							//�÷��̾� �ʱ� ����
	_state = PLAYER_IDLE;					//�÷��̾� �ʱ� ����

	_jumpPower = 0;							//�÷��̾� ������
	_jumpTime = 0;							//�÷��̾� �����ð�
	_jumpCount = 0;							//�÷��̾� ���� Ƚ��
	_isJump = false;						//�÷��̾� ���� �ߴ�?
	_isLeft = false;						//�÷��̾� �������� �̵��޴�?
	_isRight = false;						//�÷��̾� ���������� �̵��޴�?

	_currentFrameX = 0;						//�÷��̾� ������
	_currentFrameY = 0;						//�÷��̾� ������
	_frame = 0;								//�÷��̾� ������

	//��Ʈ
	//_rc = RectMake(x, y, _player->getFrameWidth(), _player->getFrameHeight());

	//�÷��̾� �̹���
	//_player = IMAGEMANAGER->findImage(imageName);

	//�÷��̾� ü�¹� (ü�¹� Ű��, ü�¹� ��ġ, ü�¹� ����)
	_hpBar = new progressBar;
	_hpBar->init(_strkey, _rc.left, _rc.bottom, _width, _height);
	_hpBar->setGauge(_currentHP, _maxHP);

	return S_OK;
}

void player::release()
{

}

void player::update()
{
	//�������� ������
	_frame++;					//������ ī��Ʈ

	if (_frame % 5 == 0)
	{
		if (_currentFrameX >= _player->getMaxFrameX())
		{
			_currentFrameX = 0;
		}

		_player->setFrameX(_currentFrameX);
		_currentFrameX++;

		_frame = 0;
	}

	_hpBar->setX(_rc.left);					//�÷��̾� �Ʒ����ٰ� ü�¹� �׷��ֱ�
	_hpBar->setY(_rc.bottom);				//�÷��̾� �Ʒ����ٰ� ü�¹� �׷��ֱ�
	_hpBar->setGauge(_currentHP, _maxHP);	//�÷��̾� �Ʒ����ٰ� ü�¹� �׷��ֱ�
	_hpBar->update();						//�÷��̾� �Ʒ����ٰ� ü�¹� �׷��ֱ�
	
	playerAtk();							//�÷��̾� �⺻���� �Լ�
	playerMove();							//�÷��̾� ������ �Լ�					
}

void player::render()
{
	playerDraw();							//�׷��ִ� �Լ�
}

//���� �Լ�
void player::playerAtk()
{

}

//������ �Լ�
void player::playerMove()
{
	//�÷��̾� ���� �̵�
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_dir = LEFT;
		_state = PLAYER_LEFT;

		_isLeft = true;
	}
	if (_isLeft == true)
	{
		_x -= _speed;
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_state = PLAYER_IDLE;
	}
	
	//�÷��̾� ������ �̵�
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_dir = RIGHT;
		_state = PLAYER_RIGHT;

		_isRight = true;
	}
	if (_isRight == true)
	{
		_x += _speed;
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_state = PLAYER_IDLE;
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_state = PLAYER_IDLE;
	}

	//����
	if (_isJump)
	{
		_state = PLAYER_JUMP;

		_y -= _jumpPower;

		_jumpPower -= _gravity;
	}

	//�÷��̾� ����
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (_jumpCount == 0)
		{
			_isJump = true;
			_jumpPower = 6.0f;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_SPACE))
	{
		_gravity = 0.3f;
	}

}


//�׷��ִ� �Լ�
void player::playerDraw()
{
	//�÷��̾� �׷��ֱ�
	_player->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);

	//ü�¹� �׷��ֱ�
	_hpBar->render();

	//switch (_state)
	//{
	//	case PLAYER_RIGHT:
	//		
	//	break;
	//	
	//	case PLAYER_LEFT:
	//	
	//	break;
	//	
	//	case PLAYER_JUMP:
	//	
	//	break;
	//	
	//	case PLAYER_IDLE:
	//	
	//	break;
	//}
}
