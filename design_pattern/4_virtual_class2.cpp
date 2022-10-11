//1_추상클래스2.cpp
#include <iostream>

// "OCP"
// 기능 확장에 Open
// 코드 수정에는 Closed
// 하도록 디자인 하라는 원칙 Principle
// => "SOLID" : SRP, OCP, LSP, ISP, DIP

// "Tightly Coupled"
// 클래스에서 다른 클래스 이용 시, 클래스 이름을 직접 사용하는 것
// 교체 불가능한, 경직된 디자인.
// OCP 만족하지 않음

class Camera
{
public:	
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void UseCamera(Camera* p) { p->Take(); }
	void UseCamera(HDCamera* p) { p->Take(); }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);
}





