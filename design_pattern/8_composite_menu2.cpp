#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// ��ü���� ���α׷���(Object Oriented Programming )

// 1. ���α׷��� ��ü�� �����ϰ� 
// 2. ��ü���� ���踦 �����ϰ�, 
// 3. ��ü���� �޼����� �ְ� �޴°��̴�.( ��� �Լ��� ȣ���Ѵٴ� �ǹ�)
// 4. ���α׷��� �⺻ ������ "Ŭ����" �̴�.
// => C++, JAVA, SWIFT, C#

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}

	std::string get_title() const { return title; }

	void command()
	{
		std::cout << get_title() << " �޴� ���õ�" << std::endl;
		_getch();
	}
};


int main()
{
	// ��ü���� ���α׷����� "��� ���� ��ü" �Դϴ�.
	// �޴��׸� �Ѱ��� ���� ��ü�� �����Ǿ�� �մϴ�.
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);
	m1.command(); // �޴� ���ý� ȣ��Ǵ� �Լ�!
}




