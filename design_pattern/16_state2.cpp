#include <iostream>

// 게임 캐릭터 클래스
// default로 돈, 아이템 가지고 있고, 달리기, 공격 동작 가능함
// => boost 먹으면 빠르게 달리기 동작 하게 하고 싶음.
// => 제어문을 수정하면 기능이 추가될 때마다 if 제어문을 추가해야 함(좋지 않음)
// => 변하는 부분을 가상 함수로하는 것도 좋지 않음.

// => 방법2. 변하는 것을 다른 클래스로
// => 아이템 획득해도 상태(멤버 데이터)는 변하지 않아야 함. 동작(멤버 함수)는 변해야 함.
struct IAction
{
	virtual void run() = 0;
	virtual void attack() = 0;
//	virtual void jump() = 0;
	virtual ~IAction(){}
};

// 캐릭터가 action 포인터 가짐
class Character
{
	int gold;
	int item;
	IAction* pact = nullptr;
public:
	void set_state(IAction* p) { pact = p; }
	void run() { pact->run(); }
	void attack() { pact->attack(); }
};

// 아이템에 따른 action 클래스 설계
class NoItem : public IAction
{
public:
	virtual void run() override { std::cout << "run" << std::endl; }
	virtual void attack() override { std::cout << "attack" << std::endl; }
};

class BoostItem : public IAction
{
public:
	virtual void run() override { std::cout << "fast run" << std::endl; }
	virtual void attack() override { std::cout << "attack" << std::endl; }
};

class StarItem : public IAction
{
public:
	virtual void run() override { std::cout << "fast run" << std::endl; }
	virtual void attack() override { std::cout << "power attack" << std::endl; }
};

int main()
{
	NoItem na;
	BoostItem ba;
	StarItem sa;

	Character* p = new Character;
	p->set_state(&na);
	p->run();
	p->attack();

	p->set_state(&ba);
	p->run();
	p->attack();
}
