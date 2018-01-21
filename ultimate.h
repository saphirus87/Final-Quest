#pragma once
#include "player.h"
#include <vector>
enum ULTIMATESTATE
{
	ULTIMATE_SKILL,
	ULTIMATE_AT,
	ULTIMATE_LEFT,
	ULTIMATE_RIGHT,
	ULTIMATE_NONE
};
struct GUN
{
	image* img;
	RECT rc_gun;
	int x, y;
	float angle;
};
class ultimate : public player
{
private:
	GUN gun;
	vector<GUN>				vGun;
	vector<GUN>::iterator	viGun;
	int count;
	bool isAttack;
	int stay_count;
	int move_count;
	int skill_count;
	int atk_count;
	ULTIMATESTATE ultimate_state;

public:
	ultimate();
	~ultimate();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	//업데이트
	void jump();
	void move();
	void frameUpdate();

	//총알
	void bullet_fire();
	void bullet_move();
};

