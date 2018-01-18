#include "stdafx.h"
#include "CameraManager.h"

//컴파일러 지시기 나는 마소이미지(32비트) 라이브러리를 사용하겠다
#pragma comment(lib, "msimg32.lib")


CameraManager::CameraManager()
{
}


CameraManager::~CameraManager()
{
}

HRESULT CameraManager::init()
{

	return S_OK;
}


//이미지 릴리즈
void CameraManager::release(void)
{
	deleteAll();
}

BOOL CameraManager::deleteAll(void)
{
	mapImageIter iter = _mImageList.begin();

	for (; iter != _mImageList.end();)
	{
		//이미지 정보가 있다!
		if (iter->second != NULL)
		{
			SAFE_DELETE(iter->second);
			iter = _mImageList.erase(iter);
		}
		else ++iter;
	}

	_mImageList.clear();

	return TRUE;
}

image* CameraManager::addImage(string strKey, int width, int height)
{
	image* img = findImage(strKey);

	//이미지가 이미 있다면 그 이미지를 반환
	if (img) return img;
	//그게 아니라면 프로세스가 여기까지 내려왔을 것.!
	img = new image;

	if (FAILED(img->init(width, height, true, RGB(255, 0, 255))))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* CameraManager::addImage(string strKey, const char* fileName, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//이미지가 이미 있다면 그 이미지를 반환
	if (img) return img;
	//그게 아니라면 프로세스가 여기까지 내려왔을 것.!
	img = new image;

	if (FAILED(img->init(fileName, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* CameraManager::addImage(string strKey, const char* fileName, float x, float y, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//이미지가 이미 있다면 그 이미지를 반환
	if (img) return img;
	//그게 아니라면 프로세스가 여기까지 내려왔을 것.!
	img = new image;

	if (FAILED(img->init(fileName, x, y, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}


image* CameraManager::findImage(string strKey)
{
	mapImageIter key = _mImageList.find(strKey);

	//찾았다
	if (key != _mImageList.end())
	{
		return key->second;
	}

	return NULL;
}


BOOL CameraManager::deleteImage(string strKey)
{
	mapImageIter key = _mImageList.find(strKey);

	//지울 이미지를 발견
	if (key != _mImageList.end())
	{
		key->second->release();
		SAFE_DELETE(key->second);
		_mImageList.erase(key);

		return true;
	}

	return false;
}
