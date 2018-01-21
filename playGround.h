#pragma once
#include "gameNode.h"
#include "gameStartScene.h"
#include "characterSelectScene.h"
#include "gameScene.h"

class playGround : public gameNode
{
private:
	
	gameNode* _start;	//스타트 씬
	gameNode* _select;	//셀렉트 씬
	gameNode* _mainGame; //메인 씬

public:
	virtual HRESULT init(void);		//초기화 함수
	virtual void release(void);		//메모리 관련 해제
	virtual void update(void);		//업데이트(연산)
	virtual void render(void);		//그려주는 함수



	playGround();
	~playGround();
};

