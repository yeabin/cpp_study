#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� ���� ������ �ʴ� �Ͱ� �и�
// ���1. ���ϴ� �κ��� �ٸ� Ŭ������ �и� (strategy ����)

// => Edit�� ������ �ʴ� ���
// => Validation ��å�� ���ϴ� �κ�

// �پ��� Validation ��å���� ��� Ŭ���� (interface)
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
				// validate �Լ��� �ٸ� Ŭ������ ����
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << '\n';
		return data;
	}
};

// ���� �پ��� ��å�� ���� "validation Ŭ����"�� ����� ��.
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

// ����
// => �ٸ� �Է� ���������� Validation ��åŬ���� ��밡��
// => ��������(����ð���) ��å ��ü�� ����
// => template method���� �����ϴ�.

// �� ������ QT ��� ���̺귯�� �ȿ� �ִ�
// QEdit/QValidator �� ���� ������ �ڵ��Դϴ�.