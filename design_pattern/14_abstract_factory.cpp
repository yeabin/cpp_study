#include <iostream>

// 컨트롤 종류마다 기반 클래스 필요
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};

// 스타일마다 컨트롤을 파생클래스로 생성
struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};

// "Abstract Factory" 
// => 객체 군을 만들기 위한 인터페이스를 만들지만
// 어떤 객체들을 만들지는 파생 클래스가 결정한다.
// => 공장도 인터페이스를 먼저 설계하자는 의미
struct IFactory
{
	virtual IButton* CreateButton() = 0;
	virtual IEdit* CreateEdit() = 0;
	virtual ~IFactory() = 0;
};

// 스타일마다 팩토리 파생 클래스
class WinFactory : public IFactory
{
public:
	IButton* CreateButton() { return new WinButton; }
	IEdit* CreateEdit() { return new WinEdit; }
	virtual ~WinFactory(){}
};

class OSXFactory : public IFactory
{
public:
	IButton* CreateButton() { return new OSXButton; }
	IEdit* CreateEdit() { return new OSXEdit; }
	virtual ~OSXFactory() {}
};



int main(int argc, char** argv)
{
	// 스타일 별 공장
	IFactory* factory;

	if (strcmp(argv[1], "-style:OSX") == 0)
		factory = new OSXFactory;
	else
		factory = new WinFactory;

	// 컨트롤이 필요하면 아래와 같이 사용.
	IButton * btn = factory->CreateButton();
	btn->Draw();
}


