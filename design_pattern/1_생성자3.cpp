class Animal
{
//public: < ok
//private: < Dog, Animal �� ��  error
// �ٽ�.
	// Animal ��ü ������ x
	// protected�� �Ļ� Ŭ���������� �θ� �� ����.


	// �����ڸ� protected�� ���� ����
	// �ڽ��� ��ü�� ������ �� ������(�߻��� ����)
	// �Ļ� Ŭ������ ��ü�� ������ �� �ְ� �ϰڴ�(��ü�� ����)

	// ��ü���� �����ο��� �߻�(abstract)�� �ݴ� �ǹ̸� ��ü(concrete)��� ��
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
	// ������ ������ ��� ��� ������
//	Animal a;
	Dog    d; // ok
}



