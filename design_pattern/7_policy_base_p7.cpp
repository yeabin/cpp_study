#include <iostream>
#include <vector>

// 사용자 정의 메모리 할당기
// => 단위 전략 디자인의 정책 클래스는 지켜야 하는 규칙(함수이름)이 있습니다
// => 모든 할당기는 "allocate, deallocate" 가 있어야 합니다 => 표준 문서에 정의!

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
	// 관례적으로 모든 할당기는 아래 3개의 멤버도 필요 합니다.
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

	v.push_back(0); // 크기가 11개가 될까요 ??
				// 좀더 커질까요 ? (capacity 개념)

	std::cout << v.size() << std::endl; // size 는 11이지만
	std::cout << v.capacity() << std::endl; // 메모리 사용량은 더 커집니다.
											// vc: 1.5 배
											// g++ : 2배
}

/*
// 정리1

// 핵심 : 공통성과 가변성의 분리
//       => 변하지 않은 코드에서 변하는 코드는 분리되어야 한다.

1. 변하는 것을 가상함수로
=> template method
=> 상속 기반의 패턴
=> 실행시간 교체 안되고, 정책을 다른 클래스에서 사용못함
=> 도형 편집기 예제  Draw/DrawImp

2. 변하는 것을 클래스로 분리 ( 정책(전략) 클래스 )
=> 정책 클래스를 어떻게 교체 할것인가 ?
A. 인터페이스를 설계해서 교체
   => strategy 패턴
   => 실행시간 교체 가능
   => 가상함수 기반이므로 느리다.
   => Edit/IValidator 예제

B. 템플릿 인자로 교체
	=> 단위 전략 디자인(policy base design)
	=> 실행시간 교체 안됨
	=> 인라인 치환 가능. 빠르다.
	=> List<int, MutexLocker> 예제, vector<int, debug_alloc<int>> 예제

// 디자인 패턴 : 언어에 무관하게 사용할수 있는 객체지향 디자인 기술
//				=> strategy, template method
//
// IDioms    : 각 언어의 특징을 고려한 디자인 기술
// C++ IDioms: policy base design


*/