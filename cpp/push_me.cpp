/*
 * push_me.cpp
 *
 *  Created on: May 29, 2021
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void Dump(vector<string>& task_list){
	cout << task_list.size();
	for (string task: task_list){
		cout << ' ' << task;
	}
}

void AddTask(vector<string>& task_list, string s){
	task_list.push_back(s);
}

int main (){
	vector<int> months = {31, 28, 31, 30, 31, 30,
	                      31, 31, 30, 31, 30, 31};

	int current_month = 0;
	vector<vector<string>> todo(months[current_month]);

	int i;
	string command, s;

	int number_of_inputs;
	int count = 0;
	cin >> number_of_inputs;
	while (number_of_inputs > count){
		cin >> command;
		if (command == "NEXT"){
			++current_month;
			todo.resize(months[current_month]);
		}
		else if(command == "DUMP"){
			cin >> i;
			Dump(todo[i-1]);
		}
		else if(command == "ADD"){
			cin >> i >> s;
			AddTask(todo[i-1], s);
		}
		++count;
	}

	return 0;
}
