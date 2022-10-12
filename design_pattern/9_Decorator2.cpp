#include <iostream>

class SpaceShip
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// 상속 : 클래스에 기능을 추가하는 것
// 포함 : 객체에 기능을 추가할 수 있다.
class LeftMissile : public SpaceShip
{
	SpaceShip* ship;
	// 반드시 값이 아닌 포인터 또는 참조로 된 멤버 변수!
	// => 이미 만들어진 우주선 객체를 가리킨다는 뜻

public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		// 그 객체의 기존 기능 사용하고 + 기능 추가
		std::cout << "Fire Left Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ship;
	ship.Fire();

	LeftMissile lm(&ship);
	lm.Fire();

	// ship에 lm이 가진 기능을 추가
	// => lm은 미리 존재하는 객체 ship에 새로운 기능을 추가한 것
}