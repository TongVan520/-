#pragma once
#include <cstdint>

using std::int64_t;

class SnakeBody {
public:
	using NumberType = int64_t;

private:
	//位置
	NumberType x = 0, y = 0;

public:
	SnakeBody() = default;
	SnakeBody(NumberType init_x, NumberType init_y);

	void setAll(NumberType new_x, NumberType new_y);

	void setX(NumberType new_x);
	void setY(NumberType new_y);
	NumberType getX() const;
	NumberType getY() const;
};