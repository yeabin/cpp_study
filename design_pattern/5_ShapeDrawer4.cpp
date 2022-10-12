#include <iostream>
#include <vector>

// 핵심5.
// Polymorphism
// 객체 지향 언어의 특징 : 캡슐화, 상속, 다형성

class Shape
{
	int color;
public:
	void SetColor(int c) { color = c; }
	int GetColor() const { return color; }

	virtual void Draw() { std::cout << "Draw Shape" << std::endl; }
};

class Rect : public Shape
{
public:
	virtual void Draw() override { std::cout << "Draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	virtual void Draw() override { std::cout << "Draw Circle" << std::endl; }
};

class Triangle : public Shape
{
public:
	virtual void Draw() override { std::cout << "Draw Triangle" << std::endl; }
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
			Rect* p = new Rect;
			v.push_back(p);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw();
			// "Polymorphism"
			// 동일한 표현식이 실제 객체에 따라 다른 함수 호출 됨
			// 새로운 클래스 추가되어도, 수정될 필요가 없음.
			// => OCP 만족하는 좋은 코드

		}
	}
}

