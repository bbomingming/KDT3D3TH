#include "Timer.h"
#include <windows.h>
STimer::STimer(int timerID) : TimerID(timerID), Repeat(false), ExpireTime(0.f), AccTime(0), CallBack(nullptr)
{

}

STimer::~STimer()
{
}

void STimer::Initalize(float expireTime)
{
	ExpireTime = expireTime;
}

bool STimer::Tick(float _deltaTime) //4-7에서 호출
{
	//누적 시간 
	AccTime += _deltaTime;
	HP -= _deltaTime;

	if (!IsExpire()) //만료 시간이 넘었다면 true반환해서 Invoke실행.
		return false;

	//Expiretime이랑 Acctime을 비교했을때 true가 나와서 invoke실행
	//내가 타이머에게 정의했던 함수가 실행됨.
	//이전에 setTimer, setCallback으로 먼저 초기화 시켜줘야함.
	Invoke();

	if (HP < 0)
	{
		char buffer[64];
		sprintf_s(buffer, "[Timer %d] HP < 0! HP: %d\n", TimerID, HP);
		OutputDebugStringA(buffer);
	}

	AccTime = 0.f;

	return true;
}

void STimer::Refresh()
{
	Repeat = false;
	ExpireTime = 0.f;
	AccTime = 0.f; 
	CallBack = nullptr;
}

bool STimer::IsExpire()
{
	//4-7 누적시간이 ExpireTime보다 크다면 true
	return AccTime >= ExpireTime;
}

void STimer::Invoke()
{
	if (CallBack)
		CallBack();
}
