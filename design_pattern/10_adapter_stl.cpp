#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL에서 Adapter 예시
// Linked List 가 있고, Stack을 새로 만들고 싶음


// 1. 인터페이스 상속을 사용한 어답터.
// => linked list의 모든 기능을 stack 클래스가 외부 노출하겠다는 것.
// => 별로 좋지 않은 예제임
template<typename T> class stack_bad : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()			  { return std::list<T>::back(); }
};

// 2. 포함을 사용한 어답터
// => 기존 linked list의 구현을 그대로 사용하지만, stack이 list의 기능을 노출하지 않음.
template<typename T> class stack
{
	//	std::list<T>* c;
	// 이렇게 하면 객체 어답터가 되버림. 클래스 어답터를 만들어야 함.
	std::list<T> c;

public:
	void push(const T& a) { c.push_back(a); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

// 3. Private 상속을 사용한 어답터
// ==> 포함을 사용한 것과의 차이점은 list의 가상함수가 있다면 override 하여 구현할 수 있음.
template<typename T> class stack_private : private std::list<T>
{
public:
	void push(const &a) { std::list<T>::push_back(a); }
	void pop() { std::list<T>::pop_back(); }
	T& top() { return std::list<T>::back(); }
};

int main()
{
	stack_bad<int> s1;
	s1.push(10);
	s1.push_front(20); // 이게 가능하면 안좋은 구현임.

	stack<int> s;
	s.push(10);
//	s.push_front(20); // error

	stack_private<int> s2;
	s2.push(10);
//	s2.push_front(30); // error
}
