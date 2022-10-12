#include <iostream>
#include <vector>

// �ٽ�5.
// Polymorphism
// ��ü ���� ����� Ư¡ : ĸ��ȭ, ���, ������

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
			// ������ ǥ������ ���� ��ü�� ���� �ٸ� �Լ� ȣ�� ��
			// ���ο� Ŭ���� �߰��Ǿ, ������ �ʿ䰡 ����.
			// => OCP �����ϴ� ���� �ڵ�

		}
	}
}

