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

	// �ٽ�
	// ��� Ŭ���� Ÿ���� �����ͷ� �Ļ� Ŭ������ �ּҸ� ���� �� �ִ�.
	// "Upcasting"
	Animal* p3 = &d; 
	Animal& r = d;

	// �ٽ�
	// ��� Ŭ���� Ÿ���� ������(����)�� ��� Ŭ���� ����� ����ų �� �ִ�.
	//
	// => C++�� "stack type check" �����
	// ������ �ð��� p3�� ������ Ÿ���� ���� ���� ���θ� �Ǵ�
	// => python�� dynamic type check" �����.
	// ����� �޸𸮿� color�� ������ error �ƴϰ� ������ ���� �߻�.
	p3->age = 10;
//  p3->color = 10;

	// �ٽ�
	// p3(Animal*)�� Dog ��ü�� ����ų ��
	// Dog�� ���� ����� �����Ϸ��� ĳ���� �ؼ� �����ϸ� ��.
	static_cast<Dog*>(p3)->color = 10;
	// ��, p3�� ����Ű�� ���� Dog���  Ȯ���� �־�� ��
	// �𸣸� "dynamic_cast" ���

	// ���� �������� ĳ���� ���� ��

}











