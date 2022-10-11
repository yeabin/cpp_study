//생성자1.cpp - 3page
#include <iostream>

// 핵심 : 생성자 호출 원리
// 1. 컴파일러가 "기반 클래스 생성자를 호출"하는 코드를 Derived 생성자에 추가한 것


// 2. 기반 클래스(Base)에 디폴트 생성자가 없다면..?
// ==> 반드시 파생 클래스에서 기반 클래스 생성자를 명시적으로 호출하는 코드를 작성해야 한다.


class Base
{
public:
//	Base()     { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:					
	// 아래 라인에서 에러 남
//	Derived()	
	// 아래 처럼 사용자가 기반 클래스 생성자를 명시적으로 호출해야 한다.
	Derived() : Base(0)
	{ 
		std::cout << "Derived()" << std::endl;
	}
	// compiler가 변경한 코드
	// Derived() : Base()
	
	// 아래 라인에서 에러 남
//	Derived(int a)	
	// 아래 처럼 사용자가 기반 클래스 생성자를 명시적으로 호출해야 한다.
	Derived(int a): Base(a)
	{ 
		std::cout << "Derived(int)" << std::endl;
	}
	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 
	}
};
int main()
{
	Derived d1;
	Derived d2(5); 
	// 먼저 Derived를 부르는 것임. Base를 먼저 부르는 것이 아님.
	// 그런데 Base(int)가 먼저 출력되고 Derived()가 나중에 출력되는 이유?
	// 
	// compiler가 미리 만들어 주는 코드인
	// Derived(int a) : Base()
	// 코드를 먼저 부르기 때문임

	// 소멸자는 사용자가 만든 코드를 먼저 실행하고
	//

}