#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 변하지 않는 것과 분리
// 방법1. 변하는 부분을 가상함수로! (template method 패턴)

// => Edit 와 Validatioin 정책이 결합 되어 있다.
// => NumEdit 안에 있는 Validation 정책은 NumEdit 만 사용가능

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

			if (validate(c)) // 가상함수 호출
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
// => NumEdit가 정책을 포함하고 있으므로 동적으로 정책 교체 안됨


int main()
{
	NumEdit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


// => 변하는 것(정책)을 동적으로 변경할 필요 없고, 
//    정책을 다른 곳에서 사용할 필요가 없다면
//    template method 가 좋다.
//    접근 지정자로 보호 가능하고, 멤버 데이타 접근도 쉽다.