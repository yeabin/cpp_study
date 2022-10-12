#include <iostream>
#include <string>
#include <vector>
#include <conio.h>


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

// MenuItem ��ü�� ������ �����ϴ� Ŭ����
class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add_menu(MenuItem* p) { v.push_back(p); }

	// �˾��޴� ���ý� �ؾ�����(main �Լ��ּ�)�� ��� �������� ������ ������.
	void command()
	{
		std::size_t sz = v.size(); // ���� �޴� ����

		for (std::size_t i = 0; i < sz; i++)
		{
			std::cout << i + 1 << "." << v[i]->get_title() << std::endl;
		}
		std::cout << sz + 1 << ". ����" << std::endl;

		std::cout << "�޴��� �����ϼ��� >> ";
		int cmd;
		std::cin >> cmd;
		v[cmd - 1]->command(); // ���õ� �޴� �׸� ����
	}
};


int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);

	PopupMenu pm("������ �޴�");

	pm.add_menu(&m1);
	pm.add_menu(&m2);

	pm.command();	// �˾��޴� ���ý� "���� �޴�"�� ��Ÿ���� �մϴ�.
					// 1. ���
					// 2. ���
					// 3. ����
					// �޴��� �����ϼ��� >> 
}

