#pragma once
#include "player.h"
enum ULTIMATESTATE
{
	ULTIMATE_SKILL,
	ULTIMATE_AT,
};
class ultimate : public player
{
private:
	ULTIMATESTATE ultimate_state;

public:
	ultimate();
	~ultimate();

	HRESULT init(const char* imageName, float x, float y, float currentHP, float maxHP, float width, float height);
	void release();
	void update();
	void render();

	//������Ʈ
	void jump();
	void move();
	void frameUpdate();

	//�Ѿ�
	void bullet_fire();
	void bullet_move();
};

