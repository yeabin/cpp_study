
// 동기화 정책을 변경 가능하게 설계!

// 방법1. 변하는 것을 가상함수로
// template method

template<typename T> class List
{
public:
	virtual void lock() {}
	virtual void unlock() {}
	// 변하는 것을 가상함수로

	void push_front(const T& a)
	{
		lock();
		//...
		unlock();
	}
};

// List 파생 클래스 만들어서
// lock/unlcok override 해라.
template<typename T> class ThreadSafeList : public List<T>
{
	std::mutex m;
public:
	virtual void lock() { m.lock(); }
	virtual void unlock() { m.unlock(); }
};



List<int> st;

int main()
{
	st.push_front(10);
}




