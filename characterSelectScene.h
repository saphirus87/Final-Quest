#pragma once
#include "gameNode.h"

class characterSelectScene : public gameNode
{
private:
	//Ã³À½ ¹è°æ µîÀåÇÒ¶§ »ç¿ëÇÒ ¾ËÆÄ°ª 255µÇ¸é ¸Ø­y
	int _alpha;



	int _selectUnit; //Áö±İ °í¸¥ À¯´ÖÀ» Àü´ŞÇØÁÙº¯¼ö

	int _indexCount; //ÇÁ·¹ÀÓ ¼ÓµµÁ¶ÀıÇØÁÙ ÀÎµ¦½º Ä«¿îÆ®

	int _zeroIndex; //ÇÁ·¹ÀÓ ¹øÈ£ Á¶ÀıÇØÁÙ ÀÎµ¦½º Á¦·Î¿ë
	int _rockManIndex; //ÇÁ·¹ÀÓ ¹øÈ£ Á¶ÀıÇØÁÙ ÀÎµ¦½º ·Ï¸Ç¿ë

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

	void selectUnitFrame();//¼±ÅÃ½Ã ÇÁ·¹ÀÓ °¡µ¿ÇÒ ÇÔ¼ö

};