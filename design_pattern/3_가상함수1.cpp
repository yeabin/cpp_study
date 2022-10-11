#include <iostream>

class Animal
{
public:
	void cry1() { std::cout << "Animal Cry1" << std::endl; }
	
	// "Virtual Function"
	// 함수 호출할 때 컴파일 시간이 아닌 실행 시간에 메모리 조사 후 결정해 달라는 것
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};
class Dog : public Animal
{
public:
	// "Function Override"
	// 기반 클래스 멤버 함수를 파생 클래스가 다시 만드는 것
	void cry1() { std::cout << "Dog Cry1" << std::endl; }
	
	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; }
};
int main()
{
	Dog d;
	Animal* p = &d; 

	p->cry1();
	// 당연히 Dog Cry를 불러야 할 타이밍
	// but, in C++, compiler가 멤버 함수 호출을 결정 ! => Animal Cry
	// 원리: "포인터 타입"으로 호출
	// => 장점: 컴파일 할 때 모든 것이 결정됨. 실행 시 오버헤드가 없다.

	p->cry2();
	// 만약 함수가 virtual 이라면
	// 컴파일 할 때 p가 가리키는 메모리를 조사하는 기계어 코드 생성
	// => p가 가리키는 객체를 조사하여 호출
	// => 장점 : 논리적으로 맞는 호출
	// => 단점 : 실행시간에 조사해야 하므로 느리다.
	// => Dog Cry

}


