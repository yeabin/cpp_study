#include <iostream>

// upcasting3.cpp
class Animal 
{
public: 
	int age;
	virtual ~Animal() {} //��κ��� ��� Ŭ������ �Ҹ��ڸ� ��������.
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
	++(p->age); // ���ذ� �Ǹ� ���̰� ����.
	
	// ���ο� �䱸����� ����ٸ�?
	// p�� ����Ű�� ���� Dog��� color�� ����.
	// p->color = 10;�� error.

	// static_cast: p�� ����Ű�� ���� Dog�� �ƴϴ��� ĳ���ÿ� �����մϴ�
	// �� ���, p->color = 10 �ϸ� �߸��� �����Դϴ�.
	// => static_cast�� p�� ����Ű�� ���� Dog��� Ȯ���� ���� ���� ����ϼ���.
	//
	// dynamic_cast : p�� ����Ű�� ���� Dog�� �ƴϸ� 0 ��ȯ
	// ����ð��� �����Լ� ���̺��� ����Ͽ� �����ϰ� ��.
	// => �����Լ��� �ִ� Ÿ�Ը� ��� ����.
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












