// 2_�����Լ�������
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// �ٽ�1.
	// �����Լ� ������ �� "virtual" �ʼ� �ƴ�
	// but, ���̴� �� ������ ����
	virtual void foo(){}

	// �ٽ�2.
	// �����Լ� �����ǽ� �Ǽ�(��Ÿ)�� �־ ������ �ƴ�
	// => "override" Ű���� ����.
	// => ���ο� �Լ��� ����� ���� �ƴ� ��� Ŭ���� �Լ��� ������ �Ѵٰ� �˷���
	virtual void fooo(){}
	virtual void goo(double){}
};

int main()
{
}





