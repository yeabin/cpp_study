#include <iostream>
#include <vector>

// �ٽ�1.
// ��� ������ Ÿ��ȭ

// �ٽ�2.
// ��� ������ ���� ��� Ŭ������ �ִٸ�, �ϳ��� container�� ��� ������ �� �ִ�.

class Shape
{

};

class Rect : public Shape
{
public:
	void Draw() { std::cout << "Draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void Draw() { std::cout << "Draw Circle" << std::endl; }
};


int main()
{
	// Rect�� Circle�� �ϳ��� container�� �����ؾ� ��
	// �׸��� ������ �˾ƾ�, ��ġ�� ��쿡 ���� ������ �����ϱ� ����
	std::vector<Shape*> v;
}

