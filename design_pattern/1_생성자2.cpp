// 1_������2-1.cpp
#include <string>
#include <iostream>

class People
{
	std::string name;
	int age;
public:
	// name, age�� ���� ����� �־�� �ȵ�
	People(const std::string& n, int a) : name(n), age(a) {}
};

// �Ļ� Ŭ����
class Student : public People
{
	int id;
public:
//	Student(int n) : id(n) {}
	// compiler�� �Ʒ�ó�� �ڵ� �߰�
	// Student(int n) : people(), id() {}
	// => People�� ����Ʈ �����ڰ� ����

	// �ذ�å. �ٽ�.
	// ��� Ŭ������ ����Ʈ �����ڰ� ������
	// �Ļ� Ŭ�������� ��� Ŭ���� �����ڸ� ��������� ȣ���ؾ� ��
	Student(const std::string& name, int age, int id) // member data�� ���� ������ ��� ����
		: People(name, age), id(id) {}
};
int main()
{
	// name, age�� �ʱ�ȭ ���� ���� ��ü
	// ���� �ɱ�?
	// => �����ڰ� �־�� ��
//	People p1;
	People p2("lee", 20);

	Student s1("kim", 20, 14);
}


