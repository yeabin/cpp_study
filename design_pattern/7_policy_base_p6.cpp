#include <iostream>
#include <vector>
#include <memory> 
// C++ ǥ�� �޸� �Ҵ��

int main()
{
	// �޸� �Ҵ� ���
	// 1. new / delete �� ���� ���
	// => �޸� �Ҵ� ����� ����(malloc/free)�� �ϰ� ������
	// => ��� ������ �����ؾ� ��
	int* p1 = new int[10];
	delete[] p1;

	int* p2 = new int[10];
	delete[] p2;

	// 2. allocator ���
	// => �޸� �Ҵ� ����� �����Ϸ��� "�Ҵ��"�� �����ϸ� ��

	std::allocator<int> ax; 

	//�Ʒ��� ���� ����
	int* p3 = ax.allocate(10);
	ax.deallocate(p3, 10);

}