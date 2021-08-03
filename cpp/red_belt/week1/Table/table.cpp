#include "test_runner.h"
#include <vector>

using namespace std;

// Реализуйте здесь шаблонный класс Table
template <typename T>
class Table{
public:  
  Table (size_t rows, size_t cols){
    Resize(rows, cols);
  }

  vector<T>& operator[](size_t idx){
    return v_[idx];
  }
  const vector<T> operator[](size_t idx) const{
    return v_.at(idx);
  }

  void Resize(size_t rows, size_t cols){
    v_.resize(rows);
    for (auto& item:v_){
      item.resize(cols);
    }
  }

  pair<size_t, size_t> Size() const {
    if (!v_.empty() && !v_[0].empty()) {
      return {v_.size(), v_[0].size()};
    }

    return  {0, 0};
  }


private:
  size_t rows_, cols_;
  vector<vector<T>> v_;
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  
  return 0;
}
