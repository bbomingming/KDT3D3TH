#pragma once  // 메인 파일에 여러번 호출되도 한번만 포함해라라는 의미
enum EPropertyFlags : unsigned char
{

//              16진수	    2진수			
	ENone      = 0x00,	// 0000 0000	  
	Eproperty1 = 0x01,	// 0000 0001	  
	Eproperty2 = 0x02,	// 0000 0010	  
	Eproperty3 = 0x04,	// 0000 0011	  
	Eproperty4 = 0x08,	// 0000 0100	  
};

bool BackFlag(unsigned char target, unsigned char proprety);

/*
시프트 연산

1을 2진수로 표현하면 0000 0001
그렇기 때문에 1을 계속해서 왼쪽으로 옮겨주면
8가지 공간을 사용가능


*/


/*

1. 헤더파일과 cpp파일 사용방법
함수는 어디서든 선언만 되어있으면된다.


 
2. 비트플래그에서 옵션이 활성화가 되어있는지 확인

bool HasFlag([열거형 이름] [인자 이름], [열거형 이름] [인자 이름]) //[] <<미포함

if(target&checkOption){
    return  true;
}
return 0;



ctrl+h로 문서 내 이름 바꾸기



*/

 

