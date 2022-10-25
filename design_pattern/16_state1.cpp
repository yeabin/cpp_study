#include <iostream>

// 게임 캐릭터 클래스
// default로 돈, 아이템 가지고 있고, 달리기, 공격 동작 가능함
// => boost 먹으면 빠르게 달리기 동작 하게 하고 싶음.
// => 제어문을 수정하면 기능이 추가될 때마다 if 제어문을 추가해야 함(좋지 않음)

// => 1. 변하는 부분을 가상 함수로!
class Character
{
	int gold;
	int item;
public:
	void run() { do_run(); }
	void attack() { do_attack(); }

	virtual void do_run() { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};

class StarCharacter : public Character
{
public:
	virtual void do_run() { std::cout << "fast run" << std::endl; }
	virtual void do_attack() { std::cout << "power attack" << std::endl; }
};


int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	// 근데 기존 캐릭터의 동작이 변경되는 게 아니라
	// 그냥 star 아이템 먹은 캐릭터인 새로운 클래스의 객체가 된 것임
	// => 아이템이 다양해질수록 구현이 힘들 듯...
	p = new StarCharacter;
	p->run();
	p->attack();
}
