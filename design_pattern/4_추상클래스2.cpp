//1_�߻�Ŭ����2.cpp
#include <iostream>

// "OCP"
// ��� Ȯ�忡 Open
// �ڵ� �������� Closed
// �ϵ��� ������ �϶�� ��Ģ Principle
// => "SOLID" : SRP, OCP, LSP, ISP, DIP

// "Tightly Coupled"
// Ŭ�������� �ٸ� Ŭ���� �̿� ��, Ŭ���� �̸��� ���� ����ϴ� ��
// ��ü �Ұ�����, ������ ������.
// OCP �������� ����

class Camera
{
public:	
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void UseCamera(Camera* p) { p->Take(); }
	void UseCamera(HDCamera* p) { p->Take(); }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);
}





