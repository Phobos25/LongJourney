#pragma once

#include <stdexcept>
#include <array>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
  explicit StackVector(size_t a_size = 0) {
    size_ = a_size;
    capacity_ = N;
  }

  T& operator[](size_t index);
  const T& operator[](size_t index) const;

  T* begin();
  T* end();
  const T* begin() const;
  const T* end() const;

  size_t Size() const;
  size_t Capacity() const;

  void PushBack(const T& value);
  T PopBack();

private:
  size_t size_;
  size_t capacity_;
  size_t index_ = 0;
  array<T, N> arr;
};

template <typename T, size_t N>
T& StackVector<T, N> :: operator[] (size_t index){
  return arr[index];
}

template <typename T, size_t N>
const T& StackVector<T, N> :: operator[] (size_t index) const{
  return arr[index];
}

template <typename T, size_t N>
size_t StackVector<T, N>::Size() const {
  return size_;
}

template <typename T, size_t N>
size_t StackVector<T, N> :: Capacity() const {
  return capacity_;
}

template <typename T, size_t N>
void StackVector<T, N> :: PushBack(const T& value) {
  if (size_ >= capacity_) {
    throw exception();
  }
  if (index_ >= size_){
    ++size_;
  }
  arr[index_++] = value;
}

template <typename T, size_t N>
T StackVector<T, N> :: PopBack(){
  --index_;
  return size_--;
}
