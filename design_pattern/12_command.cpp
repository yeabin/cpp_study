#include <iostream>
#include <vector>
#include <stack>

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};


// "Command" 패턴
// => 명령을 캡슐화해서 "취소/복구" 기능을 가능하게 한다
// 명령 클래스의 인터페이스
struct ICommand
{
	virtual void execute() = 0;
	virtual bool canUndo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

// Rect, Circle, Draw 메뉴 선택 시 해야할 일을 담은 클래스 설계
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute() override { v.push_back(new Rect); };
	virtual bool canUndo() override { return true; }
	virtual void undo()    override
	{
		auto p = v.back();
		v.pop_back();
		delete p;
	}
};
class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute() override { v.push_back(new Circle); };
	virtual bool canUndo() override { return true; }
	virtual void undo()    override
	{
		auto p = v.back();
		v.pop_back();
		delete p;
	}
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute() override
	{
		for (auto p : v)
			p->draw();
	};

	virtual bool canUndo() override { return true; }
	virtual void undo()    override
	{
		system("cls");
	}
};

int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> cmd_stack;

	ICommand* pcmd = nullptr;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			pcmd = new AddRectCommand(v);
			pcmd->execute();

			cmd_stack.push(pcmd); // undo 를 위해 스택에 보관

		}
		else if (cmd == 2)
		{
			pcmd = new AddCircleCommand(v);
			pcmd->execute();

			cmd_stack.push(pcmd);
		}
		else if (cmd == 9)
		{
			pcmd = new DrawCommand(v);
			pcmd->execute();

			cmd_stack.push(pcmd);
		}
		else if (cmd == 0)
		{
			if (!cmd_stack.empty())
			{

				pcmd = cmd_stack.top();
				cmd_stack.pop();

				if (pcmd->canUndo())
					pcmd->undo();

				delete pcmd;
			}
		}
	}
}
