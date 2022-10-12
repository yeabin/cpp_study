#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// ��� ������ Stream ������ �������� �����ϱ� ����
// �������̽� ����
struct Stream
{
	virtual void Write(const std::string& s) = 0;
	virtual ~Stream(){}

	// Read(), IsOpen()���� �Լ���
	// �������̽��� ���
};


class FileStream : public Stream
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
		printf("%s ����\n", buff.c_str());
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("hello");

	// FileStream �ܿ� �پ��� Stream�� �ִٰ� �����ϸ�
	// Write�� ������ ������ �� ���� => ������
	
}