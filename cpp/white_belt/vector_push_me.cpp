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

void TransferTasks(vector<string>& task_list, const vector<vector<string>>& todo, int days){
	for (int i=31-days; i<31; ++i){
		task_list.insert(std::end(task_list), std::begin(todo[i]), std::end(todo[i]));
	}

}

int main (){
	vector<int> months = {31, 28, 31, 30, 31, 30,
	                      31, 31, 30, 31, 30, 31};

	int current_month = 0;
	vector<vector<string>> todo(months[current_month]);

	int i;
	string command, s;

	int diff;
	int number_of_inputs;
	int count = 0;
	cin >> number_of_inputs;
	while (number_of_inputs > count){
		cin >> command;
		if (command == "NEXT"){
			++current_month;
			if (current_month > 11){
				current_month = 0;
				diff = 0;
			}
			else{
				diff = months[current_month] - months[current_month-1];
			}

			if (diff < 0){
				int day = months[current_month] - 1;
				TransferTasks(todo[day], todo, abs(diff));
			}

			todo.resize(months[current_month]);
		}
		else if(command == "DUMP"){
			cin >> i;
			Dump(todo[i-1]);
			cout << "\n";
		}
		else if(command == "ADD"){
			cin >> i >> s;
			AddTask(todo[i-1], s);
		}
		++count;
	}

	return 0;
}
