// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
	// Upcasting ����
	// 1. ���� �����ϴ� container ���� �� ����
	std::vector<Dog*>    v_dog;
	std::vector<Animal*>    v_ani; // ��� ���� ���� ������.
}