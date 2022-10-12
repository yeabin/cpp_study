#include <iostream>
#include <vector>

// 핵심6.
// "Replace conditiional with polymorphism"

// 핵심7.
// 디자인 패턴 "GOF's Design Pattern" 23개의 코딩 기법 Gang's of Four

// 핵심8.
// prototype 패턴
// 견본 객체를 만들고, 견본의 복사본을 통해 객체를 만드는 패턴

class Shape
{
	int color;
public:
	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }

	virtual int GetArea() const { return -1; }
	virtual void Draw() { std::cout << "Draw Shape" << std::endl; }

	// 자신의 복사본을 만들 수 있는 가상함수
	virtual Shape* Clone() const
	{
		Shape* p = new Shape(*this);
		return p;
	}
};

class Rect : public Shape
{
public:
	virtual void Draw() override { std::cout << "Draw Rect" << std::endl; }

	virtual Shape* Clone() const
	{
		Rect* p = new Rect(*this);
		return p;
	}
};
class Circle : public Shape
{
public:
	virtual void Draw() override { std::cout << "Draw Circle" << std::endl; }

	virtual Shape* Clone() const
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
			// 다형성. k번째 도형이 어떤 도형인지 몰라도 됨.
			// => 새로운 도형인 Triangle을 만들 때 Clone()을 반드시 만들어야 함...
		}
	}
}