#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

struct FPlayer
{
    std::string Name;
    int Level;
    int HP;
    int Damage;
    static int PlayerCount;



    FPlayer() {}

    FPlayer(std::string Oname, int Olevel, int OHP, int ODamage) // 생성자
        : Name(Oname), Level(Olevel), HP(OHP), Damage(ODamage)
    {
        ++PlayerCount;
    }

    FPlayer(const FPlayer& Other)		//복사생성: 새 객체를 기존 객체로 재 생성할때 자동 호출
        : Name(Other.Name), Level(Other.Level), HP(Other.HP), Damage(Other.Damage)
    {

    }

    FPlayer& operator=(const FPlayer& Other)
    {
        if (this != &Other) // 자기 자신과 대입하는 경우 방지
        {
            Name = Other.Name;
            Level = Other.Level;
            HP = Other.HP;
            Damage = Other.Damage;
            std::cout << "복사 대입 연산자 호출!\n";
        }
        return *this;
    }


};


class PParty
{
public:
    virtual void VectorPrintPlayerInfo(const std::vector<FPlayer>& Playe)
    {
        std::cout << "Vector";
    }

    virtual void MapPrintPlayerInfo(const std::map<int, FPlayer>& MPlayer)
    {
        std::cout << "Map";
    }
};

//싱클톤 패턴
//함수 포인터
//플레이어 상태 출력
class Party :public PParty
{
public:
    static Party& Get()
    {
        static Party Instance;
        return Instance;
        // ㄴinstance의 타입이 Party이기 때문에 함수 반환형도 동일
    }

    void VectorPrintPlayerInfo(const std::vector<FPlayer>& Player) {

        std::cout << "전체 플레이어 수 : " << FPlayer::PlayerCount << std::endl
            << "[Player Info]" << '\n';
        for (int i = 0; i < FPlayer::PlayerCount; i++) //for(const auto& P: Player)
        {
            std::cout << "Name: " << Player[i].Name
                << ", Level: " << Player[i].Level
                << ", HP: " << Player[i].HP
                << ", Damage: " << Player[i].Damage
                << '\n';
        }
    }

    void MapPrintPlayerInfo(const std::map<int, FPlayer>& MPlayer) {

        std::cout << "전체 플레이어 수 : " << MPlayer.size() << std::endl
            << "[Player Info]" << '\n';
        for (const auto& [key, player] : MPlayer) {
            std::cout << "Name: " << player.Name
                << ", Level: " << player.Level
                << ", HP: " << player.HP
                << ", Damage: " << player.Damage << '\n';
        }
    }



private:
    Party() {}
    Party(const Party& ref) {}
    Party& operator=(const Party& ref) {}
    ~Party() {}

};



struct FMonster
{
    std::string MName;
    int Level;
    int HP;
    int Damage;
    static int MHeart;

    FMonster() {}

    FMonster(std::string Oname, int Olevel, int OHP, int ODamage) // 생성자
        : MName(Oname), Level(Olevel), HP(OHP), Damage(ODamage)
    {
    }

    float GetResistanceRate(int AttackerLevel) const
    {
        // 예: 캐릭터 레벨이 높을수록 경감률이 커짐 (최대 40%)
        float Rate = std::min(AttackerLevel * 0.04f, 0.4f);
        return Rate;
    }
    void TakeDamageFrom(const FPlayer& Player)
    {
        float Resistance = GetResistanceRate(Player.Level);
        int Damage = static_cast<int>(Player.Damage * (1.0f - Resistance));

        HP -= Damage;
        if (HP < 0) {
            --MHeart;
            HP = 1000;
        }

        std::cout << MName << "이(가) " << Player.Name << "에게 공격받아 "
            << Damage << " 피해를 입음 (저항률: " << Resistance * 100 << "%)\n";
    }

};
