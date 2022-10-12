#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


class NotImplememted {};


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	// ���� �Լ�
	// => ���� ������ �Ļ� Ŭ��������!
	// command
	virtual void command() = 0;

	// add menu
	virtual void add_menu(BaseMenu* p)
	{
		throw NotImplememted();
	}

	// submenu
	virtual BaseMenu* submenu(int idx)
	{
		throw NotImplememted();
	}
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

	BaseMenu* submenu(int idx) { return v[idx - 1]; }
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* p1 = new PopupMenu("���� ����");
	PopupMenu* p2 = new PopupMenu("�ػ� ����");

	root->add_menu(p1);
	p1->add_menu(p2);

	root->add_menu(new MenuItem("��Ÿ", 11));

	// sub menu �Լ�
	// root->submenu(1) �� �ػ� �޴� ��ü�� ��ȯ�Ǽ� ->add_menu() �Ҽ� ������ ���ڴ�.
	// => BaseMenu�� submenu �Լ� �߰��ϸ� ��ȯ���� ��.
	// => BaseMenu�� add_menu �Լ��� ������ ��.

	root->submenu(1)->add_menu(new MenuItem("RED", 11));
	// ���� ��.

	// ���� ����
//	root[1].add_menu()

	root->submenu(2)->add_menu(new MenuItem("��Ÿ", 31)); // ����
	// root->submenu(2)�� Popup�� �ƴ� MenuItem

}
