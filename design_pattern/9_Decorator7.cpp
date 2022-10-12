#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>


// 파일 쓸 때, 암호화 하는 기능 넣고 싶음.

// 방법1. 데이터 암호화 => Write 전달
// => 암호화 작업 자주 하면 불편

// 방법2. 파생 클래스 EncryptFileStream 만들어서 Write을 override.
// => NetworkStream, PipeStream도 파생 클래스 만들어야 함

// 방법3. 기반 클래스 Stream에 암호화 기능 추가
// => OCP 만족 못함 (기능 추가할 때 기반 클래스 변경??)

// 방법4. 기존 클래스는 수정되지 않고, 미래 요구사항 추가되어야 함
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
		printf("%s 쓰기\n", buff.c_str());
	}
};

class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	virtual void Write(const std::string& s) override
	{
		std::string str = s + "압축됨";
		// 압축 기능 수행
		stream->Write(str);
		// stream 기본 기능 수행
	}
};

class EncryptDecorator : public Stream
{
	Stream* stream;
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	virtual void Write(const std::string& s) override
	{
		std::string str = s + "암호화";
		// 암호화 기능 수행
		stream->Write(str);
		// stream 기본 기능 수행
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("hello");

	EncryptDecorator ed(&fs);
	ed.Write("Hello");	// 1. Hello 를 암호화 하고 <== 추가된 기능
						// 2. fs.Write(암호화된데이타) 

	ZipDecorator zd(&ed);
	zd.Write("Hello");	// 1. 압축기능을 수행하고
						// 2. ed.Write() <=== 암호화 기능 수행
						// 3. fs.Write(압축하고 암호화 된 데이타)

	// 새로운 요구 사항(XML로 쓰기, json으로 쓰기등)이 생기면
	// "Decorator"들만 계속 만들면 됨.
}

/*
// 정리2

// 객체지향 디자인의 핵심 1. 공통성과 가변성의 분리 - 정리1 참고
// 
// 객체지향 디자인의 핵심 2. 재귀적 포함

// "A 는 B를 포함하지만 A 자신도 포함할수 있다."
// => A와 B는 동일한 기반 클래스가 있어야 한다.!!
// => 왜.. 재귀적 포함을 사용하는데 ?? 의도가 뭔데 ??

// 복합객체를 만들기 위해 : Composite 패턴
//						Folder/File, PopupMenu/MenuItem
//						여러개의 객체를 보관.

// 객체에 동적으로 기능을 추가하려면 : Decorator
//						FileStream/ZipDecorator 예제
//						여러개의 객체를 포함하는것이 아니라
//						하나의 객체에 여러개의 기능(동작)을 추가하는것

// => Composite 와 Decorator 의 클래스 Diagram 은 유사합니다
*/
