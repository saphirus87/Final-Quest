#include "stdafx.h"
#include "soundManager.h"


soundManager::soundManager()
{
}


soundManager::~soundManager()
{

}

HRESULT soundManager::init()
{
	//FMOD 사운드엔진 사용하려면 초기화
	System_Create(&_system);

	_system->init(TOTALSOUNDBUFFER, FMOD_INIT_NORMAL, NULL);

	_sound = new Sound*[TOTALSOUNDBUFFER];
	_channel = new Channel*[TOTALSOUNDBUFFER];

	ZeroMemory(_sound, sizeof(_sound));
	ZeroMemory(_channel, sizeof(_channel));


	_maxCount = 0;
	_currentPitch = 1.0f;
	_currentPan = 0;


	//로우패스 필터
	_system->createDSPByType(FMOD_DSP_TYPE_LOWPASS, &dspLowPass);
	//하이패스필터
	_system->createDSPByType(FMOD_DSP_TYPE_HIGHPASS, &dspHighPass);
	// 플랜지 필터
	_system->createDSPByType(FMOD_DSP_TYPE_FLANGE, &dspFlange);
	// 에코 필터
	_system->createDSPByType(FMOD_DSP_TYPE_ECHO, &dspEcho);


	//실험을 시작한다.
	_system->createDSPByType(FMOD_DSP_TYPE_OSCILLATOR, &_dsp);


	//마스터그룹 추가된 모든 음악을 조절가능
	_system->getMasterChannelGroup(&_masterGroup);

	//마스터사운드그룹 추가
	_system->getMasterSoundGroup(&_masterSound);

	//이펙트 사운드 그룹
	_system->createChannelGroup("channelEffect", &_effectGroup);
	//BGM 노래 그룹
	_system->createChannelGroup("channelMusic", &_musicGroup);
	
	_system->createSoundGroup("soundMusic", &_musicSound);

	
	//주파수~~~
	_system->createGeometry(1, 3, &_geometry);


	//DSP영역 초기화
	addDspLowPass();
	addDspHighPass();
	addDspFlange();
	addDspEcho();
	ocil = 0;
	return S_OK;

}

void soundManager::release()
{
	if (*_channel != NULL || *_sound != NULL)
	{
		for (int i = 0; i < TOTALSOUNDBUFFER; ++i)
		{
			if (_channel != NULL)
			{
				if (_channel[i])_channel[i]->stop();
			}
			if (_sound != NULL)
			{
				if (_sound[i] != NULL) _sound[i]->release();
			}
		}
	}

	//메모리 지워준다
	//배열이므로
	SAFE_DELETE(_channel);
	SAFE_DELETE(_sound);

	//마지막으로 FMOD 사운드 시스템 닫아줌
	if (_system != NULL)
	{
		_system->release();
		_system->close();		//셧더 내립니다
	}
}

void soundManager::update()	
{
	_system->update();
}



//사운드 추가 함수
void soundManager::addSound(string keyName, string soundName, bool bgm, bool loop)
{
	if (loop)
	{
		if (bgm)
		{ 
			_system->createStream(soundName.c_str(), FMOD_LOOP_NORMAL, NULL, &_sound[_mTotalSounds.size()]);
		}
		else
		{
			_system->createSound(soundName.c_str(), FMOD_LOOP_NORMAL , NULL, &_sound[_mTotalSounds.size()]);
		}
		_maxCount++;
	}
	else
	{
		if (bgm)
		{
			_system->createStream(soundName.c_str(), FMOD_DEFAULT , NULL, &_sound[_mTotalSounds.size()]);
		}
		else
		{
			_system->createSound(soundName.c_str(), FMOD_DEFAULT , NULL, &_sound[_mTotalSounds.size()]);
		}
		_maxCount++;
	}

	_mTotalSounds.insert(make_pair(keyName, &_sound[_mTotalSounds.size()]));

}


// 1.0 maximum 0.0 ~ 1.0 -> 0 ~ 255
void soundManager::play(string keyName, float volume)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	//배열 의 몇번째인지 세알리기위한 카운트 변수
	int count = 0;
	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_system->playSound(_sound[count],0, false, &_channel[count]);
			_channel[count]->setLoopPoints(0, FMOD_TIMEUNIT_MS, 0, FMOD_TIMEUNIT_MS);

			_channel[count]->setVolume(volume);
			
			break;
		}
	}
}


