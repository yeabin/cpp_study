#include <mutex>

// 단위 전략(Policy Based Design)
// => 템플릿 인자로 다양한 정책을 담은 크래스를 전달 받아서
// => 클래스의 멤버 함수 작성 시 "정책 클래스"에 의존해서 코드를 작성하는 것

// => 클래스의 다양한 정책을 "성능저하 없이" 교체 할수 있다.

// 정책 클래스를 교체하는 2가지 기술

//					strategy				policy base design
// 교체 방법			interface 사용			템플릿 인자 사용
//					st.set_sync(&ml)		List<int, MutexLocker>

// 실행시간 교체여부	실행시간 교체 가능			실행시간 교체 안됨.
//					st.set_sync 다시호출		=> 템플릿 인자는 실행할때 교체안됨

// 성능				가상함수기반. 느리다.		인라인 치환. 빠르다.
// 
// 함수이름			인터페이스로 약속			문서화로 약속.
//											C++20 부터는 concept으로 약속가능										

// 주의 !! STL 의 컨테이너가 이렇게 된것은 아닙니다.(STL 컨테이너는 동기화 안됨)
// => STL 은 다른 용도로 이기술을 사용합니다.

// webkit 의 List가 이렇게 되어 있습니다.

template<typename T, typename ThreadModel = NoLock> class List
// default로 NoLock 사용
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();
		// ...
		tm.unlock();
	}
};
// List의 2번째 템플릿 인자로 사용할 동기화 정책 클래스를 만들어서 제공
// => lock/unlock 함수가 있어야 함

class MutexLocker
{
	std::mutex mtx;
public:
	inline void lock() { mtx.lock(); }
	inline void unlock() { mtx.unlock(); }
};

class NoLock
{
public:
	inline void lock() { }
	inline void unlock() { }
};


List<int, MutexLocker>   st1;
List<int, NoLock>		 st2;


int main()
{
	st1.push_front(10);
}




