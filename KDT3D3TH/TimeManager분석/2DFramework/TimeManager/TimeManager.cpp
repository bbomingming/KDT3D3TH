#include "TimeManager.h"
#include "Timer.h"

#define TIMER_COUNT 1

CTimeManager::CTimeManager()
{
}

CTimeManager::~CTimeManager()
{
}

bool CTimeManager::Initialze()
{
	//1. 초반 호출
	LastTime = std::chrono::high_resolution_clock::now();
	//현재 시간을 마지막 시간에 저장.
	//예)현재 15초 -> 마지막 시간


	//2.TimeID는 호출될때마다 0에서 1씩증가.
	//3. 위에 정의된 수 만큼 쉬는 타이머에다가 STimer에 GetTimerID를 넘겨주면서 스마트 포인터 생성.
	for (int i = 0; i < TIMER_COUNT; ++i)
		PendingTimer.push(std::make_shared<STimer>(GetTimerID())); 

	return true;
}

void CTimeManager::Update() //4. Logic에서 계속 호출
{
	auto curTime = std::chrono::high_resolution_clock::now();
	//4-1 새로운 타임 생성
	std::chrono::duration<float> frameTime = curTime - LastTime;
	//4-2 현재 타임에서 이전 타임을 빼서 프레임 시간을 만듬.
	DeltaTime = frameTime.count();
	//4-3 델타타임에 프레임 시간 대입
	LastTime = curTime;
	//4-4 현재 시간을 이후 계산을 위해 Lasttime으로 대입

	//4-5 지워질 타이머들을 담을 자료구조
	std::vector<std::shared_ptr<STimer>> expireTimer;
	
	//4-6 사용 중인 타이머만 확인
	for (const auto& it : ActiveTimer)
	{
		auto itVal = it.second;
		if (itVal == nullptr) //타이머가 비어있지 않다면 타이머 체크
			continue;

		//타이머 체크
		if (itVal->Tick(DeltaTime)) // 4-7 타이머 객체 첫번째에 Tick함수 호출
		{
			//Tick을 호출했을때 true를 반환한다면 
			//해당 타이머가 반복 할껀지 확인
			if (itVal->GetRepeat())
				continue;
			//아무 설정도 없어서 현재 repeat은 false

			//반복 하지 않을 타이머는 지워질 타이머를 담을 자료구조에 넣는다.
			expireTimer.push_back(itVal);
		}
	}

	//5. 지워질 타이머들을 담을 자료구조를 순회하면서
	//타이머를 유효타이머로 전환시킨다.
	size_t size = expireTimer.size();
	for (size_t i = 0; i < size; ++i)
		Return(expireTimer[i]);

	expireTimer.clear();
	//다해주면 청소!
}

std::shared_ptr<class STimer> CTimeManager::Rent() //쉬는 타이머를 활성화 타이머로 바꾸기 위해 호출
{
	if (PendingTimer.size() == 0)
	{
		std::shared_ptr<STimer> timer = std::make_shared<STimer>(GetTimerID());
		ActiveTimer[timer->GetTimerID()] = timer;
		return timer;
	}

	std::shared_ptr<STimer> timer = PendingTimer.front();
	ActiveTimer[timer->GetTimerID()] = timer;
	PendingTimer.pop();
	
	return timer;
}


void CTimeManager::Return(std::shared_ptr<class STimer> timer) //5에서 호출.
{
	auto it = ActiveTimer.find(timer->GetTimerID());
	if (it == ActiveTimer.end()) //타이머에 마지막인지 확인
		return;

	auto itVal = it->second; 
	if (!itVal) //타이머가 있는지 확인
		return;

	//마지막 아니고 타이머 있으면 실행.
	itVal->Refresh(); //값을 모두 초기화해준다.
	PendingTimer.push(itVal); //쉬는 타이머에 현재 타이머를 보내주고,
	ActiveTimer.erase(itVal->GetTimerID()); //활성화 타이머에 현재 타이머 삭제.

}


//현재는 특별한 설정이 없지만 repeat을 조건문으로 해당 타이머를 가지고 있는 몬스터 체력이 0이되면 
//refresh해서 반환 시켜주고 + invoke를 써서 setcallback함수 설정해주고
// 모든 아이템들의 Expiretime을 5분으로 설정해주고 게임 내에서 내가 아이템을 떨어트리는 시간이 다르니까
//그걸 개별로 설정해주고 누적 시간이 다다르면 알아서 callback함수에 성정했던거 Invoke에서 호출되고 
//타이머는 true를 반환해서 해당 아이템에 타이머를 반환하는 형식으로 가능하다는거지? 


/*

요점 정리
Repeat 옵션 활용

기본적으로 Repeat = false로 설정되어 있어서, 타이머가 만료되면 한 번만 콜백 실행 후 자동으로 반환(Refresh() 및 Return())됩니다.

만약 특정 상황에서 반복 타이머가 필요하면 Repeat = true로 설정 가능.

몬스터 체력 0일 때 타이머 관리

몬스터의 체력이 0이 되면 해당 몬스터가 가진 타이머를 Refresh()로 초기화하고

Return() 함수를 호출해 타이머를 유휴 풀로 반환(재사용 대기 상태)시킬 수 있습니다.

Invoke() 함수와 SetCallBack() 활용

타이머를 생성할 때 SetTimer() 혹은 SetCallBack()으로 원하는 콜백 함수(예: 아이템 사라지는 함수)를 등록합니다.

누적 시간이 ExpireTime에 도달하면 Invoke()가 호출되어 콜백 함수가 실행됩니다.

아이템별 개별 타이머 설정

각 아이템마다 떨어뜨린 시간이나 효과 시간이 다르므로 ExpireTime을 개별로 설정 가능합니다.

누적 시간이 그 값에 도달하면 자동으로 콜백 호출 및 타이머 반환 처리.

자동 관리 흐름

매 프레임 CTimeManager::Update()에서 모든 활성 타이머를 Tick(DeltaTime)으로 체크

만료된 타이머는 Invoke() → 콜백 실행 → 반환 처리 순서로 자동 관리

유휴 타이머 풀에서 재사용 가능

*/