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
#include <string>
//절대경로: 모든 경로를 쭉 나열<< D:\KDT3D3TH-(jbm)\KDT3D3TH <<-이런 느낌
//<<-상대경로:특정 기준점을 기준으로 상대적으로 떨어진 경로<< Folder/Function.h 
//include같은 경우는 지금 현재 폴더 기준
#include "Function.h" 
#include <locale>
#include <vector>
#include <list>
#include <iterator>
#include <queue>
#include <functional>
#include <stack>
#include <map>
#include <unordered_map>
//현재 폴더 보다 상위 폴더에 포함시키고 싶은 해더파일이 있을때
//#include"../Hello.h"
//    ../ <<- 한칸 상위
//    .   <<-현재 폴더


using namespace std;

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
            enum class ETier: unsigned char // enum은 이름에 E를 붙이는편, 뒤에 : 하고 원하는 타입 부여, 이름만 ETier이지 형태는 unsigned char과 같다.
            {
                Iron,
                Bronze=10,
                Silver,
                Gold,
            };

            ETier Mytier = ETier::Gold;
        }

        {
            enum class ETier2 : unsigned char // class를 붙여서 제한을 둘 수 있다. 동일하게 변수 선언할때 접근지시자를 붙여줘야 한다. 
                //또한 enum은 정리를 한거뿐이지 데이터가 메모리로 올라가지는 않는다. 
            {
                Iron,
                Bronze = 10,
                Silver,
                Gold,
            };

           // ETier Mytier = Gold;
            ETier2 Mytier = ETier2::Gold;

            //위에 열거형과 아래 열거형의 변수이름이 같아도 class를 붙여주면 사용가능하다. 
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
        for(int i : array)   <<- 범위기반: array 안에 있는 값을 i에 저장하고 마지막까지 반복
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
    {    /*
        포인터의 크기는 플랫폼 bit수의 대응해서 바뀜.
        64비트 운영체제에서는 포인터는 8바이트
         
         
        4바이트 변수를 8바이트로 타입 지정하고 8바이트 포인터로 
        역참조하면 4바이트 이상의 값을 대입하면 뒤에 부분까지 영향을 미친다.
        
        -동적 할당

        포인터 변수 = new 타입{값};    이때 포인터 변수는 힙 영역의 주소값을 가짐.
        delete 포인터 변수;    스코프 탈출 후 메모리 누수를 막기 위함.

        */
        
        {
        // malloc free 함수

            int* ptr = (int*)malloc(sizeof(int));
            *ptr = 10;
            free(ptr);
            ptr = nullptr;
        }

        {
        //포인터 배열 접근 방법

            int* ptr = new int[10] {0, 9, 9, 9, };
            ptr[0] = 1; //<<- 시작 주소안의 값 100
            *ptr = 2;
            *(ptr + 1) = 3; //<<- 시작 주소값의 1을 더하면 다음 주소
            delete[] ptr;//<<- 배열은 []
        }

        {
        //구조체 동적할당
            struct Fstruct
            {
                //생성자:인스턴스가 만들어질때 호출되는 함수
                Fstruct()
                {

                }

                int value1 = 0;
                int value2 = 0;

            };

            Fstruct Struct;
            Struct.value1 = 10;
            
            //동적할당.
            Fstruct* ptr = new Fstruct{};    //<<<-구조체 동적할당
            ptr->value1 = 1234;              // <-구조체 포인터     
            (*ptr).value1 = 12412;

            *((int*)(ptr)) = 5555;
            *(((int*)(ptr))+1) = 6666;

            (ptr + 1)->value1 = 7777;
            (ptr + 2)->value2 = 8888;
        }
        {
            //malloc free 
            struct Fstruct
            {
                //생성자:인스턴스가 만들어질때 호출되는 함수
                Fstruct()
                {
                    std::cout << "생성자";
                }

                int value1 = 0;
                int value2 = 0;

            };
            //new delete와는 다르게 생성자와 소멸자를 호출하지 않는다.
            //malloc은 요청한 크기만큼 메모리 할당하고 그 주소를 return함.
            Fstruct* Struct = (Fstruct*)malloc(sizeof(Fstruct));

            free (Struct);

        }
        {//함수 호출과 포인터
            //5/12코드 참조
            //call by value방식을 사용하면 함수에서 저장된 값을 복사하는거기 때문에 2배의
            //공간이 사용된다.
            //ㄴ복사 생성자가 있다고한다.

            //그러나 포인털르 사용하면 주소값을 전달하기때문에 공간을 그대로 접근해서 사용한다.

        }
        //레퍼런스와 포인터 정리
        {
            int a = 0;

            int& ptr=a;
            ptr = 1000;
            // 레퍼런스는 이후에 주소값은 바꿀 수 없다. 포인터는 &으로 주소값을 바꿔줄 수 있다.
            //다른걸 못 가리킴.

            int* const b = &a;  // b의 주소값은 바꿀수 없다.
            const int* c = &a;  //c의 값은 바꿀 수 없다.
            const int* const d = &a; //값과 주소 변경 불가
        }
        {
            //스마트 포인터 
            //shared_ptr, weak_ptr
            std::shared_ptr<int>a = std::make_shared<int>(10);
            //reference Count 방식으로 수명 관리-> 현재 참조 횟수 1
            //위에 shared_ptr한개 생성하고 대입하면 참조 횟수 2로 스코프 빠져나가도 값 유지
            //메모리 없애는 방식->인스턴스가 소멸되면 count 감소->0이되면 shared ptr 소멸자 호출

        }

        //스마트 포인터와 구조체
        {
            struct Fstruct
            {
                Fstruct()
                {
                    std::cout << __FUNCTION__ << std::endl;
                }
                ~Fstruct()
                {
                    std::cout << __FUNCTION__ << std::endl;
                }
                int value = 0;

            };

            std::shared_ptr<Fstruct> SharedPtr;
            {
                SharedPtr = std::make_shared<Fstruct>();
            }

            //일반 포인터가 스마트 포인터의 주소를 참조하고 있을때
            //스마트 포인터가 삭제되면 일반 포인터는 값은 사라졌지만 그대로 주소를 가르킨다.
            //ptr=smart_ptr.get(); <<--일반포인터 참조, raw pointer을 얻는다.

        }/*

        1. std::shared_ptr 와 참조 카운트

            shared_ptr는 참조 횟수(reference count) 로 객체 수명을 관리함.

            shared_ptr가 복사될 때마다 참조 횟수 증가 → 소멸될 때마다 참조 횟수 감소.

            참조 횟수가 0이 되면, 관리하는 객체 메모리 자동 해제.

            weak_ptr는 참조 횟수에 영향 안 주고, 객체 소멸 여부를 확인하는 용도.

        2. std::weak_ptr 와 사용법

            weak_ptr은 객체를 직접 소유하지 않음 → 참조 횟수 증가 안 함.

            lock() 함수로 shared_ptr 임시 생성해 객체에 안전하게 접근 가능.

            lock() 반환값이 nullptr이면 객체가 이미 소멸된 상태.

            expired() 함수로 객체가 소멸됐는지 미리 확인 가능.

            중요: weak_ptr.lock()->Value 처럼 바로 쓰면 안 됨!
            반드시 lock() 반환값이 유효한지 검사 후 사용해야 런타임 오류 방지.

            3. nullptr의 의미와 특성
            nullptr는 C++11부터 도입된 null pointer를 나타내는 특수한 값.

            타입은 std::nullptr_t로, 정수가 아님.

            모든 포인터 타입으로 암시적 변환 가능.

            nullptr은 포인터만 의미하며, 정수 0이나 NULL과 다름.

            if (ptr) 조건문에서 nullptr은 false로 간주됨.

            4. 포인터와 nullptr
            포인터 변수에 nullptr을 대입하면, 포인터가 아무것도 가리키지 않는 상태가 됨.

            하지만 nullptr을 대입해도, 해당 주소의 메모리 자체가 사라지는 것은 아님.

            동적 할당한 메모리는 delete 해야 명시적으로 해제됨.

            단순히 ptr = nullptr 하면 메모리 누수 위험 있음(할당 해제 안 됨).

            5. 스마트 포인터 get() 함수
            get() 함수는 스마트 포인터가 관리하는 원시 포인터(raw pointer)를 반환.

            반환된 포인터로 메모리 해제하면 안 됨(스마트 포인터가 관리 중).

            주로 스마트 포인터가 관리하는 객체 주소를 외부에 전달할 때 사용.
                */
    }

    {
        //https://gdngy.tistory.com/183
    }

#pragma endregion

#pragma region 15.타입 재정의
#pragma endregion

#pragma region 16. 문자열+locale
    {
        //문자열이 같으면 같은 주소를 가르킴
        const char* text = "asdfsdafasdf";
        const char* text2 = "asdfsdafasdf"; //<<힙
        char text3[] = "asdfsdafasdf"; //<< 스택


        text3[3] = '\0'; //보통 문자열의 끝
        std::string String = { "hahaahahah" };
    

        

        std::cout << sizeof(String)<<std::endl;

        std::cout << sizeof(text3)<<std::endl;

        std::string size = {"llkasdfjlaskdflsdkfnsdlkfnsdlkfnasdlkfnsdalk;fsdalfkasdflksnl;knlknlk"};
        std::cout << sizeof(size) << std::endl;
        //sizeof는 현재 변수의 최대 크기를 알려줌

        size_t Size = String.size(); //문자열 길이 
        std::cout << Size << std::endl;
        //위를해서 대입된 길이를 알게됨

        {

            // if(String==string)   //문자열 비교
        }
        {
            std::string String = "hello 안녕";
            String[6] = '한';
            //손실 변환으로 데이터 깨짐
            std::wstring WString = L"hello 안녕";
            WString[6] = '앙';

            std::wcout.imbue(std::locale(".UTF-8"));  

            const std::wstring texts[] = {
       L"どうして君だったかな 도 - 시테 키미닷타카나 어째서 너였던걸까"  // Japanese text
            };

            // 배열의 첫 번째 요소 직접 출력
            std::wcout << texts[0] << std::endl;
        }

        //출력을 위해서는 인코딩 설정이 필수, locale설정으로 
        // #include<lacale>
        // std::wcout.imbue(std::locale(".UTF-8"));
        //메모리 내부에서는 locale설정없이도 동작
        
    }

    
#pragma endregion

#pragma region 17. 클래스
    {
      
        // 클래스는 데이터(변수)와 함수(메서드)를 묶어서 하나의 단위로 만들 수 있습니다.
        class FClass
        {
                        // 접근 지정자 기본은 private
                        // public: 외부에서 접근 가능(호출, Read Write 불가)
                        // private: 외부에서 접근 불가(호출불가, Read Write 불가)
            public:

               FClass()                    // 생성자: 인스턴스가 만들어질 때 호출되는 함수
                : Value2(1000)
               {
                std::cout << "FClass 생성자!\n";
                /*this->*/Value1 = 12345;
               }


              ~FClass()                    // 소멸자: 인스턴스가 삭제될 때 호출되는 함수
              {
                std::cout << "FClass 소멸자!\n";
              }


               void Function(/*  FClass* this   */)
               {
                // this = nullptr; // 불가능
                std::cout << std::format("Value1: {}, Value2: {}",this->Value1, Value2);   //this가 생략됨                        
                // 맴버 함수를 호출 하는 경우
                // __thiscall: 숨겨진 인자로 this가 전달 된다
               }

              void SetValue1(int InValue)
              {
                    Value1 = InValue;
                    std::cout << "Value1: " << Value1 << std::endl;;
              }

                                                     // 리턴값을 받지 않으면 경고를 띄워주는 에트리뷰트
                                                     // 함수 인자 뒤에 const가 붙으면 this를 "const" FClass* this로 바꿔줍니다
                                                [[nodiscard]] int GetValue1() const
                                                {
                                                    /*this;
                                                    Value1 = 100;
                                                    int a = 10;
                                                    a = 20;*/
                                                    return Value1;
                                                }

        private:
            int Value1 = 3;
            int Value2 = 2;
        };
        FClass Class;
        /*int* Pointer = (int*)&Class;
        *Pointer = 8888;*/

        Class.Function();
        Class.SetValue1(10);
        int Value1 = Class.GetValue1();
        Class.GetValue1();
        // private 맴버에 접근을 할 수 없다
        // Class.Value1 = 10;
        //Class.Value2 = 20;
    }


#pragma endregion

#pragma endregion 18. 다중 포인터
    {
        int** ptr = { nullptr };

        ptr = new int* { nullptr }; //stack 영역에 힙 주소
        *ptr = new int{ 10 }; //위 힙 주소 안->10 <-16진수 표시, 부호 있는 표시 선택
        **ptr = 20;

        std::cout << **ptr;
        std::cout << "**ptr의 주소: " << &(**ptr) << std::endl;
    }
#pragma region


#pragma region 19. 그냥 배운거 this, static, class의 객체 ******
    {
        class A
        {
        public:
            int num = 10;

            void print_This() {
                cout << this << endl; //호출한 객체의 주소를 리턴
            }
            A& return_This() {
                return *this; //호출한 객체 자체를 리턴
            }
        };     //this는 포인터이다!


        A a;                           //객체 a생성
        a.print_This();                //객체 a의 print_This함수 호출->this 출력(자신의 주소값)
        A& ref = a.return_This();      //래퍼런스 ref는 a의 객체 자신을 받아온다. 
        ref.print_This();
        return 0;
        /*
        1. C++에서 this와 레퍼런스

        this는 멤버 함수 내에서 호출된 객체 자신의 포인터(클래스명* this).
        ㄴ주소
        
        *this는 그 객체 자체(레퍼런스).
        ㄴ즉 (*this).value로 접근이 된다.
        
        return *this;
        ㄴ레퍼런스로 반환하면 호출한 객체 자신을 가리키게 된다.
        
        A& ref = a.return_This();에서 ref는 a 객체를 참조하므로 주소가 같다.
        
        레퍼런스가 아니라 일반 변수로 받으면 복사본이 만들어지고 주소는 다르다.
        ㄴref와 a의 객체 주소가 다르다.
        
        2. this->Value vs Value
        클래스 내부 멤버 함수에서 Value는 this->Value와 같다.
        
        this->Value는 명시적으로 현재 객체의 멤버를 가리킴.
        
        함수 매개변수나 로컬 변수와 멤버 변수가 겹칠 때 구분할 때 쓰임.
        
        3. static 멤버 함수와 this
        static 멤버 함수에는 this 포인터가 없다.
        
        이유: static 함수는 객체 없이 클래스 이름으로 호출 가능하므로 특정 객체가 없어서 this가 존재하지 않는다.
        
        static 함수 내에서는 인스턴스 멤버 변수에 접근 불가, 클래스 내 static 변수나 다른 함수만 접근 가능.
        
        4. 객체 인스턴스와 멤버 변수 주소
        A a;
        A b;
        처럼 여러 객체를 만들면 각각 멤버 변수(a.value, b.value)는 독립된 메모리 공간을 갖는다.
        
        따라서 주소값은 다르다.
        
        단, static 멤버 변수는 모든 객체가 공유해서 주소가 같다.
        
        5. 클래스와 인스턴스 메모리
        클래스 자체는 설계도라서 인스턴스가 없으면 멤버 변수에 대응하는 메모리 공간이 없다.
        
        단, static 멤버 변수와 함수, 타입 정보 등은 프로그램 시작 시 메모리에 올라가 있다.
        
        인스턴스(객체)가 생성될 때 해당 객체만의 메모리 공간이 할당되어 멤버 변수가 존재하게 된다.
        


        */

        // static 멤버 변수 관련 정리

        // 1. static 멤버 변수는 클래스 내부(보통 헤더 파일)에서 '선언'만 한다.
        //    예: static int count;

        // 2. static 멤버 변수는 반드시 cpp 파일 등 전역 스코프에서 '정의'해야 한다.
        //    예: int ClassName::count = 0;

        // 3. static 멤버 변수는 모든 인스턴스에서 공유되며,
        //    인스턴스를 만들지 않고도 접근 가능하다.
        //    예: ClassName::count;

        // 4. C++17 이상부터는 inline static을 사용하면 클래스 내부에서 선언과 정의를 동시에 할 수 있다.
        //    예: inline static int count = 0;

        //이처럼 
    }
    /*
    class Player
    {
    public:
        static int PlayerCount;

        Player() {
            PlayerCount++; // 모든 Player가 공유
        }
    };
    int Player::PlayerCount = 0;
    */ 

    /*
   ✅ 1. 함수포인터 기본
함수의 주소를 저장하는 포인터 변수

선언 예: bool (*funcPtr)() = ReturnTrue;

호출 시 funcPtr() 또는 (*funcPtr)() 둘 다 가능 (암묵적 역참조)

2. auto와 함수포인터
함수 이름 대입 시 자동으로 함수포인터 타입으로 추론됨

예: auto func = ReturnTrue; func();

3. 타입 별칭(type alias)으로 가독성 향상
예: using FuncPtr = bool(*)();

함수포인터 타입을 간단히 이름으로 표현 가능

4. std::function과 std::bind
함수포인터 한계 극복 (멤버 함수, 람다, 상태있는 호출자 등 저장 가능)

std::function은 다형적 함수 래퍼

std::bind는 객체와 멤버 함수, 인자를 묶어 호출 가능하게 만듦

   일반 함수 호출 시

	auto BoundAdd = std::bind(Add, 10, std::placeholders::_1);

	int result = BoundAdd(5);  // Add(10, 5) 호출됨

	boundFunc(42);  // 내부적으로 (obj.*(&MyStruct::Print))(42) 호출

 멤버 함수 호출 시

	auto boundFunc = std::bind(&MyStruct::Print, &obj, std::placeholders::_1);

	멤버 함수 포인터 + 객체 주소 + 인자 바인딩을 암묵적으로 처리

	boundFunc(숫자);
    */


    

#pragma endregion



    /*
   ✅ [capture](parameters) -> return_type {
    // 함수 내용
        };
    []: 외부 변수 캡처 (capture)
    () : 함수 인자 (parameters)
    -> return_type : (선택) 리턴 타입

  🔹 2. 캡처 방식 요약
     문법	의미
     [a]	a를 값으로 복사
     [&b]	b를 참조로 사용
     [=]	사용한 모든 외부 변수 값 복사
     [&]	사용한 모든 외부 변수 참조 캡처
     [=, &c]	모두 값으로, c만 참조
     [&, b]	모두 참조로, b만 값
     
  🔹 3. 예시
     
     int a = 10;
     auto lambda = [a](int x) {
         return a + x;
     };
     int result = lambda(5); // result = 15
  🔹 4. 함수처럼 즉시 호출
     
     []() {
         std::cout << "Hello\n";
     }();  // () 붙이면 즉시 실행
  🔹 5. std::function에 람다 저장
     
     std::function<int(int, int)> f = [](int a, int b) {
         return a + b;
     };
  🔹 6. 리턴 타입 명시 (생략 가능)
     
     [](int a, int b) -> float {
         return a / (float)b;
     };
         
         
         */


/*
🔺 업캐스팅 (Upcasting)
정의: 자식 클래스 포인터(또는 참조)를 부모 클래스 포인터(또는 참조)로 바꾸는 것

형태:
Dog* d = new Dog();
Animal* a = d;  // 업캐스팅 (암시적 가능)

#특징:
암시적으로 가능 (Animal* a = new Dog();)

부모 타입의 멤버 함수만 호출 가능

그러나 virtual 함수가 있다면 자식의 재정의된 함수가 호출됨 (다형성)


#이점:
여러 자식 클래스 객체를 하나의 부모 타입으로 관리 가능

코드의 유연성과 재사용성 증가


예시:
Animal* a = new Dog(); // 업캐스팅
a->Speak();            // virtual 덕분에 Dog의 Speak() 실행




🔻 다운캐스팅 (Downcasting)
정의: 부모 클래스 포인터(또는 참조)를 자식 클래스 포인터(또는 참조)로 바꾸는 것

#형태:
Animal* a = new Dog();           // 업캐스팅
Dog* d = dynamic_cast<Dog*>(a);  // 다운캐스팅
특징:

명시적 형변환 필요

안전하게 사용하려면 dynamic_cast 사용

실패 시 nullptr 반환 → 꼭 체크해야 함

#이점:

자식 클래스 고유 기능 사용 가능 (예: Bark() 같은 자식 전용 함수)

#예시:
Animal* a = new Dog();           // 업캐스팅
Dog* d = dynamic_cast<Dog*>(a);  // 다운캐스팅
if (d) {
    d->Bark();                   // Dog만의 함수 사용 가능
}

✅ 실용적 사용 예 (다형성과 결합된 형태)
void MakeAnimalSpeak(Animal* a) {
    a->Speak();  // 어떤 동물이든 Speak 호출
}

int main() {
    Dog d;
    Cat c;
    MakeAnimalSpeak(&d);  // 출력: Dog sound
    MakeAnimalSpeak(&c);  // 출력: Cat sound
}



*/
    

/*
복사생성자: 새로운 객체를 생성할때 기존 객체의 값을 복사
FClass(const FClass& InOther)
    : Value(InOther.Value)                    // 얕은 복사<-주소값 복사
    , Pointer(new int(*InOther.Pointer))     // 깊은 복사: 새로운 메모리 할당 후 값 복사
    ㄴ멤버 변수가 포인터
    , SharedPtr(new int(*InOther.Pointer))   // 깊은 복사: 새로운 메모리 할당 후 값 복사
    ㄴ멤버 변수가 스마트 포인터
{}


복사대입연산자: 두 객체가 있을대 대입
void operator=(const int InValue)
{
    Value = InValue;
}

void operator=(const FClass& InOther)
{
    Value = InOther.Value;
    *Pointer = *InOther.Pointer;
    *SharedPtr = *InOther.SharedPtr;
}


*/

/*
기본적인 싱글톤 클래스 https://hwan-shell.tistory.com/227
ㄴ전역에서 한개의 인스턴스만 생성해서 다른 변수들은 한개의 인스턴스만 참조한다, 결국 주소값이 같다.

lass FAssetManager
{
public:
    static FAssetManager* Get()
    {
        static FAssetManager Instance;
        return &Instance;
        ㄴinstance의 타입이 FAssetManager이기 때문에 함수 반환형도 동일
    }

    void Initialize(int InWidth, int InHeight)
    {
        Width = InWidth;
        Height = InHeight;
        std::cout << std::format("가로: {}, 세로: {}", Width, Height);
    }

private:
    FAssetManager() = default;
    ~FAssetManager() = default;

    FAssetManager(const FAssetManager&) = delete;
    FAssetManager& operator=(const FAssetManager&) = delete;
    ㄴ사용안하겠다는 의미

private:
    int Width = 0;
    int Height = 0;
};

int main()
{
FAssetManager a;
FAssetManager b;
ㄴ여기는 서로 다른 객체 생성. 싱클턴이 아님

FAssetManager* a = FAssetManager::Get();
FAssetManager* b = FAssetManager::Get();
ㄴa, b모두 한개의 인스턴스를 가리킴

FAssetManager::Get()->Initialize(128, 256);
ㄴ 바로 접근.

}


캐스팅에서 virtual이 소멸자에도 있으면 dynamic_cast가능



*/

/*
#pragma once
#include <vector>

inline int Sum(const int a, const int b) 메인함수에 sum복사
{
    return a + b;
}

inline double Sum(const double a, const double b = 20.f)
{
    return a + b;
}

아래가 템플릿

// T는 내가 원하는 이름을 넣으시면 됩니다
//template<class T>
template<typename T>
T TemplateSum(T a, T b)
{
    return a + b;
}

template<class RetType, class T1, class T2=int>
RetType TemplateSum2(T1 a, T2 b)
{
    return a + b;
}


#include <iostream>
#include "Template.h" <-포함

struct FStruct
{
    FStruct operator+(const FStruct& InOther)
    {
        FStruct Instance;
        Instance.Val0 = Val0 + InOther.Val0;
        Instance.Val1 = Val1 + InOther.Val1;
        return Instance;
    }

    int Val0 = 0;
    int Val1 = 0;
};

int main()
{
    {
        int Result = Sum(10, 20);
        double Result2 = Sum(10.5, 20.3);
    }
    {
        int Result = TemplateSum<int>(10, 20);
        double Result2 = TemplateSum<double>(10.5, 20.3);
        float Result3 = TemplateSum<float>(10.5f, 20.3f);
        int Result4 = TemplateSum(10, 20);
        ㄴ정수 대입이라 템플릿도 정수로 실행

            FStruct A, B;
        A.Val0 = 10;
        B.Val0 = 20;

        FStruct C = TemplateSum(A, B);
        ㄴoperate + 로 템플릿에 호풀됬을때 둘이 더해짐.
    }

    {
        double Result = TemplateSum2<double, int, float>(10, 30.5f);
        double Result = TemplateSum2<double, int>(10, 10);
        ㄴ템플릿 클래스에 반환형 부여 가능
    }
}*/

#pragma region Vector의 활용, 이터레이터(iterator), Operator, 구조체 Vector

    {
        {
            std::vector Vector{ 0, 1, 2 };
            Vector.push_back(33);
        }
        {
            // 대략적으로 또는 명확하게 size를 예상할 수 있는 경우 반드시



            std::vector<int> Vector;
            Vector.reserve(100); 			// reserve: capacity(용량)만 확보->메모리 공간을 미리 확보한다. (100개)
            for (size_t i = 0; i < 100; ++i)
            {
                Vector.push_back(i); // O(1)
            }
            Vector.push_back(1111);
        }
        {
            std::vector<int> Vector;
            Vector.resize(100);			// resize(할당 + 초기화)또는 reserve(할당)로 공간을 할당해두자
            // resize: 용량 확보 이후 데이터 생성->0으로
            for (size_t i = 0; i < 100; ++i)
            {
                Vector[i] = i;
                Vector.at(i) = i + 1;
            }
            Vector.push_back(100);
        }


        // erase, insert
        {
            std::vector<int> Vector{ 0, 1, 2, 3, 4, 5 };
            Vector.erase(Vector.begin() + 2); // O(N) (2번 인덱스 삭제)
            Vector.insert(Vector.begin() + 2, 99); // O(N) (2번 인덱스에 99 삽입)

            std::vector<int>::iterator It = std::find(Vector.begin(), Vector.end(), 99); // O(N) (99를 찾는다)->있으면 It에 주소반환


            // 못찾았나요?
            if (It == Vector.end())
            {

            }
            // 찾았나요?
            else if (It != Vector.end())
            {
                Vector.erase(It);  //해당부분 삭제
            }
        }

        {
            // 백터 안에 백터
            std::vector<std::vector<int>> Vector;
            Vector.resize(10);
            for (int i = 0; i < 10; ++i)
            {
                Vector[i].resize(10);
            }
        }

        {

            {
                struct FItem
                {
                    int ID = 0; // 아이템 고유 번호
                    int Rarity = 1; // 희귀도
                    int Attributes[10] = {}; // 추가 능력치

                    FItem() {}
                    FItem(int InID, int InRarity)
                        : ID(InID), Rarity(InRarity)
                    {
                        for (int i = 0; i < 10; ++i)
                        {
                            Attributes[i] = i;
                        }
                    }
                    FItem(const FItem& Other)		//복사생성: 새 객체를 기존 객체로 재 생성할때 자동 호출
                        : ID(Other.ID), Rarity(Other.Rarity)
                    {
                        for (int i = 0; i < 10; ++i)
                        {
                            Attributes[i] = Other.Attributes[i];
                        }
                    }

                    bool operator==(const FItem& Other) const		//연산자 오버로딩: 객체끼리도 연산을 직관적으로 할 수 있게 해준다.
                    {
                        if (ID != Other.ID || Rarity != Other.Rarity) return false;

                        for (int i = 0; i < 10; ++i)
                        {
                            if (Attributes[i] != Other.Attributes[i]) return false;
                        }

                        return true;
                    }
                };

                std::vector<FItem> Inventory;    	    // FItem타입의 인벤토리 벡터
                Inventory.reserve(10);               		// 미리 10개 공간 확보
                FItem SearchItem;
                SearchItem.ID = 101;                // 찾고자 하는 아이템 코드 (기존 객체)

                Inventory.push_back(FItem(10, 2));   // 1번 슬롯: 임시 아이템 생성 → 복사 생성자로 인벤토리에 복사
                Inventory.emplace_back(10, 2);       // 2번 슬롯: 직접 생성자 호출하여 인벤토리에 생성
                Inventory.emplace_back(20, 3);       // 3번 슬롯: 생성자 호출
                Inventory.emplace_back(SearchItem);  // 4번 슬롯: 복사 생성자 호출



                // 반복자를 통해 SearchItem과 같은 아이템을 인벤토리에서 찾기
                std::vector<FItem>::iterator It = std::find_if(Inventory.begin(), Inventory.end(),
                    [&SearchItem](const FItem& Item) -> bool
                    {
                        return Item == SearchItem;
                    }
                );

                if (It != Inventory.end()) //이터레이터는 컨테이너안에 요소를 가리킴. 객체가 있으면 (->)
                {
                    std::cout << "찾음! ID: " << It->ID << ", Rarity: " << It->Rarity << std::endl;
                }
                else
                {
                    std::cout << "못 찾음" << std::endl;
                }


            }

        }
    }

  #pragma endregion
#pragma region List
    {
        {
            std::list<std::string> Inventory;

            // 인벤토리에 아이템 추가 (뒤에 붙이기)
            Inventory.push_back("검");
            Inventory.push_back("방패");
            Inventory.push_back("활");
            Inventory.push_back("포션");
            Inventory.push_back("망토");

            // Iterator를 사용해서 포인터처럼 위치 이동
            std::list<std::string>::iterator It = Inventory.begin(); // "검"
            ++It;  // "방패"
            ++It;  // "활" ← 여기 앞에 새 아이템 추가할 예정

            // 중간에 아이템 삽입 ("활" 앞에 "전설의 검" 삽입)
            Inventory.insert(It, "전설의 검");

            // 인벤토리 전체 출력 - range 기반 for문
            std::cout << "[인벤토리 아이템 목록 - range for]\n";
            for (const std::string& Item : Inventory)
            {
                std::cout << "- " << Item << std::endl;
            }

            // 반복자(iterator)를 사용한 출력
            std::cout << "\n[인벤토리 아이템 목록 - iterator for]\n";
            for (std::list<std::string>::iterator It = Inventory.begin(); It != Inventory.end(); ++It)
            {
                std::cout << "- " << *It << std::endl;
            }

            // auto를 이용한 간단한 iterator
            std::cout << "\n[인벤토리 아이템 목록 - auto iterator for]\n";
            for (auto It = Inventory.begin(); It != Inventory.end(); ++It)
            {
                std::cout << "- " << *It << std::endl;
            }
        }
    }
#pragma endregion
#pragma region Queue
    {
        #pragma region Queue
        // [Queue]: 선입선출(FIFO, First In First Out) 구조입니다.
        // 먼저 들어온 명령이 먼저 처리됩니다.

        {
            std::cout << "[명령 대기열 Queue]\n";

            std::queue<int> CommandQueue;

            // 명령을 큐에 추가 (0부터 9까지 순서대로)
            for (int i = 0; i < 10; ++i)
            {
                CommandQueue.push(i);
                // queue는 인덱스로 접근 불가 (random access 불가능)
                // 예: CommandQueue[2]; 는 에러입니다.
            }

            // 명령 처리: 가장 오래된 명령부터 하나씩 꺼냄
            while (!CommandQueue.empty())
            {
                int Command = CommandQueue.front(); // 가장 앞 명령 확인
                CommandQueue.pop();                  // 처리 후 제거
                std::cout << "처리된 명령: " << Command << "\n";
            }
        }
#pragma endregion

#pragma region PriorityQueue
        // [priority_queue]: 우선순위 큐
        // 기본적으로 큰 값이 높은 우선순위를 가집니다.
        // 아래는 std::greater<int>를 써서 '낮은 값이 높은 우선순위'로 동작합니다.
        {
            std::priority_queue<int, std::vector<int>, std::greater<int>> PriorityQueue;

            PriorityQueue.push(50);  // 명령 우선순위 값 (낮을수록 먼저 처리됨)
            PriorityQueue.push(40);
            PriorityQueue.push(70);
            PriorityQueue.push(30);
            PriorityQueue.push(100);

            std::cout << "\n[우선순위 명령 대기열 PriorityQueue]\n";

            while (!PriorityQueue.empty())
            {
                int Command = PriorityQueue.top(); // 가장 높은 우선순위 명령 확인
                PriorityQueue.pop();                // 처리 후 제거
                std::cout << "처리된 우선 명령: " << Command << "\n";
            }
        }
#pragma endregion

#pragma region MultiQueue_ByPriority
        // 여러 부대(우선순위 그룹) 별로 큐를 분리해 명령 처리하기

        {
            std::queue<int> RegularUnitQueue;   // 일반 부대 명령 큐
            std::queue<int> EliteUnitQueue;     // 정예 부대 명령 큐
            std::queue<int> SpecialForceQueue;  // 특수 부대 명령 큐

            // 부대 구분을 위한 열거형 (enum class)
            enum class EPriority
            {
                RegularUnit,    // 일반 부대
                EliteUnit,      // 정예 부대
                SpecialForce    // 특수 부대
            };

            // 명령을 우선순위에 맞춰 각 큐에 넣는 함수
            // std::function 사용 이유:
            //  - 람다, 함수 포인터, 함수 객체 등을 모두 담을 수 있어서 유연하다
            //  - 캡쳐(&)로 외부 변수(큐)를 직접 사용할 수 있어 편리하다
            std::function<void(EPriority, int)> EnqueueCommand = [&](EPriority UnitType, int Command)
                {
                    switch (UnitType)
                    {
                    case EPriority::RegularUnit:
                        RegularUnitQueue.push(Command);
                        break;
                    case EPriority::EliteUnit:
                        EliteUnitQueue.push(Command);
                        break;
                    case EPriority::SpecialForce:
                        SpecialForceQueue.push(Command);
                        break;
                    default:
                        break;
                    }
                };

            // 명령 추가 (우선순위 별로)
            EnqueueCommand(EPriority::EliteUnit, 10000);
            EnqueueCommand(EPriority::RegularUnit, 150);
            EnqueueCommand(EPriority::EliteUnit, 140);
            EnqueueCommand(EPriority::SpecialForce, 130);
            EnqueueCommand(EPriority::EliteUnit, 1300);
            EnqueueCommand(EPriority::SpecialForce, 21300);

            // 각 부대 명령 출력 및 처리
            std::cout << "\n[일반 부대 명령]\n";
            while (!RegularUnitQueue.empty())
            {
                std::cout << "-> " << RegularUnitQueue.front() << "\n";
                RegularUnitQueue.pop();
            }

            std::cout << "\n[정예 부대 명령]\n";
            while (!EliteUnitQueue.empty())
            {
                std::cout << "-> " << EliteUnitQueue.front() << "\n";
                EliteUnitQueue.pop();
            }

            std::cout << "\n[특수 부대 명령]\n";
            while (!SpecialForceQueue.empty())
            {
                std::cout << "-> " << SpecialForceQueue.front() << "\n";
                SpecialForceQueue.pop();
            }
        }
    }
#pragma endregion
#pragma endregion
#pragma region  Stack 해야함
#include <iostream>
#include <stack>

    
    {
        std::stack<int> CommandStack;

        std::cout << "\n[명령 입력 순서 - push()]\n";
        for (int i = 0; i < 10; ++i)
        {
            std::cout << "명령 추가: " << i << std::endl;
            CommandStack.push(i); // i번째 명령을 입력 (0 ~ 9)
        }

        std::cout << "\n[명령 처리 순서 - pop()]\n";
        while (!CommandStack.empty())
        {
            int CurrentCommand = CommandStack.top(); // 가장 마지막 명령 확인
            std::cout << "명령 처리: " << CurrentCommand << std::endl;
            CommandStack.pop(); // 가장 최근 명령 제거 (처리 완료)
        }
    }

#pragma endregion

#pragma region Pair

    // [Pair]: 두 데이터를 들고 있는 컨테이너
    

        //일반적인 pair방식과 출력
        {
            std::pair<int, std::string> Item1 = std::make_pair(1001, "검");
            std::pair<int, std::string> Item2 = { 1002, "방패" };

            std::cout << "Item1 - ID: " << Item1.first << ", Name: " << Item1.second << std::endl;
            std::cout << "Item2 - ID: " << Item2.first << ", Name: " << Item2.second << std::endl;
        }


        {
            struct FWeapon
            {
                int ID;
                std::string Name;

                FWeapon(int InID, const std::string& InName)
                    : ID(InID), Name(InName) {
                }
            };

            // 두 개의 FWeapon을 pair로 묶음
            std::pair<FWeapon, FWeapon> Weapons = {
                FWeapon(1001, "검"),
                FWeapon(1002, "방패")
            };

            std::cout << "\n무기1 - ID: " << Weapons.first.ID << ", Name: " << Weapons.first.Name << std::endl;
            std::cout << "무기2 - ID: " << Weapons.second.ID << ", Name: " << Weapons.second.Name << std::endl;
        }



#pragma endregion 
#pragma region Map
        // map: 내부적으로 pair (키, 값)를 저장하는 정렬된 컨테이너
    // #include <map>
    // 내부는 레드-블랙 트리로 구현됨 (자동 정렬 트리)
    // 키 기준 자동 정렬 (기본: 오름차순)
    // insert/emplace/find 등으로 검색, 삽입, 삭제 가능


        {
            {
                // Map 예시: (아이템ID, 아이템이름)
                std::map<int, std::string/*, std::greater<int>*/> Map;

                // pair를 먼저 만들어 넣을 수도 있고
                std::pair<int, std::string> Pair = { 1, "포션" };

                // 여러 가지 방식으로 키-값 쌍을 삽입
                Map.emplace(2, "에테르");
                Map.insert(std::make_pair(0, "힐링포션"));

                // 키 중복이면 무시됨 (0은 이미 있음)
                Map.insert(std::make_pair(0, "중복시도"));

                Map.insert(Pair); // (1, "포션")

                // [] 방식 접근: 있으면 반환, 없으면 기본 생성된 값으로 추가
                std::string Value = Map[1]; // → "포션"
                std::string& Value2 = Map[200]; // 존재하지 않으므로 "빈 문자열" 생성됨
                Value2 = "희귀 아이템";

                // contains: 해당 키가 존재하는지 확인
                bool bContains = Map.contains(200); // true
                if (bContains)
                {
                    std::string& Value3 = Map[200]; // 접근 가능
                }

                bContains = Map.contains(300); // false
                if (!bContains)
                {
                    std::cout << "해당 키(300)를 찾을 수 없습니다!\n";
                }

                // find: 반복자 방식 접근 (존재 시 위치 반환, 없으면 Map.end())
                std::map<int, std::string>::iterator It = Map.find(1);
                It->second = "업그레이드 포션";

                auto It2 = Map.find(2);
                auto ItNotFound = Map.find(5);
                if (ItNotFound == Map.end())
                {
                    std::cout << "해당 키(5)를 찾을 수 없습니다!\n";
                }

                // 전체 출력 (정렬된 순서로 출력됨)
                std::cout << "\n[아이템 목록]\n";
                for (auto It = Map.begin(); It != Map.end(); ++It)
                {
                    std::cout << std::format("아이템ID: {}, 이름: {}\n", It->first, It->second);
                }

                // 전체 값을 일괄 수정
                for (auto& Pair : Map)
                {
                    Pair.second = "삭제된 아이템";
                }
            }

            {
                // 플레이어 정보 구조체 정의
                struct FPlayerInfo
                {
                    FPlayerInfo() {}
                    FPlayerInfo(int InPlayerUID, std::string InPlayerName, int InHP, int InMP)
                        : PlayerUID(InPlayerUID), PlayerName(InPlayerName), HP(InHP), MP(InMP)
                    {
                    }

                    int PlayerUID = 0;
                    std::string PlayerName;
                    int HP = 100;
                    int MP = 0;

                    // map에 넣기 위해 비교 연산자 필요 (키 정렬 기준)
                    bool operator<(const FPlayerInfo& InOther) const
                    {
                        return PlayerUID < InOther.PlayerUID;
                    }
                };

                {
                    // 키: Player 이름, 값: FPlayerInfo
                    std::map<std::string, FPlayerInfo> PlayerMap;

                    // try_emplace → 없을 때만 삽입 (중복 방지)
                    for (int i = 0; i < 20; ++i)
                    {
                        std::string PlayerName = "Player" + std::to_string(i);
                        //to_string을 이용해 플레이어넘버를 붙여서 Playername에 저장
                        PlayerMap.try_emplace(PlayerName, i, PlayerName, 100, i);
                    }

                    const std::string Key = "Player1";
                    if (PlayerMap.contains(Key))
                    {
                        FPlayerInfo& PlayerInfo = PlayerMap[Key];
                        std::cout << std::format("\n[{} 정보] HP: {}, MP: {}\n", Key, PlayerInfo.HP, PlayerInfo.MP);
                        PlayerMap.erase(Key); // 삭제 예시
                    }
                }

                // ※ 구조체 자체를 키로 쓸 수도 있음 (operator< 필요)
                /*
                std::map<FPlayerInfo, FPlayerInfo> PlayerMap;
                for (int i = 0; i < 20; ++i)
                {
                    std::string PlayerName = "Player" + std::to_string(i);
                    FPlayerInfo PlayerInfo(i, PlayerName, 100, i);
                    PlayerMap.try_emplace(PlayerInfo, PlayerInfo);
                }

                FPlayerInfo PlayerInfo(0, "", 100, 0);
                bool bContains = PlayerMap.contains(PlayerInfo);
                if (bContains)
                {
                    FPlayerInfo& FindPlayerInfo = PlayerMap[PlayerInfo];
                }
                */
            }

        }
#pragma endregion
#pragma region Hash
        {
            {
                std::hash<std::string> WeaponHash;
                std::string String = "검";
                std::string String2 = "방패";
                size_t Hash = WeaponHash(String);
                size_t Hash2 = WeaponHash(String2);

                // 서로 더른 입력값의 해쉬 결과가 극히 낮은 확률로 동일 할 수 있다
                // 이를 Hash 충돌 이라고 한다
            }
            {
                std::hash<int> IntHashFunction;
                size_t Hash = IntHashFunction(10);
                size_t Hash2 = IntHashFunction(20);
            }
            {
                using FHashKey = size_t;
                struct FStruct
                {
                    std::string WeaponName;
                    int Damage = 1;
                    int Durability = 100;

                    FHashKey HashKey = 0;

                    FStruct(std::string_view InName, int InValue, int InValue2)
                        : WeaponName(InName), Damage(InValue), Durability(InValue2)
                    {
                        HashKey = GetHash(); //생성자-> 해쉬 함수 호출
                    }

                    [[nodiscard]] FHashKey GetHash() const
                    {
                        //if (HashKey == 0)
                        {
                            // 여러 필드를 조합할 때 순서와 충돌을 줄이기 위해 시프트 + XOR를 사용
                            return std::hash<std::string>()(WeaponName)
                                ^ (std::hash<int>()(Damage) << 1)
                                ^ (std::hash<int>()(Durability) << 2);
                        }

                        //return HashKey;
                    }

                    bool operator==(const FStruct& InOther) const
                    {
                        return GetHash() == InOther.GetHash();
                    }
                };

                FStruct WP1 = FStruct("검", 50, 100);
                FStruct WP2 = FStruct("활", 30, 80);
                FStruct WP3 = FStruct("활", 30, 80);

                FHashKey WPH1 = WP1.GetHash();
                unsigned long long WPH1_1 = WP1.GetHash();
                //해쉬값을 표현해주기 위한거라 부호없는 8바이트 가능

                FHashKey WPH2 = WP2.GetHash();
                FHashKey WPH3 = WP3.HashKey;

                if (WPH1 == WPH2)
                {
                    std::cout << "무기1과 2는 같다\n";
                }
                else {

                    std::cout << "무기1과 2는 다르다\n";
                }

                if (WPH1 == WPH1_1)
                {
                    std::cout << "무기1과 1_1은 같다\n";
                }
                else {

                    std::cout << "무기1과 1_1은 다르다\n";
                }

                if (WPH2 == WPH3)
                {
                    std::cout << "무기2과 3는 같다\n";
                }
                else {

                    std::cout << "무기2과 3는 다르다\n";
                }
            }
        }    
#pragma endregion

#pragma region unordered map
        {
        
                        //	    map							unordered_map
                // 순서	오름차순정렬(바꾸기가능)	정렬 안함
                // 구현	Red Black Tree				Hash Table
                // 탐색 시간	log(n)						O(1)
                // 삽입 시간	log(n)						O(1)
                // 
                // 비정렬 연관 컨테이너(unordered associative container) / 해시 테이블
                // #include <unordered_map>
                // map은 키 기반으로 정렬을 해줬으나, 예는 안해준다{
                // hashmap으로 구현되어 있어서, 이름이 hash_map이면 좋겠지만, C++11에 추가되어(상대적으로 늦게)
                // 이미 많은 서드파티 라이브러리들이 hash로 시작하는 이름이 많아서 hash 대신 unordered란 접두어를 사용했다고 함 (표준위원회가)
                // 사용법은 unordered_map은 원소를 정렬하지 않는다는 점을 제외하면 map과 동일합니다.
                // 원소를 추가하고 삭제하고 조회하는 연산의 속도는 대체로 상수시간이고, 최악의 경우라도 선형 시간에 처리됩니다.
                // 원소를 조회하는 속도는 map보다 훨씬 빠릅니다.

                {   //선언 및 키 or 키값 변경

                    std::unordered_map<int, std::string> UnorderedMap;
                    UnorderedMap.insert(std::make_pair(999, "Test999"));
                    UnorderedMap.emplace(997, "키가변값");

                    for (int i = 0; i <= 20; ++i)
                    {
                        UnorderedMap[i] = "Test" + std::to_string(i);
                    }

                    //키 삭제
                    auto it = UnorderedMap.find(997); //1찾아서 it에 저장 std::unordered_map<int, std::string>::iterator
                    if (it != UnorderedMap.end()) {
                        std::string exchange = it->second;  // 값 백업
                        UnorderedMap.erase(it);                   // 기존 키 삭제

                        UnorderedMap[20] = exchange;
                        UnorderedMap[9999] = exchange;  // 만들었던 키 or 새로운 키에 삽입
                    }

                    if (UnorderedMap.contains(2))
                    {
                        std::string& Value = UnorderedMap[2]; //키값
                        Value = "AAA";
                    }

                    std::unordered_map<int, std::string>::iterator It = UnorderedMap.find(2);
                    if (It != UnorderedMap.end())
                    {
                        It->second = "BBB";
                    }
                }

                

                    // 키값에 따라 정보 분리가 필요한 경우(예를 들어, 학생 성적 정보(학생 이름, 점수))-> 구조체 사용 
                {
                        struct FPlayer
                        {
                            int Number;
                            int UID;
                            std::string Name;

                            size_t MakeHash() const
                            {
                                return std::hash<int>()(Number)
                                    ^ (std::hash<int>()(UID) << 1)
                                    ^ (std::hash<std::string>()(Name) << 2);
                                /*
                                std::size_t NumberHash = std::hash<int>{}(Player.Number);
                                std::size_t UIDHash = std::hash<int>{}(Player.UID);
                                std::size_t NameHash = std::hash<std::string>{}(Player.Name);

                                return ScoreHash ^ (NumberHash << 1)^ (NameHash << 2);*/
                            }

                            bool operator==(const FPlayer& Other) const
                            {
                                return MakeHash() == Other.MakeHash();
                            }
                        };

                        struct FPlayerHash
                        {
                            std::size_t operator()(const FPlayer& Player) const
                            {
                                return Player.MakeHash();
                            }
                        };




                        std::unordered_map<FPlayer, int, FPlayerHash> PlayerMap;
                        //std::unordered_map<키값타입, 값타입, 키값 저장 방식 객체> PlayerMap;

                        FPlayer P1{ 1, 85, "다오" };
                        FPlayer P2{ 2, 34, "마리드" };
                        FPlayer P3{ 3, 67, "투탑" };

                        PlayerMap[P1] = 120; //구조체 키에 해당하는 값들
                        PlayerMap[P2] = 80;
                        PlayerMap[P3] = 95;


                        for (const auto& Pair : PlayerMap)
                        {
                            std::cout << "Number: " << Pair.first.Number
                                << ", UID: " << Pair.first.UID
                                << ", Name: " << Pair.first.Name
                                << ", Score: " << Pair.second << '\n';
                        }





                    }




        }
#pragma endregion
}






//#pragma region
//#pragma endregion






