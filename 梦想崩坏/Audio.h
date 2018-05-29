#pragma once
#pragma once
#pragma once
#ifndef _AUDIO_MANAGER_H_
#define _AUDIO_MANAGER_H_

#include <string>
#include <map>
#include "fmod.h" //FMOD是一款跨平台的音频引擎
#define Audio_Music CAudioManager

class CAudioManager
{
private:
	//循环音频对象
	struct _LOOPAUDIO
	{
		//声音流
		FSOUND_STREAM* _s; //音频流

						   //声道
		int _c;
		int Lenth;
		//功能:构造
		_LOOPAUDIO()
			:
			_s(0),
			_c(-1)
		{}
	};
	std::string m_PlayingLoopAudio; //正在播放的循环音乐
	int m_MaxChannel; //声道上限
	int m_LoopVolume; //循环音乐音量(0~255)
	int m_OnceVolume; //非循环音乐音量(0~255)
	int m_State;
	

public:
	std::map<std::string, _LOOPAUDIO> m_LoopAudio; //循环音乐集合
	std::map<std::string, _LOOPAUDIO> m_OnceAudio; //非循环音乐集合
	//功能:构造
	//参数1:初始循环音频音量(背景音乐)
	//参数2:初始非循环音频音量(音效)
	//参数3:声道上限
	CAudioManager(int InitLoopVolume = 127, int InitOnceVolume = 127, int MaxChannel = 32);

	//功能:析构
	virtual ~CAudioManager();

	//功能:加载循环音乐
	//参数1:循环音乐ID
	//参数2:循环音乐文件路径
	//返回:true为成功,false为失败
	bool PushLoopAudio(const char* Key, const char* AudioPath);

	//功能:加载非循环音乐
	//参数1:非循环音乐ID
	//参数2:非循环音乐文件路径
	//返回:true为成功,false为失败
	bool PushOnceAudio(const char* Key, const char* AudioPath);

	//功能:释放循环音乐
	//参数1:循环音乐ID
	//返回:true为成功,false为失败
	bool ReleaseLoopAudio(const char* Key);

	//功能:释放非循环音乐
	//参数1:非循环音乐ID
	//返回:true为成功,false为失败
	bool ReleaseOnceAudio(const char* Key);

	//功能:播放循环音乐
	//参数1:循环音乐ID
	//返回:true为成功,false为失败
	bool PlayLoopAudio(const char* Key);

	//功能:停止循环音乐
	//参数1:循环音乐ID
	//返回:true为成功,false为失败
	bool StopLoopAudio(const char* Key);

	//功能:播放非循环音乐
	//参数1:非循环音乐ID
	//返回:true为成功,false为失败
	bool PlayOnceAudio(const char* Key);

	//功能:得到循环音乐音量
	//返回:循环音乐音量
	int GetLoopVolume();

	//功能:设置循环音乐音量
	//返回:true为成功,false为失败
	bool SetLoopVolume(int Volume);

	//功能:得到非循环音乐音量
	//返回:非循环音乐音量
	int GetOnceVolume();

	//功能:设置非循环音乐音量
	//返回:true为成功,false为失败
	bool SetOnceVolume(int Volume);

	//关闭正在播放的音乐   Key为正在播放的音乐名
	bool CloceLoopAudio();
	
	//获取当前播放音乐的时长
	int GetMusicLenth();

	//获取当前在播放中的音乐中正在播放的位置
	int GetCurrentPlayPos();

	//重新设置播放位置
	void ContinueCurrentPlay(unsigned int Postion);

	//从音乐库中移除Key指定的音乐
	void DeleteMusic(const char *Key);
};

#endif