#pragma once
#include "gameNode.h"
#include "gameStartScene.h"
#include "characterSelectScene.h"
#include "gameScene.h"

class playGround : public gameNode
{
private:
	
	gameNode* _start;	//��ŸƮ ��
	gameNode* _select;	//����Ʈ ��
	gameNode* _mainGame; //���� ��

public:
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�



	playGround();
	~playGround();
};

