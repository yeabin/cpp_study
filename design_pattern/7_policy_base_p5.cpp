#include <memory>

// STL �� ����
// => ����ȭ�� ����ؼ� ������ ������ �ʾ�����
// => Policy Based Design�� ���

// STL�� vector�� �Ʒ� ó�� ������ �Ǿ� ����.
template<typename T, typename Alloc = std::allocator<T>>
class vector
{
	T* buff;
	Alloc ax; // �޸� �Ҵ��(allocator)
			  // vector�� ��� ��� �Լ����� �޸� �Ҵ�/������ ax�� ���
public:
	void resize(int n)
	{
		// ���� ũ�Ⱑ �����ؼ� �ٽ� �Ҵ��Ϸ��� �մϴ�.
		// ��� �Ҵ��ұ�� ?
		// C++������ �޸𸮸� �Ҵ��ϴ� ����� ���� ���� �ֽ��ϴ�.
		// new / malloc / system call / windows api/ Ǯ�� 

//		buff = new T[n] 
		// �޸� �Ҵ� ����� ��ü�� �� ����

		buff = ax.allocate(n); // TŸ�� n�� �Ҵ�
		
		ax.deallocate(buff, n); // n�� ����

	}
};

vector<int> v;

