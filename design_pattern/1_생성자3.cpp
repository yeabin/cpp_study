class Animal
{
//public: < ok
//private: < Dog, Animal 둘 다  error
// 핵심.
	// Animal 객체 생성은 x
	// protected는 파생 클래스에서는 부를 수 있음.


	// 생성자를 protected에 놓는 이유
	// 자신은 객체를 생성할 수 없지만(추상적 존재)
	// 파생 클래스는 객체를 생성할 수 있게 하겠다(구체적 존재)

	// 객체지향 디자인에서 추상(abstract)의 반대 의미를 구체(concrete)라고 함
protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {} // Dog() : Animal() {}
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
//	Animal a;
	Dog    d; // ok
}



