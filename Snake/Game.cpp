#include "Game.h"
#include <chrono>
#include <conio.h>
#include <thread>

using namespace std;

Game::Game(size_t init_map_width, 
	size_t init_map_height, 
	size_t init_snake_length) : 
	map(init_map_width, init_map_height), 
	snake(init_length) {

}


void Game::start() {
	if(this->is_start){
		return;
	}

	while(this->is_start) {
		//...
		this->showMap();
		this->input();
		this->update();
		this->judge();
		this_thread::sleep_for(chrono::milliseconds(200));
	}
}

void Game::over() {
	this->is_start = false;
}

void Game::update() {
	this->snake.move();
	auto head = this->snake.getHead();
	static auto tail = this->snake.getTail();

	this->map.setPoint(head.getX(), head.getY(), ActorCharacterEnum::SnakeBody);
	this->map.setPoint(tail.getX(), tail.getY(), ActorCharacterEnum::SnakeBody);
	
	tail = this->snake.getTail();
}

void Game::input() {
	if(_kbhit()){
		char input = _getch();
		
		switch(input) {
			case 'w':{
				this->snake.setDirect(DirectEnum::Up);
				break;
			}
			case 's':{
				this->snake.setDirect(DirectEnum::Down);
				break;
			}
			case 'a':{
				this->snake.setDirect(DirectEnum::Left);
				break;
			}
			case 'd':{
				this->snake.setDirect(DirectEnum::Right);
				break;
			}
			default :{
				break;
			}
		}
	}
}

void Game::showMap(){
	system("cls");
	for(auto i = 0; i < this->map.getWidth(); i++){
		for(auto j = 0; j < this->map.getHeight(); j++) {
			cout << this->map.getPoint(i, j);
		}
		cout << endl;
	}
}

void Game::judge() {
	if(this->map.isOutOfRange(this->snake.getX(), this->snake.getY())){
		this->is_start = false;
	}
}
