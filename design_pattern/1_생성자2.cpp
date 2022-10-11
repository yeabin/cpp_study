// 1_생성자2-1.cpp
#include <string>
#include <iostream>

class People
{
	std::string name;
	int age;
public:
	// name, age가 없는 사람이 있어서는 안됨
	People(const std::string& n, int a) : name(n), age(a) {}
};

// 파생 클래스
class Student : public People
{
	int id;
public:
//	Student(int n) : id(n) {}
	// compiler가 아래처럼 코드 추가
	// Student(int n) : people(), id() {}
	// => People의 디폴트 생성자가 없음

	// 해결책. 핵심.
	// 기반 클래스에 디폴트 생성자가 없으면
	// 파생 클래스에서 기반 클래스 생성자를 명시적으로 호출해야 함
	Student(const std::string& name, int age, int id) // member data와 같은 변수명 사용 가능
		: People(name, age), id(id) {}
};
int main()
{
	// name, age가 초기화 되지 않은 객체
	// 만들어도 될까?
	// => 생성자가 있어야 함
//	People p1;
	People p2("lee", 20);

	Student s1("kim", 20, 14);
}


