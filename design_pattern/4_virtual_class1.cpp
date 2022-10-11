// 1_추상클래스1.cpp - 10page

// 추상 클래스 : 순수 가상함수가 한개 있는 클래스
// 특징 : 객체를 생성할 수 없음.
class Shape
{
public:
	virtual void Draw() = 0;
	// 순수 가상함수 "pure virtual function"
	// 구현부가 없고 "=0"으로만 표기

	// 의도가 핵심.
	// 모든 파생 클래스는 Draw() 를 구현하라는 지시!
};

class Rect : public Shape
{
	// 핵심
	// Rect가 "Draw()"의 구현부를 제공하지 않으면
	// Rect도 추상 클래스
};

class Rect2 : public Shape
{
	virtual void Draw() override {}
};

int main()
{
//	Shape  s; 
	// 추상 클래스는 객체 생성 안됨

	Shape* p;

//	Rect  r;
	// 역시 추상 클래스는 객체 생성 안됨

	Rect2 r2;
}
