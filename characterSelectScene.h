#pragma once
#include "gameNode.h"

class characterSelectScene : public gameNode
{
private:
	//처음 배경 등장할때 사용할 알파값 255되면 멈춞
	int _alpha;



	int _selectUnit; //지금 고른 유닛을 전달해줄변수

	int _indexCount; //프레임 속도조절해줄 인덱스 카운트

	int _zeroIndex; //프레임 번호 조절해줄 인덱스 제로용
	int _rockManIndex; //프레임 번호 조절해줄 인덱스 록맨용

	bool _isStart;

public:
	characterSelectScene();
	~characterSelectScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void charactorInput();
	void sceneChange();

	void selectUnitFrame();//선택시 프레임 가동할 함수

};