#pragma once
#include "gameNode.h"
#include "bullets.h"

class ship : public gameNode
{
protected:
	//GDIPLUS <-- 3장 이상 뿌리면 급격하게 느려짐
	image* _image;
	RECT _rc;
	float _x, _y;
	float _angle;
	float _speed;
	float _radius;

	//기본 총알은 모든 함선들이 보유할 수 있다
	bullet* _bullet;

public:
	ship();
	~ship();

	virtual HRESULT init(const char* imageName, int x, int y);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	virtual void draw(void);
	virtual void keyControl(void);
	virtual void move(void);

	virtual void bulletFire(void);
	virtual void bulletMove(void);
	virtual void bulletDraw(void);


};

