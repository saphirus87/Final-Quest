#pragma once
#include "singletonBase.h"
#include <map>

#include "inc/fmod.hpp"	//fmod.hpp파일 인클루드
#pragma comment(lib, "lib/fmod64_vc.lib")	//라이브러리 파일 등록

using namespace FMOD;

#define SOUNDBUFFER 10
#define EXTRACHANNELBUFFER 5

#define TOTALSOUNDBUFFER SOUNDBUFFER + EXTRACHANNELBUFFER

class soundManager : public singletonBase<soundManager>
{
private:
	typedef map<string, Sound**>				arrSounds;
	typedef map<string, Sound**>::iterator		arrSoundsIter;
	typedef map<string, Channel**>				arrChannels;
	typedef map<string, Channel**>::iterator	arrChannelsIter;

	FMOD_TAG Ftag;
	float _currentPitch, _currentPan;

private:
	System*			_system;
	
	Sound**			_sound;
	SoundGroup*		_masterSound;
	SoundGroup*		_musicSound;

	Channel**		_channel;
	ChannelGroup*	_musicGroup;  //노래 그룹
	ChannelGroup*	_effectGroup; //이펙트 그룹조절용
	ChannelGroup*   _masterGroup; //전체적 조절

	FMOD_RESULT     result;
	Geometry*		_geometry;
	DSP				*dspLowPass = 0;  //낮은음역
	DSP				*dspHighPass = 0; //높은음역
	DSP		   	    *dspEcho = 0;     //반사음역
	DSP			    *dspFlange = 0;   //솔까모르겠다 차이를
	DSP				*_dsp = 0;

	FMOD_VECTOR     _vector;//새로운 길로...
	int _polyIndex;

	int _maxCount;
	int ocil;
	float _frequency;
	float _bpm;
	arrSounds _mTotalSounds;

public:
	soundManager();
	~soundManager();

	HRESULT init();
	void release();
	void update();

	//사운드 추가 함수
	void addSound(string keyName, string soundName, bool bgm, bool loop);




	// 1.0 maximum 0.0 ~ 1.0 -> 0 ~ 255
	void play(string keyName, float volume = 1.0f);

	void stop(string keyName);

	void pause(string keyName);
	void resume(string keyName);



	bool isPlaySound(string keyName);
	bool isPauseSound(string keyName);
	
	
	void play(int count, float volume = 1.0f);
	void stop(int count);
	void pause(int count);
	void resume(int count);
	
	
	bool isPlaySound(int count);
	bool isPauseSound(int count);
	int getMaxCount() { return _maxCount; }



	void addMusicGroup(int count);
	void addEffectGroup(int count);

	//재생길이 관련 
	int getPosition(int count);
	void setPosition(int count, int position);
	int getLengh(int count);
	
	//이름얻기
	string getTagTitle(int count);
	string getTagArtist(int count);
	
	//볼륨관련
	float getVolume(int count);
	void setVolume(int count,float volume);

	
	




	//팬조절 //팬이란 스피커 좌우 음향의 치우침 조절기능
	void leftPan(int count); //왼쪽으로 0.5
	void rightPan(int count); //오른쪽으로 0.5
	void setPan(int count, float panValue);  // 자신이 조절 -1~1까지였나

	void addDspLowPass();
	void addDspHighPass();
	void addDspFlange();
	void addDspEcho();

	void reverseLowPass(bool byPass);
	void reverseHighPass(bool byPass);
	void reverseaddDspFlange(bool byPass);
	void reverseaddEcho(bool byPass);


	//반사음 
	void reverbOn(int count);
	void reverbOff(int count);

	//주파수대역
	void downFrequency(int count);//주파수 다운
	void upFrequency(int count);//주파수 업
	void multipleFrequency(int count, float multiple); // 주파수 배율
	//음역 조절
	void picthUp(int count);
	void picthDown(int count);

	
	//bpm
	void setBpm(float bpm);
	float getBpm() { return _bpm; };
	
	
	
	void test3(int count);
	void test4(int count);

	void ssss(int count);
};

