#include <iostream>

// C++에서 반드시 알아야 하는 규칙
// => 기반 클래스의 소멸자는 "public virtual"이거나
// => "protected non-virtual" 이어야 한다!

class Base
{
	// 가상함수의 오버헤드(가상함수 테이블)을 없애기 위해서
	// 가끔 소멸자를 "non-virtual", "protected"에 놓는 기술이 있습니다.
protected:
	~Base() {}
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};

int main()
{
	Base* p2 = new Derived;
//	delete p2; // compile error. 소멸자가 protected에 있으므로...

	// Solution
	delete static_cast<Derived*>(p2);

}
