#include <iostream>

// C++���� �ݵ�� �˾ƾ� �ϴ� ��Ģ
// => ��� Ŭ������ �Ҹ��ڴ� "public virtual"�̰ų�
// => "protected non-virtual" �̾�� �Ѵ�!

class Base
{
public:
	virtual ~Base() {} // virtual��!
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; } // Base�� virtual�̸� �굵 virtual
};
int main()
{
	//Derived d;

	//Derived* p1 = new Derived;	// ��ü ����
	//delete p1;	// ��ü �ı�

	Base* p2 = new Derived;
	delete p2;
	// �ٽ�.
	// �Ҹ��ڵ� �Լ� ȣ��.
	// 1. �����Ϸ��� p2�� "Base*�̹Ƿ� Base���� �Ҹ��ڰ� �������� ����
	// => Base�� �Ҹ��ڰ� �����Լ��� �ƴϸ� ������ ����Ʈ Ÿ������ ȣ��
	// => ~Base() �Լ��� ȣ��

	// �ذ�å.
	// �Ҹ��ڰ� �����Լ���� p�� ����Ű�� �޸��� ��ü�� �����ϴ� �ڵ带 �����ϰ�
	// ���� �� �����ؼ� �Ҹ��� ȣ���� ����
}	
