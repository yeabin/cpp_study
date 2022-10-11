#include <iostream>

class Animal
{
public:
	int age;
	virtual ~Animal() {}
};
class Cat : public Animal
{
};
class Dog : public Animal
{
public:
	int color;
};

// 모든 동물의 공통 특징만 사용하겠다는 의도
// 검사 하는 코드가 여기 들어가는 건 좋지 않음.
void NewYear(Animal* p)
{
	++(p->age);
}

// Dog에 대해서만 다른 동작이 필요하면
// Dog* 전용 버전 따로 설계
void NewYear(Dog* p)
{
	NewYear(static_cast<Animal*>(p));
	// 기존 동작 수행 후
	p->color = 10;
	// 추가 동작 수행
}
int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}












