#include <iostream>

// C++에서 반드시 알아야 하는 규칙
// => 기반 클래스의 소멸자는 "public virtual"이거나
// => "protected non-virtual" 이어야 한다!

class Base
{
public:
	virtual ~Base() {} // virtual로!
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; } // Base가 virtual이면 얘도 virtual
};
int main()
{
	//Derived d;

	//Derived* p1 = new Derived;	// 객체 생성
	//delete p1;	// 객체 파괴

	Base* p2 = new Derived;
	delete p2;
	// 핵심.
	// 소멸자도 함수 호출.
	// 1. 컴파일러는 p2가 "Base*이므로 Base에서 소멸자가 가상인지 조사
	// => Base는 소멸자가 가상함수가 아니면 무조건 포인트 타입으로 호출
	// => ~Base() 함수만 호출

	// 해결책.
	// 소멸자가 가상함수라면 p가 가리키는 메모리의 객체를 조사하는 코드를 생성하고
	// 실행 시 조사해서 소멸자 호출을 결정
}	
