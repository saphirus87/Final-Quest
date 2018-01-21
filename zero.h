#pragma once
#include "player.h"
#include <vector>

enum ZERO_STATE
{
	ZERO_AT1,
	ZERO_HIT,
	ZERO_SKILL,
	ZERO_LEFT,
	ZERO_RIGHT,
	ZERO_NONE

};
struct ATTACK
{
	RECT arc;
	int x, y;
};
class zero : public player
{
private:
	ATTACK att;
	vector<ATTACK> vAtk;
	vector<ATTACK>::iterator viAtk;

	ZERO_STATE zero_state;
	int atk_combo;
	int count;
	int move_count;
	int at1_count;
	int at2_count;
	float at3_count;
	float startCount, endCount;
public:
	zero();
	~zero();

	HRESULT init();
	void release();
	void update();
	void render();

	void frameUpdate();
	void move();
	void zero_atk1();
	void zero_atk2();
	void zero_atk3();
	void jump();
};

