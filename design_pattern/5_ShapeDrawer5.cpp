#include <iostream>
#include <vector>

// �ٽ�6.
// "Replace conditiional with polymorphism"

// �ٽ�7.
// ������ ���� "GOF's Design Pattern" 23���� �ڵ� ��� Gang's of Four

// �ٽ�8.
// prototype ����
// �ߺ� ��ü�� �����, �ߺ��� ���纻�� ���� ��ü�� ����� ����

class Shape
{
	int color;
public:
	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }

	virtual int GetArea() const { return -1; }
	virtual void Draw() { std::cout << "Draw Shape" << std::endl; }

	// �ڽ��� ���纻�� ���� �� �ִ� �����Լ�
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
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->Clone());
			// ������. k��° ������ � �������� ���� ��.
			// => ���ο� ������ Triangle�� ���� �� Clone()�� �ݵ�� ������ ��...
		}
	}
}