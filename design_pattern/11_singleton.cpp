#include <iostream>

// 싱글톤
// 1. 오직 하나의 객체만 존재하는 것.
// 2. 세가지 규칙 존재
// => 생성자는 private에
// => 컴파일러에게 디폴트 복사 생성자, 대입연산자 삭제 요청
// => 오직 한개의 객체를 만들어서 반환하는 static 멤버 함수
// 3. 단점
// => 결국 전역변수와 동일한 특징을 가지게 되므로,위험함.

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sinstance;
public:
	static Cursor& getInstance()
	{
		if (sinstance == nullptr)
		{
			sinstance = new Cursor;
		}
		return *sinstance;
	}
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;
}






