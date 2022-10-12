#include <iostream>
#include <vector>

// 핵심3.
// 모든 파생클래스의 공통 특징은
// 반드시 기반 클래스에 있어야 함.
// => Draw() 가 Shape에 있어야 함.
class Shape
{
	int color;
public:
	// 핵심4.
	// 기반 클래스의 멤버 함수 중,
	// 파생 클래스가 재정의 할 필요 없는 것은 "non-virtual"
	void SetColor(int c) { color = c; }
	int GetColor() const { return color; }

	// 파생 클래스가 재정의 할 것은 "virtual"
	virtual int GetArea() const { return -1; }
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
	}
}
