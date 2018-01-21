#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{

}

HRESULT progressBar::init(string strKey, int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	//_progressBarTop = new image;
	//_progressBarTop->init(".\\bmps\\hpBarTop.bmp", (float)x, (float)y, width, height, true, RGB(255, 0, 255));
	//
	//_progressBarBottom = new image;
	//_progressBarBottom->init(".\\bmps\\hpBarBottom.bmp", (float)x, (float)y, width, height, true, RGB(255, 0, 255));

	_strKey = strKey;
	_progressBarTop = IMAGEMANAGER->addImage(strKey + "frontBar", "\Image\\hpBarTop.bmp", x, y, width, height, true, RGB(255, 0, 255));

	_progressBarBottom = IMAGEMANAGER->addImage(strKey + "backBar", "\Image\\hpBarBottom.bmp", x, y, width, height, true, RGB(255, 0, 255));

	//설정된 가로크기로!
	_width = _progressBarTop->getWidth();

	return S_OK;
}

void progressBar::release()
{
}

void progressBar::update()
{
	_rcProgress = RectMakeCenter(_x, _y, _progressBarTop->getWidth(), _progressBarTop->getHeight());
}

void progressBar::render()									  
{
	IMAGEMANAGER->render(_strKey + "backBar", getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());
	
	IMAGEMANAGER->render(_strKey + "frontBar", getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 0, 0,
		_width, _progressBarBottom->getHeight());

	//_progressBarBottom->render(getMemDC(),
	//	_rcProgress.left + _progressBarBottom->getWidth() / 2,
	//	_y + _progressBarBottom->getHeight() / 2, 0, 0,
	//	_progressBarBottom->getWidth(), _progressBarBottom->getHeight());
	//
	//_progressBarTop->render(getMemDC(),
	//	_rcProgress.left + _progressBarBottom->getWidth() / 2,
	//	_y + _progressBarBottom->getHeight() / 2, 0, 0,
	//	_width, _progressBarBottom->getHeight());

}

void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();
}
