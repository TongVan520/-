#include "SnakeBody.h"

SnakeBody::SnakeBody(NumberType init_x, NumberType init_y) : x(init_x), y(init_y) {

}

void SnakeBody::setAll(NumberType new_x, NumberType new_y){
	this->x = new_x;
	this->y = new_y;
}

void SnakeBody::setX(NumberType new_x){
	this->x = new_x;
}

void SnakeBody::setY(NumberType new_y){
	this->y = new_y;
}

NumberType SnakeBody::getX() const {
	return this->x;
}

NumberType SnakeBody::getY() const {
	return this->y;
}
