
// ����ȭ ��å�� ���� �����ϰ� ����!

// ���1. ���ϴ� ���� �����Լ���
// template method

template<typename T> class List
{
public:
	virtual void lock() {}
	virtual void unlock() {}
	// ���ϴ� ���� �����Լ���

	void push_front(const T& a)
	{
		lock();
		//...
		unlock();
	}
};

// List �Ļ� Ŭ���� ����
// lock/unlcok override �ض�.
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




