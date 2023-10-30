#pragma once
#include <vector>
#include <string>
#include <cstdint>

using std::vector, std::string, std::int64_t;

class Map {
private:
	//数据
	vector<string> dataStrVec;

public:
	Map(size_t init_width, size_t init_height);

	//判断是否越界
	bool isOutOfRange(int64_t x, int64_t y) const;

	//读写点
	void setPoint(int64_t x, int64_t y, char new_point);
	char getPoint() const;

	//获取宽高
	size_t getWidth() const;
	size_t getHeight() const;
};
