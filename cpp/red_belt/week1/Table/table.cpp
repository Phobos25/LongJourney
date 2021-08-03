#include "test_runner.h"
#include <vector>

using namespace std;

// Реализуйте здесь шаблонный класс Table
template <typename T>
class Table{
public:  
  Table <T> (size_t rows, size_t cols){
    rows_ = rows;
    cols_ = cols;
    v_.resize(rows);
    for (size_t i=0; i<v_.size(); ++i){
      v_.resize(cols);      
    }
  }

  int& operator[](size_t row, size_t col){
    return v_[row][col];
  }
  int operator[](size_t row, size_t col) const{
    return v_.at(row).at(col);
  }

  void Resize(size_t rows, size_t cols){
    for (size_t i=0; i<rows; ++i){
      v_[i].resize(cols);
    }
    v_.resize(rows);
  }

  pair<size_t, size_t> Size() const{
    return make_pair(rows_, cols_);
  }

private:
  size_t rows_, cols_;
  vector<vector<T>> v_;
};

void TestTable() {
  // Table<int> t(1, 1);
  // ASSERT_EQUAL(t.Size().first, 1u);
  // ASSERT_EQUAL(t.Size().second, 1u);
  // t[0][0] = 42;
  // ASSERT_EQUAL(t[0][0], 42);
  // t.Resize(3, 4);
  // ASSERT_EQUAL(t.Size().first, 3u);
  // ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  // RUN_TEST(tr, TestTable);
  Table<int> t(1, 1);
  cout << t.Size().first << ' '
       << t.Size().second << endl;
  return 0;
}
