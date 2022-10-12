
// 아래 처럼 짜고 싶음
template<typename T> class List
{
	// member data
public:
	void push_front(const T& a)
	{
		// mutex.lock()
		// ,,,
		// mutex.unlock()
	}
};


List<int> st; 
// 전역변수는 멀티스레드에 안전하지 않습니다.

int main()
{
	// mutex.lock()
	st.push_front(10);
	// mutex.unlock()
}




