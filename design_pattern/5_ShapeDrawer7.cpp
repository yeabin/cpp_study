#include <iostream>
#include <vector>

// 핵심 10. 코드 정리 !!

class NotImplemented {};

//---------------------------------------------------------------------------//
class Shape
{
	int color;
public:
	virtual ~Shape() {}
	// 기반 클래스 이므로 가상 소멸자!

	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }

protected:
	/*	virtual void DrawImp()
	{
		std::cout << "Draw Shape" << std::endl;
	}*/
	// 가상함수
	// 파생 클래스가 재정의 하지 않으면 default 구현 제공

	virtual void DrawImp() = 0;
	// 순수 가상함수
	//파생 클래스에게 반드시 만들어라.

public:
	virtual void Draw() final
	{
		std::cout << "Mutex lock" << std::endl;
		DrawImp();
		std::cout << "Mutex unlock" << std::endl;
	}

//	virtual Shape* Clone() const = 0;
	// 순수 가상 함수로 만드는 게 제일 좋음.

	virtual Shape* Clone() const
	{
		throw NotImplemented();
	}
	// 근데 이렇게 할 수도 있음.
	// 1. 파생 클래스가 Clone() 만들지 않고, 사용하지 않으면 ok
	// 2. 파생 클래스가 Clone() 만들지 않고, 사용하면 예외
	// 3. 파생 클래스가 Clone() 만들면, 사용 가능!

	virtual int GetArea() const { return -1; }
	// 순수 가상함수로 해도 되고,
	// 구현되지 않음을 나타내는 반환 값도 가능함.
};

//---------------------------------------------------------------------------//
class Rect : public Shape
{
public:
	virtual void DrawImp() override { std::cout << "Draw Rect" << std::endl; }

	// 가상함수 재정의 할 때, 반환 타입 변경 가능!
	// => 단, 상속 관계의 타입으로 변경해야 함.
//	virtual Shape* Clone() const
	virtual Rect* Clone() const override
	{
		Rect* p = new Rect(*this);
		return p;
	}
};

//---------------------------------------------------------------------------//
class Circle : public Shape
{
public:
	virtual void DrawImp() override { std::cout << "Draw Circle" << std::endl; }

	virtual Circle* Clone() const override
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