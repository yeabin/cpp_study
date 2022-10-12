#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>


// ���� �� ��, ��ȣȭ �ϴ� ��� �ְ� ����.

// ���1. ������ ��ȣȭ => Write ����
// => ��ȣȭ �۾� ���� �ϸ� ����

// ���2. �Ļ� Ŭ���� EncryptFileStream ���� Write�� override.
// => NetworkStream, PipeStream�� �Ļ� Ŭ���� ������ ��

// ���3. ��� Ŭ���� Stream�� ��ȣȭ ��� �߰�
// => OCP ���� ���� (��� �߰��� �� ��� Ŭ���� ����??)

// ���4. ���� Ŭ������ �������� �ʰ�, �̷� �䱸���� �߰��Ǿ�� ��
// => "Decorator!"

struct Stream
{
	virtual void Write(const std::string& s) = 0;
	virtual ~Stream() {}

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

class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	virtual void Write(const std::string& s) override
	{
		std::string str = s + "�����";
		// ���� ��� ����
		stream->Write(str);
		// stream �⺻ ��� ����
	}
};

class EncryptDecorator : public Stream
{
	Stream* stream;
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	virtual void Write(const std::string& s) override
	{
		std::string str = s + "��ȣȭ";
		// ��ȣȭ ��� ����
		stream->Write(str);
		// stream �⺻ ��� ����
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("hello");

	EncryptDecorator ed(&fs);
	ed.Write("Hello");	// 1. Hello �� ��ȣȭ �ϰ� <== �߰��� ���
						// 2. fs.Write(��ȣȭ�ȵ���Ÿ) 

	ZipDecorator zd(&ed);
	zd.Write("Hello");	// 1. �������� �����ϰ�
						// 2. ed.Write() <=== ��ȣȭ ��� ����
						// 3. fs.Write(�����ϰ� ��ȣȭ �� ����Ÿ)

	// ���ο� �䱸 ����(XML�� ����, json���� �����)�� �����
	// "Decorator"�鸸 ��� ����� ��.
}