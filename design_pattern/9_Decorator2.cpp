#include <iostream>

class SpaceShip
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// ��� : Ŭ������ ����� �߰��ϴ� ��
// ���� : ��ü�� ����� �߰��� �� �ִ�.
class LeftMissile : public SpaceShip
{
	SpaceShip* ship;
	// �ݵ�� ���� �ƴ� ������ �Ǵ� ������ �� ��� ����!
	// => �̹� ������� ���ּ� ��ü�� ����Ų�ٴ� ��

public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		// �� ��ü�� ���� ��� ����ϰ� + ��� �߰�
		std::cout << "Fire Left Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ship;
	ship.Fire();

	LeftMissile lm(&ship);
	lm.Fire();

	// ship�� lm�� ���� ����� �߰�
	// => lm�� �̸� �����ϴ� ��ü ship�� ���ο� ����� �߰��� ��
}