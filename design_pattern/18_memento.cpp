#include <iostream>
#include <vector>
#include <map>

// Memento 패턴
// => 객체가 자신의 상태를 저장했다가, 복구 할수 있게 한다.
// => 멤버 데이터를 외부에서 접근하지 않아도
//    상태 백업을 저장할 수 있도록 함.

class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	// 백업 데이터들을 별도 클래스로 설계
	struct Memento
	{
		int penWidth;
		int penColor;
	};
	std::map<int, Memento*> memento_map;

public:
	// Memento 저장
	int Save()
	{
		static int key = 0; 
		++key;

		Memento* p = new Memento;
		p->penColor = penColor;
		p->penWidth = penWidth;

		memento_map[key] = p;

		return key;
	}
	// Memento 복구
	void Restore(int key)
	{
		Memento* p = memento_map[key];

		if (p != nullptr)
		{
			penColor = p->penColor;
			penWidth = p->penWidth;
		}
	}

	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};


int main()
{
	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200);

	// 여기서 객체의 상태를 백업해 놓을 수 있음
	// 객체 멤버 데이터에 접근하지 않아도 가능함.
	int token = g.Save();

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 복구 가능!
	g.Restore(token);
}

