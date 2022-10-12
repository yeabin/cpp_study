#include <iostream>
#include <vector>
#include <string>

// strategy, template method
// => 변하는 것을 변경할 수 있게 하는 패턴

// composite 패턴
// => 복합 객체를 만들 때 사용하는 디자인 패턴
// => 재귀적 포함을 사용한 복합객체 만들기
// (A는 B뿐만 아니라 A도 포함 = 재귀적 포함)

// 폴더는 폴더 or 파일을 포함.
// => 공통의 기반 클래스 필요

class Component
{
	std::string title;
public:
	Component(const std::string& title) : title(title) {};
	virtual ~Component() {};

	// 공통의 특징.
	// 핵심.
	// getSize 함수
	virtual int getSize() const = 0;
};

class File  : public Component
{
	int size;
public:
	File(const std::string& title, int n) : Component(title), size(n) {};
	virtual ~File() {};

	// getSize 함수
	virtual int getSize() const { return size; }
};

class Folder : public Component
{
	std::vector<Component*> v;

public:
	Folder(const std::string& title) : Component(title) {};

	// addItem 함수
	void addItem(Component* f) { v.push_back(f); }

	// 핵심.
	// 재귀적.
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

	// 파일은 자신만의 크기는 있습니다.
	// 폴더는 자신만의 크기는 없지만 크기를 구할수 있습니다.
	std::cout << f2->getSize() << std::endl; // 20
	std::cout << fo1->getSize() << std::endl; // 10
	std::cout << root->getSize() << std::endl; // 30
}

