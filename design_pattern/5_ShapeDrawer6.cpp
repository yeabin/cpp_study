#include <iostream>
#include <vector>

// �ٽ�9.
// template method ����
// 
// => ��� Ŭ������ ������ ���� ��ü �帧�� ���� ��� �Լ� ����(Shape::Draw, public)
//    ���ؾ� �ϴ� �κи� ã�Ƽ� �����Լ��� �и�(Shape::DrawImp, protected)

// => �Ļ� Ŭ������ ���ϴ� ���� ���� �����Լ��� ������!!

class Shape
{
	int color;
public:
	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }

	virtual int GetArea() const { return -1; }

	// ���뼺�� �������� �и�
	// => ������ �ʴ� �ڵ� ���ο� �ִ� ���ؾ� �ϴ� �κ��� �и��Ǿ�� �Ѵ�.
	// => ���ϴ� �κ��� �����Լ��� �и�
protected:
	virtual void DrawImp()
	{
		std::cout << "Draw Shape" << std::endl;
	}

public:
	// �� ���� �����ڴ� "DrawImp"�� ������ �ϸ� �ȴ�!
	// ���� ��Ģ�� Draw�� �������� ����
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
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->Clone());
		}
	}
}