#pragma region 솔루션 탐색기 설정
// 솔루션 탐색기 -> 모든 파일 표시로 변경
// 메모장 드래그 드랍
// sln 솔루션= 상위폴더
// 디버그-> exe파일
// 원하는 폴더에서 검색창에 cmd입력-> 경로 열림
// <솔루션 설정>
// 출력 디렉 => $(SolutionDir)Binary\$(Platform)\$(Configuration)\
// 중간 디렉 => $(SolutionDir)Intermediate\$(ProjectName)\$(Platform)\$(Configuration)\
// c++표준 ->c++ 20
//ctrl + m + O 모든 함수 접기
//ctrl + m + L 모든 함수 펼치기

#pragma endregion


#pragma region 주석
// 주석 Ctrl+K -> Ctrl 누른상태 + C:선택 라인 주석
// 돌아가기 Ctrl+K -> Ctrl 누른상태+ U 
//Ctrl+Z Undo
//Ctrl+Y Redo
//배포할때 pdb x
#pragma endregion

#include <iostream>
#include <format>
#include <array>

//절대경로: 모든 경로를 쭉 나열<< D:\KDT3D3TH-(jbm)\KDT3D3TH <<-이런 느낌
//<<-상대경로:특정 기준점을 기준으로 상대적으로 떨어진 경로<< Folder/Function.h 
//include같은 경우는 지금 현재 폴더 기준
#include "Function.h" 
//현재 폴더 보다 상위 폴더에 포함시키고 싶은 해더파일이 있을때
//#include"../Hello.h"
//    ../ <<- 한칸 상위
//    .   <<-현재 폴더

