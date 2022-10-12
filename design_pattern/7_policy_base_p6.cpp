#include <iostream>
#include <vector>
#include <memory> 
// C++ 표준 메모리 할당기

int main()
{
	// 메모리 할당 방법
	// 1. new / delete 를 직접 사용
	// => 메모리 할당 방식을 변경(malloc/free)로 하고 싶으면
	// => 모든 문장을 수정해야 함
	int* p1 = new int[10];
	delete[] p1;

	int* p2 = new int[10];
	delete[] p2;

	// 2. allocator 사용
	// => 메모리 할당 방식을 변경하려면 "할당기"만 변경하면 됨

	std::allocator<int> ax; 

	//아래는 변경 없음
	int* p3 = ax.allocate(10);
	ax.deallocate(p3, 10);

}