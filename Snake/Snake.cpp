#include "Snake.h"

Snake::Snake(size_t init_length) : bodyVec(init_length, SnakeBody()) {

}

void Snake::setDirect(DirectEnum new_direct) {
	this->direct = new_direct;
}

Snake::DirectEnum Snake::getDirect() const {
	return this->direct;
}

void Snake::move(){
	auto head = this->bodyVec.front();
	switch(direct) {
		case DirectEnum::Up: {
			head.setY(head.getY() - 1);
			break;
		}
		case DirectEnum::Down: {
			head.setY(head.getY() + 1);
			break;
		}
		case DirectEnum::Left: {
			head.setX(head.getX() - 1);
			break;
		}
		case DirectEnum::Right: {
			head.setX(head.getX() + 1);
			break;
		}
		default:{
			break;
		}
	}
	this->bodyVec.pop_back();
	this->bodyVec.insert(this->bodyVec.begin(), head);
}

const SnakeBody& Snake::getHead() const {
	return this->bodyVec.front();
}

const SnakeBody& Snake::getTail() const {
	return this->bodyVec.back();
}

void Snake::setDirect(DirectEnum new_direct) {
	this->direct = new_direct;
}

Snake::DirectEnum Snake::getDirect() const {
	return this->direct;
}
