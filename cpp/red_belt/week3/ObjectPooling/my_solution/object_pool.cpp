#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
  T* Allocate(){
    if (free_obj.empty()){
      T* ptr = new T;      
      allocated_obj.push_back(ptr);
      return ptr;
    } else {
      T* ptr = free_obj.front();
      free_obj.pop_front();
      allocated_obj.push_back(ptr);
      return ptr;
    }
  }
  T* TryAllocate(){
    if (free_obj.empty()){
      return nullptr;      
    } else {
       return free_obj.front();       
    }
  }

  void Deallocate(T* object) {
    auto it = find(allocated_obj.begin(), allocated_obj.end(), object);
    if (it != allocated_obj.end()){
      free_obj.push_back(object);
      allocated_obj.erase(it);
    } else {
      throw runtime_error("invalid_argument");
    }
  }

  ~ObjectPool() {
    while( !allocated_obj.empty() ) {
      auto object = allocated_obj.front();
      allocated_obj.pop_front();
      delete object;      
    }
    while( !free_obj.empty() ) {
      auto object = free_obj.front();      
      free_obj.pop_front();     
      delete object;
    }
    
  }

private:
  deque<T*> allocated_obj;
  deque<T*> free_obj;
};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
