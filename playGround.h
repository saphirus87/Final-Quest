#pragma once
#include "gameNode.h"
#include "starcraftScene.h"
#include "selectScene.h"

class playGround : public gameNode
{
private:
	
	gameNode* _select;
	

public:
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�



	playGround();
	~playGround();
};

