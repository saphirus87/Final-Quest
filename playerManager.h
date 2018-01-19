#pragma once
#include "gameNode.h"
#include "progressBar.h"

class playerManager : public gameNode
{
protected:
	progressBar* _hpBar;

	image* _player;				//�÷��̾� �̹���
	RECT _rc;					//�÷��̾� ��Ʈ

	float _x, _y;				//�÷��̾� ��ǥ (left, top)

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
	HRESULT init(const char* imageName, string strKey, float x, float y, float currentHP, float maxHP, float width, float height);
	void release();
	void update();
	void render();

	void playerMove();		//������ �Լ�
	void playerDraw();		//�׷��ִ� �Լ�

	playerManager();
	~playerManager();
};

