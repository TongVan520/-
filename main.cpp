#include <iostream>
#include "InputReceiver.h"

using namespace std;

//先尝试能否一次性解决所有设计问题

//分治：
//将一个大项目或大体系分解成多个小项目或小体系
//示例：俄罗斯方块

//分解思路：
//输入接收部分、图像显示部分、逻辑处理部分

//创建一个具体类时，需要明确它的职能，以及确定它如何被外部使用

int main(int argc, char* argv[]) {

	InputReceiver<char> input_receiver;
	/*input_receiver['k'] += []() {
		cout << "测试" << endl;
	};*/

	input_receiver.addCallbackFunction('k',
									   []() {
										   cout << "测试" << endl;
									   });

	return 0;
}