#pragma once
#include "gameNode.h"
#include "progressBar.h"

class player : public gameNode
{
protected:
	progressBar* _hpBar;		//�÷��̾� ü��

	image* _player;				//�÷��̾� �̹���
	RECT _rc;					//�÷��̾� ��Ʈ

	float _x, _y;				//�÷��̾� ��ǥ (left, top)
	float _speed;				//�÷��̾� �̵��ӵ�
	float _gravity;				//�߷�

	float _jumpPower;			//�÷��̾� ������
	int   _jumpTime;			//�÷��̾� �����ð�
	int   _jumpCount;			//�÷��̾� ���� Ƚ��
	bool  _isJump;				//�÷��̾� ���� �ߴ�?
	

	//�÷��̾� ������ �̹����� ���� ����
	int _currentFrameX;
	int _currentFrameY;
	int _frame;
	/////////////////////////////////

	//�÷��̾� ü�� or ü�¹� ����
	float _currentHP, _maxHP;	//�÷��̾� ü��
	float _width, _height;		//�÷��̾� ü�¹� ����
	string _strkey;				//ü�¹� Ű��
	/////////////////////////////////


	//�浹 �˰���(�ȼ�), �����ӷ���
	//��ǥ : Left Top
	//WINDOW_SIZE 1280 X 720

public:
	//				�̹��� Ű��        , �̹��� ����   , ��Ʈ��ǥ x,y    ,               ü��           , ü�¹� ���α���, ü�¹� ���α���
	HRESULT init(const char* imageName, string strKey, float x, float y, float currentHP, float maxHP, float width, float height);
	void release();
	void update();
	void render();

	void playerAtk();		//���� �Լ�
	void playerMove();		//������ �Լ�
	void playerDraw();		//�׷��ִ� �Լ�

	player();
	~player();
};

