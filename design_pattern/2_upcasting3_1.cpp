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

// ��� ������ ���� Ư¡�� ����ϰڴٴ� �ǵ�
// �˻� �ϴ� �ڵ尡 ���� ���� �� ���� ����.
void NewYear(Animal* p)
{
	++(p->age);
}

// Dog�� ���ؼ��� �ٸ� ������ �ʿ��ϸ�
// Dog* ���� ���� ���� ����
void NewYear(Dog* p)
{
	NewYear(static_cast<Animal*>(p));
	// ���� ���� ���� ��
	p->color = 10;
	// �߰� ���� ����
}
int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}












