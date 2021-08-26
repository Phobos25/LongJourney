#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
  SimpleVector(){
    data = nullptr;    
    end_ = data;
    capacity_ = 0;
  }

  explicit SimpleVector(size_t size){
    data = new T[size];
    end_ = data + size;
    capacity_ = size;
  }

  ~SimpleVector(){
    delete[] data;
  }

  T& operator[](size_t index){
    return data[index];
  }

  T* begin(){return data; }
  T* end()  {return end_; }

  const T* begin() const {return data; }
  const T* end()   const {return end_; }

  size_t Size() const{
    return end_ - data;
  }
  size_t Capacity() const{
    return capacity_;
  }
  void PushBack(const T& value){
    if (Size() == 0){
      capacity_ = 1;         
      data = (T*)realloc(data, capacity_);                 
      end_ = data;
    }
    if (Size() == capacity_){
      capacity_ *= 2;
      data = (T*)realloc(data, capacity_);           
    }
    size_t i = Size();
    data[i] = value;
    ++end_; 
  }
 
private:
  T* data;  
  T* end_;
  size_t capacity_;  
};

