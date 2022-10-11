// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// 핵심1.
	// 가상함수 재정의 시 "virtual" 필수 아님
	// but, 붙이는 게 가독성 좋음
	virtual void foo(){}

	// 핵심2.
	// 가상함수 재정의시 실수(오타)가 있어도 에러가 아님
	// => "override" 키워드 도입.
	// => 새로운 함수를 만드는 것이 아닌 기반 클래스 함수를 재정의 한다고 알려줌
	virtual void fooo(){}
	virtual void goo(double){}
};

int main()
{
}





