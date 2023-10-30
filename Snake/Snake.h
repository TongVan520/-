#pragma once
#include <vector>
#include "SnakeBody.h"

using std::vector;

enum class DirectEnum {
	Up, 
	Down, 
	Left, 
	Right, 
};

class Snake {
private:
	//身体
	vector<SnakeBody> bodyVec;

	//方向
	DirectEnum direct = DirectEnum::Right;

public:
	Snake(size_t init_length);

	//移动
	void move();

	//获取蛇头
	const SnakeBody& getHead() const;
	//获取蛇尾
	const SnakeBody& getTail() const;

	//读写方向
	void setDirect(DirectEnum new_direct);
	DirectEnum getDirect() const;
};
