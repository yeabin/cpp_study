#include <iostream>

// 우주 비행선 예제
// 이해 하기는 쉽지만 별로 안좋은 예제

// 구현 기능
// => 미사일을 직선 한줄로 쏘다가
// => 아이템을 먹으면 대각선 줄도 추가됨.

class SpaceShip
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};

// => 상속을 사용한 기능의 추가
class LeftMissile : public SpaceShip
{
public:
	void Fire()
	{
		SpaceShip::Fire(); // 기존 기능은 기본
		std::cout << "Fire Left Missile" << std::endl; // 새로운 기능 추가
	}
};

int main()
{
	SpaceShip ship;
	ship.Fire();

	LeftMissile lmship;
	lmship.Fire();
	// ship 우주선에 기능이 추가된 것이 아님.
	// 새로운 우주선이 생긴 것임.

	//핵심: 상속은 객체가 아닌 클래스에 기능을 추가하는 것임.
}