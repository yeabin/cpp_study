class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;
	Dog* p1 = &d; 
//	int* p2 = &d; 

	// 핵심
	// 기반 클래스 타입의 포인터로 파생 클래스의 주소를 담을 수 있다.
	// "Upcasting"
	Animal* p3 = &d; 
	Animal& r = d;

	// 핵심
	// 기반 클래스 타입의 포인터(참조)는 기반 클래스 멤버만 가리킬 수 있다.
	//
	// => C++은 "stack type check" 언어임
	// 컴파일 시간에 p3의 데이터 타입을 보고 오류 여부를 판단
	// => python은 dynamic type check" 언어임.
	// 실행시 메모리에 color가 있으면 error 아니고 없으면 예외 발생.
	p3->age = 10;
//  p3->color = 10;

	// 핵심
	// p3(Animal*)로 Dog 객체를 가리킬 때
	// Dog의 고유 멤버에 접근하려면 캐스팅 해서 접근하면 됨.
	static_cast<Dog*>(p3)->color = 10;
	// 단, p3가 가리키는 곳이 Dog라는  확신이 있어야 함
	// 모르면 "dynamic_cast" 사용

	// 좋은 디자인은 캐스팅 없는 것

}











