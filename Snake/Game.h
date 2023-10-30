#pragma once
#include "Snake.h"
#include "Map.h"

enum class ActorCharacterEnum {
	//墙
	Wall = '#', 

	//蛇身
	SnakeBody = 'O', 

	//食物
	Food = '*', 
}

class Game {
private:
	//蛇
	Snake snake;
	//地图
	Map map;

	//游戏开始标志
	bool is_start = false;

public:
	Game(size_t init_map_width, size_t init_map_height, size_t init_snake_length);

	//开始游戏
	void start();

	//结束游戏
	void over();

	//更新
	void update();

	//输入
	void input();

	//显示地图
	void showMap();

	//判断游戏是否结束，并处理
	void judge();
};
