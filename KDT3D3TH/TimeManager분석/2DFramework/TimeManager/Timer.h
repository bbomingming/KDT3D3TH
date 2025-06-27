#pragma once
#include <chrono>
#include <functional>

//시간을 정해주면
//해당 시간마다 정해진 함수를 호출해주는 얘

class STimer // ID, ExpireTime, AccTime(누적 시간), CallBack 함수 
{
public:
	STimer(int timerID);
	//3-1 초반 Initialize에서 타이머 ID를 0에서부터 1씩 증가시켜서 넘겨주면 안에값은 아래처럼 바뀜.
	//TimerID(timerID), Repeat(false), ExpireTime(0.f), AccTime(0), CallBack(nullptr)
	~STimer();

private:
	STimer(STimer&) = delete;
	STimer& operator=(STimer&) = delete;

private:
	int TimerID;
	bool Repeat;
	float ExpireTime;
	float AccTime;

	float HP = 10.0;
	std::function<void()> CallBack;

public:
	void Initalize(float expireTime);
	bool Tick(float _deltaTime);
	void Refresh();
	const int GetTimerID() const { return TimerID; }
	bool GetRepeat() { return Repeat; }	
	bool SetRepeat(bool _Repeat) {Repeat = _Repeat;}


	template<typename Func>
	void SetTimer(float _expireTime, float _AccTime, bool _repeate, Func&& _func)
	{
		ExpireTime = _expireTime;
		Repeat = _repeate;
		AccTime = _AccTime;
		CallBack = std::forward<Func>(_func);
	}

	template<typename Func>
	void SetCallBack(Func&& _func)
	{
		CallBack = std::forward<Func>(_func);
	}

private:
	bool IsExpire();
	void Invoke();
};

