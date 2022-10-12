#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� ���� ������ �ʴ� �Ͱ� �и�
// ���1. ���ϴ� �κ��� �����Լ���! (template method ����)

// => Edit �� Validatioin ��å�� ���� �Ǿ� �ִ�.
// => NumEdit �ȿ� �ִ� Validation ��å�� NumEdit �� ��밡��

class Edit
{
	std::string data;
public:
	virtual bool validate(char c)
	{
		return true;
	}

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break;

			if (validate(c)) // �����Լ� ȣ��
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << '\n';
		return data;
	}
};

class NumEdit : public Edit
{
public:
	virtual bool validate(char c) override
	{
		return isdigit(c);
	}
};
// => NumEdit�� ��å�� �����ϰ� �����Ƿ� �������� ��å ��ü �ȵ�


int main()
{
	NumEdit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


// => ���ϴ� ��(��å)�� �������� ������ �ʿ� ����, 
//    ��å�� �ٸ� ������ ����� �ʿ䰡 ���ٸ�
//    template method �� ����.
//    ���� �����ڷ� ��ȣ �����ϰ�, ��� ����Ÿ ���ٵ� ����.