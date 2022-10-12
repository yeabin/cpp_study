#include <memory>

// STL 의 원리
// => 동기화를 고려해서 디자인 되지는 않았지만
// => Policy Based Design을 사용

// STL의 vector는 아래 처럼 디자인 되어 있음.
template<typename T, typename Alloc = std::allocator<T>>
class vector
{
	T* buff;
	Alloc ax; // 메모리 할당기(allocator)
			  // vector의 모든 멤버 함수에서 메모리 할당/해지는 ax만 사용
public:
	void resize(int n)
	{
		// 버퍼 크기가 부족해서 다시 할당하려고 합니다.
		// 어떻게 할당할까요 ?
		// C++에서는 메모리를 할당하는 방법이 아주 많이 있습니다.
		// new / malloc / system call / windows api/ 풀링 

//		buff = new T[n] 
		// 메모리 할당 방식을 교체할 수 없음

		buff = ax.allocate(n); // T타입 n개 할당
		
		ax.deallocate(buff, n); // n개 해지

	}
};

vector<int> v;

