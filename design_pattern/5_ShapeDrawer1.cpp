#include <iostream>
#include <vector>

// 핵심1.
// 모든 도형을 타입화

// 핵심2.
// 모든 도형의 공통 기반 클래스가 있다면, 하나의 container에 묶어서 보관할 수 있다.

class Shape
{

};

class Rect : public Shape
{
public:
	void Draw() { std::cout << "Draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void Draw() { std::cout << "Draw Circle" << std::endl; }
};


int main()
{
	// Rect와 Circle을 하나의 container에 보관해야 함
	// 그리는 순서를 알아야, 겹치는 경우에 대한 구현이 가능하기 때문
	std::vector<Shape*> v;
}

