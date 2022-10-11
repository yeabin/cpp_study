#include <iostream>

// "Loosely Coupling"
// 하나의 클래스가 다른 클래스 사용 시,
// 규칙을 담은 인터페이스(추상클래스)를 사용하여 접근하는 것
// => 확장성 있는 유연한 디자인

// 추상 클래스 : 지켜야 하는 규칙(순수 가상함수) + 다른 멤버
// 인터페이스 : 지켜야하는 규칙(순수 가상함수)만 있는 경우

// C#, java에는 "interface"라는 키워드 존재
// C++에서는 추상클래스 문법으로 interface도 표현



//카메라가 지켜야 하는 규칙을 먼저 설계함
//규칙: 모든 카메라는 ICamera로부터 상속 받아야 함.
// => "모든 카메라는 아래 인터페이스를 구현해야 한다"라고 표현
// => Take() 함수 구현부를 만들어야 함.
struct ICamera
//	class ICamera
{
//public:
	virtual void Take() = 0;
	virtual ~ICamera() {} // 기반 클래스이므로 소멸자 반드시 가상함수로!
};
// "interface" 구현 시
// class가 아닌 struct로 설계하는 것이 편함
// => Dependancy Inversion Principle
// => 구체 구현에 의존하지 말고, 추상에 의존하라!!
// => ICamera*를 사용하라는 의미

class People
{
public:
	virtual void UseCamera(ICamera* p) { p->Take(); }
};

class Camera : public ICamera
{
public:
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take 4k Picture" << std::endl; }
};


int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	UHDCamera hc;
	p.UseCamera(&hc);

	UHDCamera uhc;
	p.UseCamera(&uhc);
}





