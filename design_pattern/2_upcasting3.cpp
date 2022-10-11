#include <iostream>

// upcasting3.cpp
class Animal 
{
public: 
	int age;
	virtual ~Animal() {} //대부분의 기반 클래스는 소멸자를 가상으로.
};
class Cat : public Animal 
{
};
class Dog : public Animal
{
public:
	int color;
};

//void NewYear(Dog* p)
void NewYear(Animal* p)
{
	++(p->age); // 새해가 되면 나이가 증가.
	
	// 새로운 요구사양이 생긴다면?
	// p가 가리키는 것이 Dog라면 color도 변경.
	// p->color = 10;는 error.

	// static_cast: p가 가리키는 곳이 Dog가 아니더라도 캐스팅에 성공합니다
	// 이 경우, p->color = 10 하면 잘못된 실행입니다.
	// => static_cast는 p가 가리키는 것이 Dog라는 확신이 있을 때만 사용하세요.
	//
	// dynamic_cast : p가 가리키는 곳이 Dog가 아니면 0 반환
	// 실행시간에 가상함수 테이블을 사용하여 조사하게 됨.
	// => 가상함수가 있는 타입만 사용 가능.
//	Dog* pDog = static_cast<Dog*>(p);


	Dog* pDog = dynamic_cast<Dog*>(p);
	std::cout << pDog << std::endl;

	if (pDog != nullptr)
	{
		pDog->color = 10;
	}
}
int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}












