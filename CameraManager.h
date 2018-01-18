#pragma once
#include "singletonBase.h"
#include "image.h"
#include <map>

class CameraManager : public singletonBase<CameraManager>
{
private:
	typedef map<string, image*>				mapImageList;
	typedef map<string, image*>::iterator	mapImageIter;

private:
	mapImageList _mImageList;

public:
	CameraManager();
	~CameraManager();

	HRESULT init();

	//이미지 릴리즈
	void release(void);

	image* addImage(string strKey, int width, int height);
	image* addImage(string strKey, const char* fileName, int width, int height, bool trans, COLORREF transColor);
	image* addImage(string strKey, const char* fileName, float x, float y, int width, int height, bool trans, COLORREF transColor);

	image* findImage(string strKey);

	BOOL deleteImage(string strKey);


	BOOL deleteAll(void);
};

