#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// 실전에서 Decorator을 쓰는 대표적인 예제

class FileStream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void Write(const std::string& buff) 
	{
		printf("%s 쓰기\n", buff.c_str());
	}
};

int main()
{
	// C언어와 파일 관리
	// => 항상 사용자가 fclose()를 해야하므로 안전하지 않다.
	FILE* f = fopen("a.txt", "wt");
	fclose(f);

	// C++은 생성자/소멸자를 이용하여 자원 관리를 편하고 안전하게 할 수 있다.
	FileStream fs("a.txt");
	// => fs가 파괴될 때 소멸자 호출하니까 안전
}