void soundManager::stop(string keyName)				 
{
	arrSoundsIter iter = _mTotalSounds.begin();
	//배열 의 몇번째인지 세알리기위한 카운트 변수
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->stop();
			break;
		}
	}
}




void soundManager::pause(string keyName)			 
{
	arrSoundsIter iter = _mTotalSounds.begin();
	//배열 의 몇번째인지 세알리기위한 카운트 변수
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPaused(true);
			break;
		}
	}
}

void soundManager::resume(string keyName)			 
{
	arrSoundsIter iter = _mTotalSounds.begin();
	//배열 의 몇번째인지 세알리기위한 카운트 변수
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPaused(false);
			break;
		}
	}
}


bool soundManager::isPlaySound(string keyName) 
{
	bool isPlay;

	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->isPlaying(&isPlay);
			break;
		}
	}

	return isPlay;
}

bool soundManager::isPauseSound(string keyName)
{
	bool isPause;

	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->getPaused(&isPause);
			break;
		}
	}

	return isPause;
}

//준우의 사운드매니저!!!!!!!!!!!!!!!!!!!!!!!!!!!!//준우의 사운드매니저!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//채널 뮤직그룹에 추가
void soundManager::addMusicGroup(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_channel[count]->setChannelGroup(_musicGroup);
	break;
		}
	}
}

//채널 이펙트그룹에 추가
void soundManager::addEffectGroup(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_channel[count]->setChannelGroup(_effectGroup);
	break;
		}
	}
}


//음악 길이구해오기 //MS단위
int soundManager::getLengh(string keyName)// 길이구해오기
{
	arrSoundsIter iter = _mTotalSounds.begin();
	unsigned int _musicLenght;
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_sound[count]->getLength(&_musicLenght, FMOD_TIMEUNIT_MS);
	break;
		}
	}
	return _musicLenght;
}


//현재 재생 위치 구해오기
int soundManager::getPosition(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;
	unsigned int _musicLenght;
	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_channel[count]->getPosition(&_musicLenght, FMOD_TIMEUNIT_MS);
	break;
		}
	}
	return _musicLenght;
}


//재생 위치 설정 //MS단위
void soundManager::setPosition(string keyName, int position)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;
	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_channel[count]->setPosition(position, FMOD_TIMEUNIT_MS);
	break;
		}
	}
}


//마스터볼륨 -- 전체적 볼륨을 조절한다
//채널의 볼륨얻어오기
float soundManager::getVolume(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;
	float volume;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_masterGroup->getVolume(&volume);
	break;
		}
	}
	return volume;
}

//채널의 볼륨설정하기
void soundManager::setVolume(string keyName, float volume)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_channel[count]->setVolume(volume);
	break;
		}
	}
}





// 타이틀을 얻어서 string형태로 반환
string soundManager::getTagTitle(string keyName)
{
	const int fileName = 255;
	char tag[fileName] = { 0 };
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_sound[count]->getTag("TITLE", 0, &Ftag);
	break;
		}
	}
	return (char*)Ftag.data;
}

// 작곡가를 얻어서 string형태로 반환
string soundManager::getTagArtist(string keyName)
{
	const int fileName = 255;
	char tag[fileName] = { 0 };
	
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_sound[count]->getTag("ARTIST", 0, &Ftag);
	break;
		}
	}

	return (char*)Ftag.data;
}




///////////***************///////////////
///////////***************///////////////
///////////**** 팬설정 ****///////////////
///////////***************///////////////
//-1 ~ 0 ~ 1 로 왼쪽부터 오른쪽까지의 좌우음향설정
void soundManager::setPan(string keyName, float panValue)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_channel[count]->setPan(panValue);
		break;
		}
	}
}

//오른쪽으로 한칸씩 
void soundManager::rightPan(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_currentPan += 0.05;
	_masterGroup->setPan(_currentPan);
	break;
		}
	}
}


//왼쪽으로 한칸씩 팬설정
void soundManager::leftPan(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_currentPan -= 0.05;
	_masterGroup->setPan(_currentPan);
	break;
		}
	}
}




void soundManager::ssss(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_masterGroup->setReverbProperties(2, 0.5);
	_channel[count]->setPriority(1);
	break;
		}
	}
}





// 곡의 노래 음역을 높여준다// 당연한건데 이거 하면 스피드도 동시에 증가
void soundManager::picthUp(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_currentPitch += 0.01;
	_channel[count]->setPitch(_currentPitch);
		break;
		}
	}
}

