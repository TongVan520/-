#include <iostream>
#include "InputReceiver.h"

using namespace std;

//�ȳ����ܷ�һ���Խ�������������

//���Σ�
//��һ������Ŀ�����ϵ�ֽ�ɶ��С��Ŀ��С��ϵ
//ʾ��������˹����

//�ֽ�˼·��
//������ղ��֡�ͼ����ʾ���֡��߼�������

//����һ��������ʱ����Ҫ��ȷ����ְ�ܣ��Լ�ȷ������α��ⲿʹ��

int main(int argc, char* argv[]) {

	InputReceiver<char> input_receiver;
	/*input_receiver['k'] += []() {
		cout << "����" << endl;
	};*/

	input_receiver.addCallbackFunction('k',
									   []() {
										   cout << "����" << endl;
									   });

	return 0;
}