#include <iostream>

class Animal
{
public:
	void cry1() { std::cout << "Animal Cry1" << std::endl; }
	
	// "Virtual Function"
	// �Լ� ȣ���� �� ������ �ð��� �ƴ� ���� �ð��� �޸� ���� �� ������ �޶�� ��
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};
class Dog : public Animal
{
public:
	// "Function Override"
	// ��� Ŭ���� ��� �Լ��� �Ļ� Ŭ������ �ٽ� ����� ��
	void cry1() { std::cout << "Dog Cry1" << std::endl; }
	
	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; }
};
int main()
{
	Dog d;
	Animal* p = &d; 

	p->cry1();
	// �翬�� Dog Cry�� �ҷ��� �� Ÿ�̹�
	// but, in C++, compiler�� ��� �Լ� ȣ���� ���� ! => Animal Cry
	// ����: "������ Ÿ��"���� ȣ��
	// => ����: ������ �� �� ��� ���� ������. ���� �� ������尡 ����.

	p->cry2();
	// ���� �Լ��� virtual �̶��
	// ������ �� �� p�� ����Ű�� �޸𸮸� �����ϴ� ���� �ڵ� ����
	// => p�� ����Ű�� ��ü�� �����Ͽ� ȣ��
	// => ���� : �������� �´� ȣ��
	// => ���� : ����ð��� �����ؾ� �ϹǷ� ������.
	// => Dog Cry

}


