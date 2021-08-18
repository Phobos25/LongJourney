#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class ReadingManager {
public:
  ReadingManager()
      : users(MAX_USER_COUNT_ + 1, -1),        
        pages(MAX_PAGE_COUNT_ + 1, 0) {}

  void Read(int user_id, int page_count) {
    for (int i = users[user_id] + 1; i<=page_count; ++i){
      ++pages[i];
    }
    users[user_id] = page_count;
  }

 double Cheer(int user_id) const {
    if (users[user_id] == -1){
      return 0;
    }
    if (pages[0] == 1){
      return 1;
    }

    return (pages[0] - pages[users[user_id]]) * 1.0 / (pages[0]-1);
  }
private:
  // Статическое поле не принадлежит какому-то конкретному
  // объекту класса. По сути это глобальная переменная,
  // в данном случае константная.
  // Будь она публичной, к ней можно было бы обратиться снаружи
  // следующим образом: ReadingManager::MAX_USER_COUNT.
  static const int MAX_USER_COUNT_ = 100'000;
  static const int MAX_PAGE_COUNT_ = 1'000;

  vector<int> users;
  vector<int> pages;
  
};


int main() {
  // Для ускорения чтения данных отключается синхронизация
  // cin и cout с stdio,
  // а также выполняется отвязка cin от cout
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    } 
  }

  return 0;
}