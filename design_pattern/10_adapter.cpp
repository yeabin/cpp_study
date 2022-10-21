#include <iostream>
#include <string>
#include <vector>


// 문자열 저장하고 있다가 화면에 출력해주는 클래스
// 기존에 이미 있던 클래스.
// => 아래 도형 편집기 Shape 객체에서도 TextView의 기능을 사용하고 싶어짐.
class TextView
{
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void Show() { std::cout << data << std::endl; }
};

class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}
};
class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }
};
// => 그러나 Shape 객체에 담아서 사용하려면
// Shape의 파생 클래스여야 하고, Draw Function도 정의되어있어야 함

// ==> TextView의 인터페이스를 변경해서 사용 가능!
// ==> "Adadpter"
// 클래스 어답터 : 클래스의 인터페이스의 변경
// 객체 어답터 : 객체의 인터페이스 변경

// 1. 상속을 통한 어답터. 클래스의 인터페이스를 수정하는 것임.
class Text_c : public Shape, public TextView
{
public:
	Text_c(const std::string& s) : TextView(s) {}

	virtual void Draw() override
	{
		TextView::Show();
	}
};


// 2. 포함을 통한 어답터. 객체의 인터페이스를 수정하는 것임.
class Text_o : public Shape
{
	TextView* txtView;
public:
	Text_o(TextView* p) : txtView(p) {}

	virtual void Draw() override
	{ 
		txtView->Show();
	}

};

int main()
{
	std::vector<Shape*> v;
	v.push_back(new Text_c("clas_textview"));
	// Text_c 객체를 바로 넣을 수 있음.


	TextView tv("object_textview");
//	v.push_back(&tv);
	// textView 객체를 바로 v에 넣지 못함.

	v.push_back(new Text_o(&tv));
	// tv 객체를 Text_o 객체로 변경해서 v에 넣어줌.

	// ==> Text도 Draw function 사용 가능 !
	v[0]->Draw();
}


