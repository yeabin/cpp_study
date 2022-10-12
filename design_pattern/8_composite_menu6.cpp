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

	// 가상 함수
	// => 세부 구현은 파생 클래스에서!
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
		std::cout << get_title() << " 메뉴 선택됨" << std::endl;
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
			std::cout << sz + 1 << ". 종료" << std::endl;

			std::cout << "메뉴를 선택하세요 >> ";
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
	PopupMenu* p1 = new PopupMenu("색상 변경");
	PopupMenu* p2 = new PopupMenu("해상도 변경");

	root->add_menu(p1);
	p1->add_menu(p2);

	root->add_menu(new MenuItem("기타", 11));

	// sub menu 함수
	// root->submenu(1) 이 해상도 메뉴 객체로 반환되서 ->add_menu() 할수 있으면 좋겠다.
	// => BaseMenu에 submenu 함수 추가하면 반환까지 됨.
	// => BaseMenu에 add_menu 함수를 넣으면 됨.

	root->submenu(1)->add_menu(new MenuItem("RED", 11));
	// 구현 완.

	// 도전 과제
//	root[1].add_menu()

	root->submenu(2)->add_menu(new MenuItem("기타", 31)); // 예외
	// root->submenu(2)는 Popup이 아닌 MenuItem

}
