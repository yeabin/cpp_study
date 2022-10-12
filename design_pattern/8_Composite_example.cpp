#include <iostream>
#include <vector>
#include <string>

// strategy, template method
// => ���ϴ� ���� ������ �� �ְ� �ϴ� ����

// composite ����
// => ���� ��ü�� ���� �� ����ϴ� ������ ����
// => ����� ������ ����� ���հ�ü �����
// (A�� B�Ӹ� �ƴ϶� A�� ���� = ����� ����)

// ������ ���� or ������ ����.
// => ������ ��� Ŭ���� �ʿ�

class Component
{
	std::string title;
public:
	Component(const std::string& title) : title(title) {};
	virtual ~Component() {};

	// ������ Ư¡.
	// �ٽ�.
	// getSize �Լ�
	virtual int getSize() const = 0;
};

class File  : public Component
{
	int size;
public:
	File(const std::string& title, int n) : Component(title), size(n) {};
	virtual ~File() {};

	// getSize �Լ�
	virtual int getSize() const { return size; }
};

class Folder : public Component
{
	std::vector<Component*> v;

public:
	Folder(const std::string& title) : Component(title) {};

	// addItem �Լ�
	void addItem(Component* f) { v.push_back(f); }

	// �ٽ�.
	// �����.
	// getSize
	virtual int getSize() const override
	{
		int size = 0;
		for (auto p : v)
		{
			size = size + p->getSize();
		}
		return size;
	}
};



int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1  = new Folder("A");
	Folder* fo2  = new Folder("B");
	
	root->addItem(fo1);
	root->addItem(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->addItem(f1);
	root->addItem(f2);

	// ������ �ڽŸ��� ũ��� �ֽ��ϴ�.
	// ������ �ڽŸ��� ũ��� ������ ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	std::cout << f2->getSize() << std::endl; // 20
	std::cout << fo1->getSize() << std::endl; // 10
	std::cout << root->getSize() << std::endl; // 30
}

