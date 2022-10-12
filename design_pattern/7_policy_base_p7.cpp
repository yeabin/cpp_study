#include <iostream>
#include <vector>

// ����� ���� �޸� �Ҵ��
// => ���� ���� �������� ��å Ŭ������ ���Ѿ� �ϴ� ��Ģ(�Լ��̸�)�� �ֽ��ϴ�
// => ��� �Ҵ��� "allocate, deallocate" �� �־�� �մϴ� => ǥ�� ������ ����!

template<typename T> struct debug_alloc
{
	T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T) * sz);

		printf("debug_alloc : allocate %d counts, at %p\n", sz, p);
		return static_cast<T*>(p);
	}
	void deallocate(T* p, std::size_t sz)
	{
		printf("debug_alloc : deallocate %d counts, at %p\n", sz, p);
		free(p);
	}
	// ���������� ��� �Ҵ��� �Ʒ� 3���� ����� �ʿ� �մϴ�.
	using value_type = T;
	debug_alloc() = default;
	template<typename U> debug_alloc(const debug_alloc<U>&) {}
};

int main()
{
	std::vector<int, debug_alloc<int>> v;

	std::cout << "====" << std::endl;

	v.resize(5);
	std::cout << "====" << std::endl;

	v.resize(10);
	std::cout << "====" << std::endl;

	v.push_back(0); // ũ�Ⱑ 11���� �ɱ�� ??
				// ���� Ŀ����� ? (capacity ����)

	std::cout << v.size() << std::endl; // size �� 11������
	std::cout << v.capacity() << std::endl; // �޸� ��뷮�� �� Ŀ���ϴ�.
											// vc: 1.5 ��
											// g++ : 2��
}

/*
// ����1

// �ٽ� : ���뼺�� �������� �и�
//       => ������ ���� �ڵ忡�� ���ϴ� �ڵ�� �и��Ǿ�� �Ѵ�.

1. ���ϴ� ���� �����Լ���
=> template method
=> ��� ����� ����
=> ����ð� ��ü �ȵǰ�, ��å�� �ٸ� Ŭ�������� ������
=> ���� ������ ����  Draw/DrawImp

2. ���ϴ� ���� Ŭ������ �и� ( ��å(����) Ŭ���� )
=> ��å Ŭ������ ��� ��ü �Ұ��ΰ� ?
A. �������̽��� �����ؼ� ��ü
   => strategy ����
   => ����ð� ��ü ����
   => �����Լ� ����̹Ƿ� ������.
   => Edit/IValidator ����

B. ���ø� ���ڷ� ��ü
	=> ���� ���� ������(policy base design)
	=> ����ð� ��ü �ȵ�
	=> �ζ��� ġȯ ����. ������.
	=> List<int, MutexLocker> ����, vector<int, debug_alloc<int>> ����

// ������ ���� : �� �����ϰ� ����Ҽ� �ִ� ��ü���� ������ ���
//				=> strategy, template method
//
// IDioms    : �� ����� Ư¡�� ����� ������ ���
// C++ IDioms: policy base design


*/