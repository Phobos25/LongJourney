#include "test_runner.h"

using namespace std;

// Реализуйте здесь шаблонный класс Table
template <typename T>
class Table{
  Table(size_t rows, size_t cols);

  int& operator[](size_t rows, size_t cols);
  int operator[](size_t rows, size_t cols) const;

  void Resize(size_t rows, size_t cols);
  pair<size_t, size_t> Size() const;
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
