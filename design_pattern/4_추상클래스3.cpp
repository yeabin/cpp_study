#include <iostream>

// "Loosely Coupling"
// �ϳ��� Ŭ������ �ٸ� Ŭ���� ��� ��,
// ��Ģ�� ���� �������̽�(�߻�Ŭ����)�� ����Ͽ� �����ϴ� ��
// => Ȯ�强 �ִ� ������ ������

// �߻� Ŭ���� : ���Ѿ� �ϴ� ��Ģ(���� �����Լ�) + �ٸ� ���
// �������̽� : ���Ѿ��ϴ� ��Ģ(���� �����Լ�)�� �ִ� ���

// C#, java���� "interface"��� Ű���� ����
// C++������ �߻�Ŭ���� �������� interface�� ǥ��



//ī�޶� ���Ѿ� �ϴ� ��Ģ�� ���� ������
//��Ģ: ��� ī�޶�� ICamera�κ��� ��� �޾ƾ� ��.
// => "��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�"��� ǥ��
// => Take() �Լ� �����θ� ������ ��.
struct ICamera
//	class ICamera
{
//public:
	virtual void Take() = 0;
	virtual ~ICamera() {} // ��� Ŭ�����̹Ƿ� �Ҹ��� �ݵ�� �����Լ���!
};
// "interface" ���� ��
// class�� �ƴ� struct�� �����ϴ� ���� ����
// => Dependancy Inversion Principle
// => ��ü ������ �������� ����, �߻� �����϶�!!
// => ICamera*�� ����϶�� �ǹ�

class People
{
public:
	virtual void UseCamera(ICamera* p) { p->Take(); }
};

class Camera : public ICamera
{
public:
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take 4k Picture" << std::endl; }
};


int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	UHDCamera hc;
	p.UseCamera(&hc);

	UHDCamera uhc;
	p.UseCamera(&uhc);
}





