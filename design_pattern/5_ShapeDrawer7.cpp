#include <iostream>
#include <vector>

// �ٽ� 10. �ڵ� ���� !!

class NotImplemented {};

//---------------------------------------------------------------------------//
class Shape
{
	int color;
public:
	virtual ~Shape() {}
	// ��� Ŭ���� �̹Ƿ� ���� �Ҹ���!

	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }

protected:
	/*	virtual void DrawImp()
	{
		std::cout << "Draw Shape" << std::endl;
	}*/
	// �����Լ�
	// �Ļ� Ŭ������ ������ ���� ������ default ���� ����

	virtual void DrawImp() = 0;
	// ���� �����Լ�
	//�Ļ� Ŭ�������� �ݵ�� ������.

public:
	virtual void Draw() final
	{
		std::cout << "Mutex lock" << std::endl;
		DrawImp();
		std::cout << "Mutex unlock" << std::endl;
	}

//	virtual Shape* Clone() const = 0;
	// ���� ���� �Լ��� ����� �� ���� ����.

	virtual Shape* Clone() const
	{
		throw NotImplemented();
	}
	// �ٵ� �̷��� �� ���� ����.
	// 1. �Ļ� Ŭ������ Clone() ������ �ʰ�, ������� ������ ok
	// 2. �Ļ� Ŭ������ Clone() ������ �ʰ�, ����ϸ� ����
	// 3. �Ļ� Ŭ������ Clone() �����, ��� ����!

	virtual int GetArea() const { return -1; }
	// ���� �����Լ��� �ص� �ǰ�,
	// �������� ������ ��Ÿ���� ��ȯ ���� ������.
};

//---------------------------------------------------------------------------//
class Rect : public Shape
{
public:
	virtual void DrawImp() override { std::cout << "Draw Rect" << std::endl; }

	// �����Լ� ������ �� ��, ��ȯ Ÿ�� ���� ����!
	// => ��, ��� ������ Ÿ������ �����ؾ� ��.
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
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->Clone());
		}
	}
}