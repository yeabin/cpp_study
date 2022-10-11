//������1.cpp - 3page
#include <iostream>

// �ٽ� : ������ ȣ�� ����
// 1. �����Ϸ��� "��� Ŭ���� �����ڸ� ȣ��"�ϴ� �ڵ带 Derived �����ڿ� �߰��� ��


// 2. ��� Ŭ����(Base)�� ����Ʈ �����ڰ� ���ٸ�..?
// ==> �ݵ�� �Ļ� Ŭ�������� ��� Ŭ���� �����ڸ� ��������� ȣ���ϴ� �ڵ带 �ۼ��ؾ� �Ѵ�.


class Base
{
public:
//	Base()     { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:					
	// �Ʒ� ���ο��� ���� ��
//	Derived()	
	// �Ʒ� ó�� ����ڰ� ��� Ŭ���� �����ڸ� ��������� ȣ���ؾ� �Ѵ�.
	Derived() : Base(0)
	{ 
		std::cout << "Derived()" << std::endl;
	}
	// compiler�� ������ �ڵ�
	// Derived() : Base()
	
	// �Ʒ� ���ο��� ���� ��
//	Derived(int a)	
	// �Ʒ� ó�� ����ڰ� ��� Ŭ���� �����ڸ� ��������� ȣ���ؾ� �Ѵ�.
	Derived(int a): Base(a)
	{ 
		std::cout << "Derived(int)" << std::endl;
	}
	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 
	}
};
int main()
{
	Derived d1;
	Derived d2(5); 
	// ���� Derived�� �θ��� ����. Base�� ���� �θ��� ���� �ƴ�.
	// �׷��� Base(int)�� ���� ��µǰ� Derived()�� ���߿� ��µǴ� ����?
	// 
	// compiler�� �̸� ����� �ִ� �ڵ���
	// Derived(int a) : Base()
	// �ڵ带 ���� �θ��� ������

	// �Ҹ��ڴ� ����ڰ� ���� �ڵ带 ���� �����ϰ�
	//

}