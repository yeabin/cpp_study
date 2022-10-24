#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

// Rect, Circle 도형 외에 다른 도형 추가하고 싶을 때,
// => 근데 Factory class에 type을 매번 추가하고, Shape의 파생 클래스를 만들면
// => 추가될 때마다 main 코드가 수정되어야 하고 OCP 만족을 못함
class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
	virtual Shape* clone() const = 0;
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();
	// 함수 포인터 타입
	// using을 이용하여 별칭 생성 가능
	// "type alias"
	// => CREATOR라는 콜백을 파라미터로 받는 함수를 만들 수 있음.
	std::map<int, CREATOR> create_map;

public:
	// 아래는 나쁜 예시.
	//Shape* Create(int type)
	//{
	//	Shape* p = nullptr;
	//	if (type == 1)	p = new Rect;
	//	else if (type == 2)	p = new Circle;
	//	return p;
	//}

	void Register(int key, CREATOR f)
	{
		create_map[key] = f;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;

		if (create_map[type] != nullptr)
		{
			p = create_map[type]();
		}

		return p;
	}
};

// main에 공장 제품 등록을 매번 하고 싶지 않고,
//factory.Register(1, &Rect::create);
//factory.Register(2, &Circle::create);
// 미리 pre-set을 만들어두면 자동으로 등록하게 하고 싶음
struct AutoRegister
{
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::getInstance().Register(key, f);
	}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// 자기 자신을 만드는 static 멤버 변수

	// => 객체를 만들 때 사용하기 좋은 방법
	// 1. Rect* p1 = new Rect;
	// 사용자가 클래스 이름을 알아야 함.
	// 자료구조에 클래스 이름등을 보관할 수 없고, 함수 인자로도 사용할 수 없음.
	// v.push_back("Rect")와 같이 문자열로 객체 생성도 불가능함
	//
	// 2. Rect* p1 = Rect::create();
	// 함수 주소만 알면 객체 생성 가능하다. 자료 구조에 보관도 가능하고 함수 인자로도 사용가능하다.
	static Shape* create() { return new Rect; }
	virtual Shape* clone() const override { return new Rect(*this); }

	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
	static Shape* create() { return new Circle; }
	virtual Shape* clone() const override { return new Circle(*this); }
	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::create);


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 아래 코드는 수정하고 싶지 않음.
	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8) // 1 ~ 7 을 도형번호로 예약
		{
			Shape* p = factory.Create(cmd);

			if (p != nullptr)
				v.push_back(p);
		}

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}
