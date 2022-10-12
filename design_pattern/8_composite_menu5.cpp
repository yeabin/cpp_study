#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }
	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << " �޴� ���õ�" << std::endl;
		_getch();
	}
};


class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p)
	{
		v.push_back(p);
	}


	void command()
	{
		while (1)
		{
			system("cls");

			std::size_t sz = v.size();

			for (std::size_t i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". ����" << std::endl;

			std::cout << "�޴��� �����ϼ��� >> ";
			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;


			v[cmd - 1]->command();
		}

	}
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* p1 = new PopupMenu("���� ����");
	PopupMenu* p2 = new PopupMenu("�ػ� ����");

	root->add_menu(p1);
//	root->add_menu(p2);
	// �Ʒ� ó�� �ٲٸ�?
	p1->add_menu(p2);


	p1->add_menu(new MenuItem("RED", 11));
	p1->add_menu(new MenuItem("GREEN", 12));
	p1->add_menu(new MenuItem("BLUE", 13));

	p2->add_menu(new MenuItem("HD", 21));
	p2->add_menu(new MenuItem("FHD", 22));
	p2->add_menu(new MenuItem("UHD", 23));

	// ���� �����Ϸ��� ??

}

// �ٽ�
// Composite ����
// => ���հ�ü(PopupMenu)�� ������ü(MenuItem) �Ӹ� �ƴ϶�
//    ���հ�ü �ڱ� �ڽŵ� �����Ѵ�.
// => ���հ�ü�� ������ü�� ������ ��� Ŭ������ �ʿ��ϴ�.
// => ����� ������ ����.

// ���հ�ü�� ������ü�� ������ �����ϴ�.
// => command ������ ��� Ŭ������ �־�� �Ѵ�.

// ���հ�ü�� "tree" ������ �����ȴ�.

// 