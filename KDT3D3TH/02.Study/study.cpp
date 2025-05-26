//#include <format>
//#include <array>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <functional>
#include <vector>
#include "study.h"

int FPlayer::PlayerCount = 0;
int FMonster::MHeart = 3;


int main() //rpg 파티 관리 시스템  
{

	FPlayer P1 = { "다오", 10, 100, 5 };
	FPlayer P2 = { "마리드", 12, 100, 8 };
	FPlayer P3 = { "디지니", 15, 100, 11 };

	std::vector<FPlayer> Player;
	Player.reserve(10);
	Player.push_back(P1);
	Player.push_back(P2);
	Player.push_back(P3);

	PParty* PPrintInfo = &Party::Get();

	PPrintInfo->VectorPrintPlayerInfo(Player);

	std::cout << "아래부터 map" << std::endl;

	std::map<int, FPlayer> MPlayer;

	for (int i = 0; i < Player.size(); ++i)
	{
		MPlayer[i] = Player[i];
	}

	FPlayer P4 = { "라비", 5,  100, 3 };
	FPlayer P5 = { "어소", 54, 100, 43 };
	FPlayer P6 = { "트락", 67, 100, 89 };

	MPlayer.emplace(3, P4);
	MPlayer.emplace(4, P5);
	MPlayer.emplace(5, P6);

	PParty* MMPlayer = &Party::Get();
	MMPlayer->MapPrintPlayerInfo(MPlayer);

	for (int i = 0; i < MPlayer.size(); ++i)
	{
		std::cout << MPlayer[i].Name
			<< "의 데미지를 입력하세요."
			<< std::endl;
		std::cin >> MPlayer[i].Damage;
	}
	MMPlayer->MapPrintPlayerInfo(MPlayer);


	int Retry = 0;
	std::string Final;
	FMonster Boss = { "고블린",50,1000,30 };

	int* arr = new int[MPlayer.size()];


	for (int i = 0; i < MPlayer.size(); ++i)
	{
		arr[i] = MPlayer[i].HP;
	}

	// 몬스터 하트가 0일때까지 파티 진행
	// 몇번째 트라이 였는지 확인 변수
	// 한명의 플레이어의 체력이 0이되면
	//-> 다른 플레이어로 교체
	// 마지막 플레이어까지 돌면 다시 리트라이.
	while (FMonster::MHeart > 0)
	{
		++Retry;

		for (int i = 0; i < MPlayer.size(); ++i)
		{
			MPlayer[i].HP = arr[i];

		}

		for (int i = 0; i < MPlayer.size(); ++i)
		{
			// 각 플레이어가 살아있는 동안 계속 공격
			while (MPlayer[i].HP > 0)
			{
				Boss.TakeDamageFrom(MPlayer[i]);
				MPlayer[i].HP -= Boss.Damage; // 플레이어도 데미지 받는 설정 (예시)
				std::cout << MPlayer[i].Name << " 현재 HP: " << MPlayer[i].HP << '\n';

				if (FMonster::MHeart <= 0) break;
			}

			std::cout << "현재 몬스터 목숨:"
				<< FMonster::MHeart
				<< std::endl;

			if (FMonster::MHeart <= 0)
			{
				Final = MPlayer[i].Name;
				break;
			}

		}


		if (FMonster::MHeart <= 0) {
			std::cout
				<< "....."
				<< "\n"
				<< "....."
				<< "\n"
				<< "....."
				<< "\n"
				<< "....."
				<< "\n"
				<< "도전 횟수:"
				<< Retry << "\n"
				<< "....."
				<< "\n"
				<< "....."
				<< "\n"
				<< "....."
				<< "\n"
				<< "....."
				<< "\n"
				<< "마지막 타격 플레이어:"
				<< Final << "\n"
				<< "....."
				<< "\n"
				<< "....."
				<< "\n"
				<< "....."
				<< "\n"
				<< "....."
				<< "\n"
				<< "보스 처치 완료!\n";
			break;
		}
	}


	delete[] arr;
	return 0;

}

//백터, 함수포인터, static, 싱글톤,
// this, 함수의 캡쳐와 파라미터,업캐스팅, 
// 다운캐스팅,virtual, 복사생성자, 
// 복사대입연산자, 생성자, 소멸자, 템플릿, 
// 이중포인터,스마트 포인터와 구조체, 동적할당, 
// 컨테이너(list, stack, map unordered map, hash 등등)