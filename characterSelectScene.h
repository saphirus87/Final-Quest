#pragma once
#include "gameNode.h"

class characterSelectScene : public gameNode
{
private:
	//ó�� ��� �����Ҷ� ����� ���İ� 255�Ǹ� �حy
	int _alpha;



	int _selectUnit; //���� �� ������ �������ٺ���

	int _indexCount; //������ �ӵ��������� �ε��� ī��Ʈ

	int _zeroIndex; //������ ��ȣ �������� �ε��� ���ο�
	int _rockManIndex; //������ ��ȣ �������� �ε��� �ϸǿ�

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

	void selectUnitFrame();//���ý� ������ ������ �Լ�

};