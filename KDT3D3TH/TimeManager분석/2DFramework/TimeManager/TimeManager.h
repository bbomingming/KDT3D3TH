#pragma once
#include "Singleton.h"
#include "../Info.h"
#include "Timer.h"
#include<functional>

class CTimeManager : public SSingleton<CTimeManager>
{
	friend SSingleton<CTimeManager>;

protected:
	CTimeManager();
	~CTimeManager();

private:
	CTimeManager(CTimeManager&) = delete;
	CTimeManager& operator=(const CTimeManager&) = delete;

private:
	//chrono 에 여러가지 시계가 있는데
	//high_resolution_clock <---얘는 가장 정밀한 시간
	//내부적으로 구현은 쿼리포퍼먼스프리퀀스 <-- C++ windows 지원하는 정밀타이머
	
	//현재 사용중인 타이머
	std::map<int, std::shared_ptr<class STimer>> ActiveTimer;
	
	//쉬고 있는 타이머
	std::queue<std::shared_ptr<class STimer>> PendingTimer;

	std::chrono::high_resolution_clock::time_point LastTime;
	float DeltaTime;
	int TimerID;

public:

	bool Initialze();
	//초반 호출 후 생성

	void Update();
	//Logic에서 계속 호출되면서  DeltaTime을 최신화 시켜줌.

	float GetDeltaTime() { return DeltaTime; }
	//위에서 초기화 시킨 DeltaTime을 보내줌.

	std::shared_ptr<class STimer> Rent();

	void Return(std::shared_ptr<class STimer> timer);


	void TimerInit(int _timerID,
		bool _Repeat, 
		float _ExpireTime,
		float _AccTime,
		std::function<void()> _callback)
	{
		ActiveTimer[_timerID]->SetTimer(_ExpireTime, _AccTime, _Repeat, _callback);
	}

private:
	int GetTimerID() { return TimerID++; }
};

