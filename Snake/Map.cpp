#include "Map.h"

Map::Map(size_t init_width, size_t init_height) : dataStrVec(init_height, string(init_width, '#')) {

}

//判断是否越界
bool Map::isOutOfRange(int64_t x, int64_t y) const {
	return (x < 0 || x >= this->dataStrVec.at(0).size()) || 
		(y < 0 || y >= this->dataStrVec.size());
}

//读写点
void Map::setPoint(int64_t x, int64_t y, char new_point) {
	this->dataStrVec[y][x] = new_point;
}

char Map::getPoint() const {
	return this->dataStrVec.at(y).at(x);
}

size_t Map::getWidth() const {
	if(!this->dataStrVec.size()){
		return 0;
	}
	return this->dataStrVec.at(0).size();
}

size_t Map::getHeight() const {
	return this->dataStrVec.size();
}