//곡의 노래 음역을 내려준다// 스피드도 동시에 다운
void soundManager::picthDown(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_currentPitch -= 0.01;
	_channel[count]->setPitch(_currentPitch);
	break;
		}
	}
}

//현재 주파수를 얻어온후 주파수의 진동수를 700 낮춤
void soundManager::downFrequency(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_channel[count]->getFrequency(&_frequency);
	_frequency -= 700;
	_channel[count]->setFrequency(_frequency);
	break;
		}
	}
}

//현재 주파수를 얻어온후 주파수의 진동수를 500정도 높임
void soundManager::upFrequency(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_channel[count]->getFrequency(&_frequency);
	_frequency += 700;
	_channel[count]->setFrequency(_frequency);
	break;
		}
	}
}

//현재 주파수를 얻어온후 주파수의 진동수를 speed의 배수로 곱한다.
//진동수가 빨라질수록 곡의 길이는 짧아지고 재생속도는 빨라진다.
void soundManager::multipleFrequency(string keyName, float speed)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_channel[count]->getFrequency(&_frequency);
	_frequency *= speed;
	_channel[count]->setFrequency(_frequency);

	break;
		}
	}
}


//FMod를 사용하여 반사음의 효과를 넣을 수 있음
//네크로댄서 상인아저씨 방에 들어갔을시 넣으면 좋을듯
//또는 네크로댄서 상인아저씨 방에 들어가기전에 이 효과를 넣고나서
//highPass를 넣으면 높은 주파수만 도착하는 현상과 반사음의 효과로
//멀리서 듣는 효과를 실현가능할꺼같은데 실행해본적없는 이론의 이야기 그냥 소리줄이고 쓰면 될듯
void soundManager::reverbOn(string keyName)
{
	FMOD_REVERB_PROPERTIES propOn = FMOD_PRESET_CONCERTHALL;

	_system->setReverbProperties(0, &propOn);
}
void soundManager::reverbOff(string keyName)
{
	FMOD_REVERB_PROPERTIES propOff = FMOD_PRESET_OFF;

	_system->setReverbProperties(0, &propOff);
}


//어우 귀갱 추천안함 이건 test4에 있는 주파수를 조정해주는 기능 이 byPass가 false가 되는 순간 ㄷㄷ
//정확히 주파수를 조절한다기보다는 oscillator라는것의 주파수의 파라미터 값을 설정해주는 값 진심 비추
void soundManager::test3(string keyName)
{
	_dsp->setParameterFloat(FMOD_DSP_OSCILLATOR_RATE, 100.0f);
	_dsp->setBypass(true);
}

//진짜 이거야말로 씹 귀갱
//주파수의 모양을 선택해서 듣는 dsp기능
//그러나 그 주파수는 그야말로 귀갱이여서 주파수는 충분히 떨어뜨린 100정도에서 들을것 44100HZ는 들을게 못됨
//주의 진짜 건들지 말 것 사용하기 힘든 것이기에
void soundManager::test4(string keyName)
{
	ocil++;
	if (ocil >= 6) ocil = 0;
	_dsp->setParameterInt(FMOD_DSP_OSCILLATOR_TYPE, ocil);
	_system->playDSP(_dsp, _masterGroup, false, &_channel[3]);
}



// dsp장난치기


//저음역 주파수만 통과
void soundManager::addDspLowPass()
{
	_masterGroup->addDSP(0, dspLowPass);
	dspLowPass->setBypass(true);
}

//고음역 주파수만 통과
void soundManager::addDspHighPass()
{
	_masterGroup->addDSP(0, dspHighPass);
	dspHighPass->setBypass(true);
}

//dsp에 플랜지효과를 넣음
void soundManager::addDspFlange()
{
	_masterGroup->addDSP(0, dspFlange);
	dspFlange->setBypass(true);
}

//dsp에 에코효과를 넣음
void soundManager::addDspEcho()
{
	_masterGroup->addDSP(0, dspEcho);
	dspEcho->setBypass(true);
}




//리버스함수들은 토글방식으로 위에서 추가한 dsp효과들을
//껏다켰다 가능 false일때가 On 
//true일때가 off
void soundManager::reverseLowPass(bool byPass)
{
	dspLowPass->setBypass(byPass);
}
void soundManager::reverseHighPass(bool byPass)
{

	dspHighPass->setBypass(byPass);
}
void soundManager::reverseaddDspFlange(bool byPass)
{

	dspFlange->setBypass(byPass);
}
void soundManager::reverseaddEcho(bool byPass)
{
	dspEcho->setBypass(byPass);
}

