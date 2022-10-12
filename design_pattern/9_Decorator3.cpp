#include <iostream>


// ��ü�� ��ü�� ����� �߰��ϴ� Ŭ����(Decorator)��
// ������ ��� Ŭ���� �ʿ�
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
	// �̷��� ���� �Ʒ�ó��
	// left missile �߰��� ��ü�� �ٽ� ����� �߰� �ϰ� ����
	// SpaceShip�̵� Lef/Right Missile�̵� ������ ��ü�� ��ܾ� ��
	// ������� ��Ȳ
	// => ������ ��� Ŭ���� �ʿ�!
	RightMissile rm(&lm);
	rm.Fire();
}