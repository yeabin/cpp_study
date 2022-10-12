#include <iostream>


// 객체와 객체에 기능을 추가하는 클래스(Decorator)는
// 공통의 기반 클래스 필요
struct Component
{
	virtual void Fire() = 0;
	virtual ~Component() {};
};

class SpaceShip : public Component
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

class LeftMissile : public Component
{
	Component* ship;
public:
	LeftMissile(Component* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Left Missile" << std::endl;
	}
};

class RightMissile : public Component
{
	Component* ship;
public:
	RightMissile(Component* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;
	LeftMissile lm(&ss);

//	RightMissile rm(&ss);
	// 이렇게 말고 아래처럼
	// left missile 추가된 객체에 다시 기능을 추가 하고 싶음
	// SpaceShip이든 Lef/Right Missile이든 공통의 객체로 담겨야 함
	// 재귀적인 상황
	// => 공통의 기반 클래스 필요!
	RightMissile rm(&lm);
	rm.Fire();
}