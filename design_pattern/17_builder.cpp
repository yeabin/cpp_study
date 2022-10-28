#include <iostream>
#include <string>

// 축구게임 캐릭터 장비를 생각해보면,
// 캐릭터 객체가 국가별로 모자, 유니폼, 신발을 다르게 입음
typedef std::string Character;		// class Character{}라고 가정
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}

// "Builder" 인터페이스
struct IBuilder
{
	virtual Hat makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Shoes makeShoes() = 0;
	virtual ~IBuilder() {};
};


// 캐릭터를 만드는 클래스
class Director
{
	// 빌더 객체 연결
	IBuilder* pbuilder = nullptr;
public:
	void set_builder(IBuilder* p) { pbuilder = p; }

	Character construct()
	{
		// 국가가 달라도 캐릭터 만드는 공정은 동일
		Character c;
		c = c + pbuilder->makeHat();
		c = c + pbuilder->makeUniform();
		c = c + pbuilder->makeShoes();
		return c;
	}
};

// 국가 별 다양한 빌더 제공
class Korean : public IBuilder
{
public:
	virtual Hat     makeHat()     override { return "갓\n"; }
	virtual Uniform makeUniform() override { return "한복\n"; }
	virtual Shoes   makeShoes()   override { return "고무신\n"; }
};

class American : public IBuilder
{
public:
	virtual Hat     makeHat()     override { return "야구모자\n"; }
	virtual Uniform makeUniform() override { return "양복\n"; }
	virtual Shoes   makeShoes()   override { return "구두\n"; }
};

int main()
{
	Director d;

	Korean k;
	American a;

	d.set_builder(&k);
	d.set_builder(&a); // 국가 변경할 때

	Character c = d.construct();
	std::cout << c << std::endl;

}