int main()
{   
    
#pragma region 01.표준 입출력 (cout, cin)

    { //스코프 = 지역변수
        int a = 10;
    }
    {
        int a = 0;
        //std::cin >> a;
       // std::cout << "Hello World!\n" << a;

        //std는 namespace의 일종
    }
#pragma endregion


#pragma region 02.리터럴(literal) <코드에 표시한 숫자나 문자열과 같은 값을 의미>
    {
        //2진수는 2진수 앞에 0b 0110 0100 -> 100(10진수)
        int v2{ 0b01100100 };
        //아래 동일
        //8진수 0
        int v8{ 0 };
        //16진수 0x
        int v16{ 0 };

        //부동소수점(float) 소수 뒤에 f
        float f{ 3.14f };
        //배정도 부동소수점(double) 소수 뒤에 f 없음
        double f1{ 3.14 };
        //단일문자
        char c{'a'}; //아스키 코드값 '' <- 문자 /  "" <- 문자열
        char c0{ 97 }; // 위와 같음.
    }

#pragma endregion


#pragma region 03.변수(Variable)
    {
        //unsigned char, int, long,longlong, float double의 대한 설명


        //유니코드(다국어 처리가 가능, 2Byte)
        {
            wchar_t W{ L'A' };
            wchar_t W2{ L'가' };
        }
        //부울타입(boolean참,거짓)
        {
            bool B0 = false;
            bool B1 = true;
            bool B2 = 0;
            bool B3 = 1;

        }
        //형변환
        {
            float Float{ 3.14f };
            int Int = Float; // 묵시적 cast (경고 발생)
            int Int2 = (int)Float;// c스타일 명시적 Cast
            int Int3 = int(Float);//동일
            int Int4 = static_cast<int>(Float); // c++스타일 명시적 Cast
            
            short Short{ 10 };
            int Int5 = Short;// 더큰 타입의 정수 자료형으로 가기에 문제가 없다.

            //반대로면 값이 잘릴 수 있다.
            //int int6 = 999999;
           // short short2 = int6;
        }
    }
#pragma endregion


#pragma region 04.지역변수, 전역변수와 메모리
    {
        //지역변수: {} 스코프 내부에서 선언, 안에서만 유효
        //전역변수: 함수 바깥에서 선언, 모든 스코프에서 접근 가능
        
        int j{ 0 };   // << 아래 지역변수에 대한 전역변수 

        {
            int j{ 1 }; // 지역변수
           // std::cout << j; <- 1 출력
        }

    // std::cout << j;  <- 0 출력




        //stack 높은주소-> 낮은주소
        //heap 낮은주소-> 높은주소
        
    }

#pragma endregion


#pragma region 05.연산자
    {
        bool b1{ !6 }; // <- false
        //대입연산, 사칙연산, 나머지연산(mod), 증감연산
        //a++ 후행증가: 계산이후 증가
        // ex) int a=0 
        // int b=a++;  <-b=0 불상사 발생
        //++a 선행증가: 계산 전 증가
        // int b=++a; <-b=1 

        //삼항 연산자
        //(조건문) ? 참: 거짓;
        int a = 0;
        int b = (a == 0) ? 100 : -100;



        //xor사용해 toggle기능을 구현

    }
#pragma endregion


#pragma region 06. 열거형(enumerated type)  3일차

    {

        {
            //const: 상수, 초기화 이후 해당값은 변경 불가
            const int iron = 0;
            const int Bronze = 1;
            const int silver = 2;
            const int Gold = 3;
        
            int MyTier = Gold;
        
        }
        {
            enum ETier: unsigned char // enum은 이름에 E를 붙이는편, 뒤에 : 하고 원하는 타입 부여, 이름만 ETier이지 형태는 unsigned char과 같다.
            {
                Iron,
                Bronze=10,
                Silver,
                Gold,
            };

            ETier Mytier = Gold;
        }

        {
            enum class ETier : unsigned char // class를 붙여서 제한을 둘 수 있다. 동일하게 변수 선언할때 접근지시자를 붙여줘야 한다. 
                //또한 enum은 정리를 한거뿐이지 데이터가 메모리로 올라가지는 않는다. 
            {
                Iron,
                Bronze = 10,
                Silver,
                Gold,
            };

           // ETier Mytier = Gold;
            ETier Mytier = ETier::Gold;


        }
    }


#pragma endregion


#pragma region 07. 구조체(Struct) +패딩 개념, format 사용
    {
        enum class ETier : unsigned char
        {
            None,
            Iron,
            Bronze,
            Silver,
            Gold,
        };
        struct Fplayer1
        {
            int HP; //<< 항상 초기화 해주기 
            int MP = 10;
            ETier Tier = ETier::None;

        };
        Fplayer1 player1; //<< 플레이어 변수를 구조체 인스턴스라고 부른다.
        Fplayer1 player12{ .HP = 100,.MP = 123 }; //<< {.}으로 수정 방법 111
        player1.HP = 100; //<< 수정 방법2222

        std::cout << "HP" << player1.HP << std::endl;
        std::cout << "MP" << player1.MP << std::endl;

        std::cout << std::format("HP:{},MP:{}", player12.HP, player12.MP);

        // 
        // 패딩은 가장 큰 자료형태의 크기로 정해짐. 
        // 아래는 패딩을 수동으로 설정하는 방식 
        //#pragma pack(push, 1) <<-구조체 형식에만 영향을 미치나?
        //#pragma pack(pop)
        //[00] / [00 00 00 | 00 00 00 00 00]  <<- 패딩x double값을 읽기 위해 두번 접근  9byte
        // [00] [00] [00] [00] / [00 00 00 00 00 00 00 00]   << 한번에   16byte
        //
    }

#pragma endregion

#pragma region 08. 조건문 (if/switch)
    {
        //if
        {
            if (int a = 10; a <10) 
            {
                std::cout << "N\n";
            }
            else if (a >= 13) 
            {
                std::cout << "Y\n";

            }
            else
            {
                std::cout << "hello\n";
            }
        }
    }

    {
        int i = 10;
        switch (i)
        {
        case 10:
            std::cout << "10\n";
            break; //탈출
        case 11:
            std::cout << "11\n";
        case 12:    //break가 없어서 12까지 수행후 탈출
            std::cout << "12\n";
            break;
        default:
            std::cout<<"Default";
            break; //만족하는게 없으면 실행. else와 같은 너낌. 
        }

    }
    //아래는 구조체와 열거형 만들고 조건문 or연산
    {
        enum class ETier : unsigned char
        {
            None,
            Iron,
            Bronze,
            Silver,
            Gold,
        };
        struct Fplayer1
        {
            int HP = 100;
            int MP = 10;
            ETier Tier = ETier::Gold;

        };
        Fplayer1 player11;
        player11.Tier = ETier::Bronze;
        if (player11.Tier == ETier::Bronze || player11.Tier == ETier::Iron || player11.Tier == ETier::None)
        {
            std::cout << "나의 티어는 골드가 아닙니다.";
        }
        else
        {
            std::cout << "나의 티어는 골드입니다.";
        }
    }
#pragma endregion


#pragma region 09. 논리연산자, xor연산에서 불 함수
    {
        //논리 부정
        if (!false)
        {
            std::cout << "참";
        }

    }
#pragma endregion
#pragma region 10. 함수, 오버로딩, F11<-함수진입, 재귀호출
    {
       /* 
       규모가 큰 프로그램에서 모든 코드를 main함수에 작성하면 유지보수가 어렵습니다.
        
       가독성과 구조화를 위해서 함수 단위로 나눈다.
        
       c++에서 함수를 사용하기 위해서는 선언이 필요하다.
       -함수의 선언은 메인함수 위에서
       -함수의 정의는 메인함수 밖에다가 해야한다. 중첩된다고 한다. 람다함수라고 안에서 사용할 수 있게 하는게 있나보다.
       -함수 선언 형식
       
       (반환타입) (함수이름) (입력 파라미터) 
        
        -오버로딩: 동일한 함수 이름이지만 파라미터, 인자가 다른 함수. 자료형에따라도 구분가능
        void function(ina a);
        void function(int a, int b);

        -함수 호출 방법
        호출 시 복귀할 주소(코드영역)를 스택에 저장
        호출되 함수의 주소로 이동하고 함수 내용 실행-> ret를 만나면 -> 스택에 저장된 복귀할 주소로 돌아가게됨.
        
        [calling Conbention-함수 호출 규약]
        함수 호출 시 파라미터 전달 및 스택 정리를 누가 담당하는지 정의하는 방식
        예: __cdecl 등등  __thiscall <-나중에 설명 예정

        */

        /*
        재귀 호출 형식

        반환타입 이름 (인자)
        {
             if(f==0)
             {
                    return 1;
              }
             else
             {
                    return f*이름(f-1);
             }
        }

        재귀 호출의 장단점
        
        */
     
   
    
    }


#pragma endregion 


#pragma region 11.BIT Flag
    {
    
        EPropertyFlags Me = EPropertyFlags::Eproperty1;
        bool Bresult = BackFlag(Me, EPropertyFlags::Eproperty1);

        if (Bresult)
        {
            std::cout << "Yes 1";
        }
        else 
        {
            std::cout << "No";
        }


    }
#pragma endregion


#pragma region 12. 배열
    {
        //개수로 넣고 접근할때는 index로 접근
        //   int a[3]  <- a[0] a[1] a[2 <- index]
        /*
        
        #include <array> 사용법
        
        std::array (컨테이너)
       
        std::array < 타입 , 사이즈(개수) > 배열이름 { 값, 없으면 0 };
        
        const int ArraySize = 배열이름.size();


        


        */
    }
#pragma endregion

#pragma region 13. 반복문
    {

        {
            const int size = 10; 
            int array[size]{}; // <<- 배열 선언할때 인뎃스값은 상수만. const 

            for (int i = 0; i < size;i++) 
            {
                std::cout << array[i] << std::endl;
            }

        }
        /*
        for(int i : array)   <<- 범위기반: array 안에 있는 값을 i에 저장. 
        {

        }
        
        */

        {
            const int size = 10;5;
            int array[size]{1,2,3,};
            int count = 1;

            for (int i : array)
            {
                std::cout << i<<"-"<<count<<std::endl;
                
                ++count;
            }

            {//c++20 부터 
                for (std::array Array2{ 1,2,3 }; int i : Array2)
                    { 
                        std::cout << std::format("i 값은: {}\n", i); 
                    
                    }

               /* for (size_t i = 0; i < length; i++) <<- size_t는 부호없는 정수타입
                {

                }*/

            }
            
        }

    }
#pragma endregion



#pragma region 14. 포인터와 동적 메모리 + 레퍼런스{참조}
    {


        //4바이트 변수를 8바이트로 타입 지정하고 8바이트 포인터로 
        //역참조하면 4바이트 이상의 값을 대입하면 뒤에 부분까지 영향을 미친다.

        /*
        -동적 할당
        
        포인터 변수 = new 타입{값};    이때 포인터 변수는 힙 영역의 주소값을 가짐.
        delete 포인터 변수;    스코프 탈출 후 메모리 누수를 막기 위함.

        */

    }
#pragma endregion
}



// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴
// <F10> 한줄씩 디버그, 왼쪽 화살표 드래그 드랍 가능, 브레이크 포인트(단축키<F9>)


// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

//#pragma region
//#pragma endregion






