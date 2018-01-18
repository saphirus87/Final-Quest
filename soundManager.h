#pragma once
#include "singletonBase.h"
#include <map>

#include "inc/fmod.hpp"	//fmod.hpp���� ��Ŭ���
#pragma comment(lib, "lib/fmod64_vc.lib")	//���̺귯�� ���� ���

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
	ChannelGroup*	_musicGroup;  //�뷡 �׷�
	ChannelGroup*	_effectGroup; //����Ʈ �׷�������
	ChannelGroup*   _masterGroup; //��ü�� ����

	FMOD_RESULT     result;
	Geometry*		_geometry;
	DSP				*dspLowPass = 0;  //��������
	DSP				*dspHighPass = 0; //��������
	DSP		   	    *dspEcho = 0;     //�ݻ�����
	DSP			    *dspFlange = 0;   //�ֱ�𸣰ڴ� ���̸�
	DSP				*_dsp = 0;

	FMOD_VECTOR     _vector;//���ο� ���...
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

	//���� �߰� �Լ�
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

	//������� ���� 
	int getPosition(int count);
	void setPosition(int count, int position);
	int getLengh(int count);
	
	//�̸����
	string getTagTitle(int count);
	string getTagArtist(int count);
	
	//��������
	float getVolume(int count);
	void setVolume(int count,float volume);

	
	




	//������ //���̶� ����Ŀ �¿� ������ ġ��ħ �������
	void leftPan(int count); //�������� 0.5
	void rightPan(int count); //���������� 0.5
	void setPan(int count, float panValue);  // �ڽ��� ���� -1~1��������

	void addDspLowPass();
	void addDspHighPass();
	void addDspFlange();
	void addDspEcho();

	void reverseLowPass(bool byPass);
	void reverseHighPass(bool byPass);
	void reverseaddDspFlange(bool byPass);
	void reverseaddEcho(bool byPass);


	//�ݻ��� 
	void reverbOn(int count);
	void reverbOff(int count);

	//���ļ��뿪
	void downFrequency(int count);//���ļ� �ٿ�
	void upFrequency(int count);//���ļ� ��
	void multipleFrequency(int count, float multiple); // ���ļ� ����
	//���� ����
	void picthUp(int count);
	void picthDown(int count);

	
	//bpm
	void setBpm(float bpm);
	float getBpm() { return _bpm; };
	
	
	
	void test3(int count);
	void test4(int count);

	void ssss(int count);
};

