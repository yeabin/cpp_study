#include <iostream>
#include <vector>

// 핵심9.
// template method 패턴
// 
// => 기반 클래스가 변하지 않은 전체 흐름을 가진 멤버 함수 제공(Shape::Draw, public)
//    변해야 하는 부분만 찾아서 가상함수로 분리(Shape::DrawImp, protected)

// => 파생 클래스가 변하는 것을 담은 가상함수를 재정의!!

class Shape
{
	int color;
public:
	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }

	virtual int GetArea() const { return -1; }

	// 공통성과 가변성의 분리
	// => 변하지 않는 코드 내부에 있는 변해야 하는 부분은 분리되어야 한다.
	// => 변하는 부분을 가상함수로 분리
protected:
	virtual void DrawImp()
	{
		std::cout << "Draw Shape" << std::endl;
	}

public:
	// 각 도형 설계자는 "DrawImp"만 재정의 하면 된다!
	// 공통 규칙인 Draw는 변경하지 말라
	virtual void Draw() final
	{ 
		std::cout << "Mutex lock" << std::endl;
		DrawImp();
		std::cout << "Mutex unlock" << std::endl;
	}

	virtual Shape* Clone() const
	{
		Shape* p = new Shape(*this);
		return p;
	}
};

class Rect : public Shape
{
public:
	virtual void DrawImp() override { std::cout << "Draw Rect" << std::endl; }

	virtual Shape* Clone() const override
	{
		Rect* p = new Rect(*this);
		return p;
	}
};
class Circle : public Shape
{
public:
	virtual void DrawImp() override { std::cout << "Draw Circle" << std::endl; }

	virtual Shape* Clone() const override
	{
		Circle* p = new Circle(*this);
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw();
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->Clone());
		}
	}
}