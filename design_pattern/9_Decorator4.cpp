#include <iostream>

// 핵심
// 상속으로는 객체가 아닌 클래스에 기능이 추가됨.
// 의도는 객체에 기능을 추가하는 것!
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

// LeftMissile, RightMissile은 우주선에 기능을 추가하기 위한 클래스
// => Decorator(포장지)
// => Decorator 공통의 특징이 있으므로
// => 공통의 기반 클래스 제공하면 편리함
class Decorator : public Component
{
protected:
	Component* ship;
public:
	Decorator(Component* ship) : ship(ship) {}
};

class LeftMissile : public Decorator
{
public:
	LeftMissile(Component* s) : Decorator(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Left Missile" << std::endl;
	}
};

class RightMissile : public Decorator
{
public:
	RightMissile(Component* s) : Decorator(s) {}

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
	RightMissile rm(&lm);
	rm.Fire();
}