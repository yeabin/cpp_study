#include <iostream>
#include <vector>


class Subject;
// 클래스 전방 선언하여 포인터 변수를 먼저 만들기

struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}

	Subject* subject;
	// 모든 graph는 자기 자신이 어떤 table과 연결되어 있는지 알아야 함.
};

// 관찰자(graph)들이 등록된 관찰 대상(table)을 edit 하고 싶음.

// 아래 처럼 Subject에서 다양한 table을 파생하여 만들면
// 관찰자 패턴의 기본 로직을 제공받을 수 있음.
// => Observer Pattern
// => 관찰자를 Observer, 관찰 대상을 Subject

class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) 
	{ 
		v.push_back(p);
		p->subject = this;
	}
	void detach(IGraph* p) {}

	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
};

class Table : public Subject
{
	int value;
	int data[5] = { 1,2,3,4,5 };
public:
	int* getData() { return data; }

	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;

			notify(value);
		}
	}
};



class BarGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Bar Graph : ";

		// subject에 접근해서 data를 얻은 후 사용하면 됨.
		// int * data = subject->getData()
		// 위 처럼 할 수 없음. subject는 table의 고유 멤버에 접근할 수 없음.
		// 해결책은 casting 뿐임.
		Table* table = static_cast<Table*>(subject);
		int* data = table->getData();

		for (int i = 0; i < 5; i++)
			std::cout << data[i] << ", ";

		std::cout << std::endl;
	}
};

class PieGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Pie Graph : ";

		Table* table = static_cast<Table*>(subject);

		int* data = table->getData();
		for (int i = 0; i < 5; i++)
			std::cout << data[i] << ", ";

		std::cout << std::endl;
	}
};

int main()
{
	Table t;

	PieGraph pg;
	t.attach(&pg); // table에 pg 부착
	BarGraph bg;
	t.attach(&bg); // table에 bg 부착
	t.edit();
}
