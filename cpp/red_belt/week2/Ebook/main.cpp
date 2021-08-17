#include "test_runner.h"
#include "profile.h"

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

    return (pages[0] - pages[users[user_id]]) * 1.0 / (pages[0]);
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

// ----------------------------------------------------------------------------------------------------
void TestReadPage()
{  LOG_DURATION("Total test duration") ;
   {
       ReadingManager manager;
       ASSERT_EQUAL(manager.Cheer(1), 0.0);
       manager.Read(1, 1);
       ASSERT_EQUAL(manager.Cheer(1), 1.0);
   }
   {
       ReadingManager manager;
       ASSERT_EQUAL(manager.Cheer(1), 0.0);
       manager.Read(1, 1);
       ASSERT_EQUAL(manager.Cheer(2), 0.0);
   }
   {
       ReadingManager manager;
       manager.Read(1, 1);
       ASSERT_EQUAL(manager.Cheer(1), 1.0);
       manager.Read(1, 2);
       ASSERT_EQUAL(manager.Cheer(1), 1.0);
   }
   {
       ReadingManager manager;
       manager.Read(1, 1);
       manager.Read(2, 2);
       manager.Read(3, 3);
       ASSERT_EQUAL(manager.Cheer(2), 0.5);
       manager.Read(4, 4);
       ASSERT_EQUAL(manager.Cheer(2), 1.0 / 3.0);
   }
   {
       ReadingManager manager;
       manager.Read(1, 1);
       manager.Read(2, 2);
       manager.Read(3, 3);
       ASSERT_EQUAL(manager.Cheer(2), 0.5);
       manager.Read(4, 4);
       ASSERT_EQUAL(manager.Cheer(3), 2.0 / 3.0);
   }
   {
       ReadingManager manager;
       manager.Read(1, 0);
       manager.Read(2, 0);
       manager.Read(3, 1);
       manager.Read(4, 2);
       ASSERT_EQUAL(manager.Cheer(3), 2.0 / 3.0);
   }
   {
       ReadingManager manager;
       manager.Read(1, 5);
       manager.Read(2, 5);
       manager.Read(3, 5);
       manager.Read(4, 5);
       ASSERT_EQUAL(manager.Cheer(3), 0.0);
   }
   {
       ReadingManager manager;
       manager.Read(4, 5);
       manager.Read(3, 4);
       manager.Read(2, 3);
       manager.Read(1, 2);
       ASSERT_EQUAL(manager.Cheer(3), 2.0 / 3.0);
   }
   {
       ReadingManager manager;
       manager.Read(4, 5);
       manager.Read(3, 4);
       manager.Read(4, 6);
       manager.Read(3, 5);
       ASSERT_EQUAL(manager.Cheer(4), 1.0);
       ASSERT_EQUAL(manager.Cheer(3), 0.0);
       manager.Read(10, 2);
       ASSERT_EQUAL(manager.Cheer(3), 0.5);
       ASSERT_EQUAL(manager.Cheer(4), 1.0);
   }
   {
       ReadingManager manager;
       manager.Read(4, 5);
       ASSERT_EQUAL(manager.Cheer(4), 1.0);
       manager.Read(4, 6);
       ASSERT_EQUAL(manager.Cheer(4), 1.0);
       manager.Read(4, 100);
       ASSERT_EQUAL(manager.Cheer(4), 1.0);
       ASSERT_EQUAL(manager.Cheer(3), 0.0);
       ASSERT_EQUAL(manager.Cheer(5), 0.0);
   }
   {// ten users
       ReadingManager manager;
       manager.Read(1, 1);
       manager.Read(2, 2);
       manager.Read(3, 3);
       manager.Read(4, 4);
       manager.Read(5, 5);
       manager.Read(6, 6);
       manager.Read(7, 7);
       manager.Read(8, 8);
       manager.Read(9, 9);
       manager.Read(100, 10);
       manager.Read(111, 11);

       ASSERT_EQUAL(manager.Cheer(1), 0.0);
       ASSERT_EQUAL(manager.Cheer(2), 0.1);
       ASSERT_EQUAL(manager.Cheer(3), 0.2);
       ASSERT_EQUAL(manager.Cheer(4), 0.3);
       ASSERT_EQUAL(manager.Cheer(5), 0.4);
       ASSERT_EQUAL(manager.Cheer(6), 0.5);
       ASSERT_EQUAL(manager.Cheer(7), 0.6);
       ASSERT_EQUAL(manager.Cheer(8), 0.7);
       ASSERT_EQUAL(manager.Cheer(9), 0.8);
       ASSERT_EQUAL(manager.Cheer(100), 0.9);
       ASSERT_EQUAL(manager.Cheer(111), 1.0);
       ASSERT_EQUAL(manager.Cheer(12), 0.0);
   }
   {
       ReadingManager manager;

       ASSERT_EQUAL(manager.Cheer(1), 0.0);
       ASSERT_EQUAL(manager.Cheer(1), 0.0);
       manager.Read(1, 1);
       ASSERT_EQUAL(manager.Cheer(1), 1.0);
       ASSERT_EQUAL(manager.Cheer(1), 1.0);

       ASSERT_EQUAL(manager.Cheer(2), 0);
   }
   {   LOG_DURATION("MAX_USER_COUNT1");
       const int MAX_USER_COUNT = 100'000;
       ReadingManager manager;
       ASSERT_EQUAL(manager.Cheer(MAX_USER_COUNT), 0.0);
       manager.Read(MAX_USER_COUNT, 1);
       ASSERT_EQUAL(manager.Cheer(MAX_USER_COUNT), 1.0);
   }
   { 
       ReadingManager manager;
       ASSERT_EQUAL(manager.Cheer(1), 0.0);
       manager.Read(1, 1000);
       ASSERT_EQUAL(manager.Cheer(1), 1.0);
   }
   {   LOG_DURATION("MAX_USER_COUNT2");
       const int MAX_USER_COUNT = 100'000;
       ReadingManager manager;
       ASSERT_EQUAL(manager.Cheer(MAX_USER_COUNT), 0.0);
       manager.Read(MAX_USER_COUNT, 1000);
       ASSERT_EQUAL(manager.Cheer(MAX_USER_COUNT), 1.0);
   }
   {
       ReadingManager manager;
       ASSERT_EQUAL(manager.Cheer(0), 0.0);
       manager.Read(0, 1000);
       ASSERT_EQUAL(manager.Cheer(0), 1.0);
   }
   {// from coursera (https://www.coursera.org/learn/c-plus-plus-red/programming/e72ST/eliektronnaia-knigha/discussions/threads/hLK3cT0AEemHtRKqiMW_lA)
       ReadingManager manager;
       manager.Read(1, 1);
       manager.Read(1, 3);
       manager.Read(2, 2);
       ASSERT_EQUAL(manager.Cheer(1), 1.0);
       ASSERT_EQUAL(manager.Cheer(2), 0.0);
   }
}

int main() {
  // Для ускорения чтения данных отключается синхронизация
  // cin и cout с stdio,
  // а также выполняется отвязка cin от cout
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  TestRunner tr;
  tr.RunTest(TestReadPage, "TestReadPage");

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