#include <iostream>
#include <vector>



// p->Draw() ���� ���� ���� �ڵ�.
// Shape�� Draw()�� ���� ������.
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
			//for (auto p : v)
				//p->Draw(); 
		}
	}
}