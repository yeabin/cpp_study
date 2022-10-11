// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
	// Upcasting 장점
	// 1. 동종 보관하는 container 만들 수 있음
	std::vector<Dog*>    v_dog;
	std::vector<Animal*>    v_ani; // 모든 동물 보관 가능함.
}