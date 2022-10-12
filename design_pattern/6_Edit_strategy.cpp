#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 변하지 않는 것과 분리
// 방법1. 변하는 부분을 다른 클래스로 분리 (strategy 패턴)

// => Edit은 변하지 않는 기능
// => Validation 정책은 변하는 부분

// 다양한 Validation 정책들의 기반 클래스 (interface)
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};

class Edit
{
	std::string data;
	IValidator* pval = nullptr;
public:
	void setValidator(IValidator* p) { pval = p; }

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && (pval == nullptr || pval->iscomplete(data))) break;

			if (pval == nullptr || pval->validate(data, c))
				// validate 함수를 다른 클래스에 위임
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << '\n';
		return data;
	}
};

// 이제 다양한 정책을 가진 "validation 클래스"를 만들면 됨.
class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int n) : value(n) {}

	virtual bool validate(const std::string& s, char c) override
	{
		return s.size() < value && isdigit(c);
	}

	virtual bool iscomplete(const std::string& s) override
	{
		return s.size() == value;
	}
};



int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.setValidator(&v);

	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}

// 장점
// => 다른 입력 도구에서도 Validation 정책클래스 사용가능
// => 동적으로(실행시간에) 정책 교체가 가능
// => template method보다 유연하다.

// 이 예제는 QT 라는 라이브러리 안에 있는
// QEdit/QValidator 를 쉽게 변경한 코드입니다.
