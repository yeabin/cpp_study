// 1_�߻�Ŭ����1.cpp - 10page

// �߻� Ŭ���� : ���� �����Լ��� �Ѱ� �ִ� Ŭ����
// Ư¡ : ��ü�� ������ �� ����.
class Shape
{
public:
	virtual void Draw() = 0;
	// ���� �����Լ� "pure virtual function"
	// �����ΰ� ���� "=0"���θ� ǥ��

	// �ǵ��� �ٽ�.
	// ��� �Ļ� Ŭ������ Draw() �� �����϶�� ����!
};

class Rect : public Shape
{
	// �ٽ�
	// Rect�� "Draw()"�� �����θ� �������� ������
	// Rect�� �߻� Ŭ����
};

class Rect2 : public Shape
{
	virtual void Draw() override {}
};

int main()
{
//	Shape  s; 
	// �߻� Ŭ������ ��ü ���� �ȵ�

	Shape* p;

//	Rect  r;
	// ���� �߻� Ŭ������ ��ü ���� �ȵ�

	Rect2 r2;
}
