#include <iostream>

// ���� ���༱ ����
// ���� �ϱ�� ������ ���� ������ ����

// ���� ���
// => �̻����� ���� ���ٷ� ��ٰ�
// => �������� ������ �밢�� �ٵ� �߰���.

class SpaceShip
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};

// => ����� ����� ����� �߰�
class LeftMissile : public SpaceShip
{
public:
	void Fire()
	{
		SpaceShip::Fire(); // ���� ����� �⺻
		std::cout << "Fire Left Missile" << std::endl; // ���ο� ��� �߰�
	}
};

int main()
{
	SpaceShip ship;
	ship.Fire();

	LeftMissile lmship;
	lmship.Fire();
	// ship ���ּ��� ����� �߰��� ���� �ƴ�.
	// ���ο� ���ּ��� ���� ����.

	//�ٽ�: ����� ��ü�� �ƴ� Ŭ������ ����� �߰��ϴ� ����.
}