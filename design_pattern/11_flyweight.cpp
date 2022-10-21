#include <iostream>
#include <string>
#include <map>

// 동일 그림을 2번 다운로드 할 필요는 없으므로
// 속성이 동일한 객체는 공유하는 것이 좋음
// => "FlyWeight" 패턴

class Image
{
	std::string image_url;
	Image(std::string url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	friend class ImageFactory;
	// 객체 생성하는 함수를
	// static 멤버 함수로 만들면
	// 객체의 생성을 한 곳에서만 함.
	// => 관리를 다양하게 할 수 있음.

	// => Single Responsibility Principle에 따라 객체 생성과 공유를 관리하는 전용 클래스 생성
};


class ImageFactory
{
	static std::map<std::string, Image*> image_map;

public:
	static ImageFactory& getInstance()
	{
		static ImageFactory s;
		return s;
	}

	static Image* Create(const std::string& url)
	{
		auto ret = image_map.find(url);

		Image* img = nullptr;
		
		if (ret != image_map.end())
		{
			img = ret->second;
		}
		else
		{
			img = new Image(url);
			image_map[url] = img;
		}

		return img;
	}
};


int main()
{
	ImageFactory& factory = ImageFactory::getInstance();

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();
}



