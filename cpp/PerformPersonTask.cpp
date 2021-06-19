#include <tuple>
#include <map>
#include <string>
#include <iostream>
using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
    return tasks_.at(person);
  }

  // Добавить новую задачу (в статусе NEW) для конкретного разработчика
  void AddNewTask(const string& person){
    tasks_[person][TaskStatus::NEW] += 1;
  }

  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count){

    TasksInfo updated, untouched;
    TasksInfo baseTasks = tasks_[person];

    if(tasks_.count(person) == 0){
      return tie(updated, untouched);
    }

    for(int i=0; i<task_count; ++i){
      if (tasks_[person][TaskStatus::NEW]>0){
        updated[TaskStatus::IN_PROGRESS] +=1;
        tasks_[person][TaskStatus::NEW] -= 1;
      }else if(tasks_[person][TaskStatus::IN_PROGRESS]>0){
        updated[TaskStatus::TESTING] += 1;
        tasks_[person][TaskStatus::IN_PROGRESS] -= 1;
      }else if (tasks_[person][TaskStatus::TESTING]>0){
        updated[TaskStatus::DONE] += 1;
        tasks_[person][TaskStatus::TESTING] -= 1;
      }
    }
    //остаток заданий это untouched
    untouched = tasks_[person];
    untouched.erase(TaskStatus::DONE);

    tasks_[person][TaskStatus::IN_PROGRESS] += updated[TaskStatus::IN_PROGRESS];
    tasks_[person][TaskStatus::TESTING] += updated[TaskStatus::TESTING];
    tasks_[person][TaskStatus::DONE] += updated[TaskStatus::DONE];

    EraseEmpty(updated);
    EraseEmpty(untouched);
    EraseEmpty(tasks_[person]);
    return tie(updated, untouched);
  }

private:
  map<string, TasksInfo> tasks_;
  void EraseEmpty(TasksInfo& tasks){
    for(auto it = tasks.begin(); it!=tasks.end();){
      if(it->second == 0){
        it = tasks.erase(it);
      }else{
        ++it;
      }
    }
  }
};

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}


int main() {
  TeamTasks tasks;

  //  Input:
  //  AddNewTasks Alice 5
  //  PerformPersonTasks Alice 5
  //  PerformPersonTasks Alice 5
  //  PerformPersonTasks Alice 1
  //  AddNewTasks Alice 5
  //  PerformPersonTasks Alice 2
  //  GetPersonTasksInfo Alice
  //  PerformPersonTasks Alice 4
  //  GetPersonTasksInfo Alice
  TasksInfo updated, unchanged;
  for (int i=0; i<5; ++i){
    tasks.AddNewTask("Alice");
  }
  tasks.PerformPersonTasks("Alice", 5);
  tasks.PerformPersonTasks("Alice", 5);
  tasks.PerformPersonTasks("Alice", 1);
  for (int i=0; i<5; ++i){
    tasks.AddNewTask("Alice");
  }
  tasks.PerformPersonTasks("Alice", 2);
  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

  return 0;
}

