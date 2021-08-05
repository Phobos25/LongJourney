#include <iostream>
#include <vector>
#include <exception>

using namespace std;

template<typename T>
class Deque{
public:
    Deque() {};
    
    bool Empty() const {
        if (front_.empty() && back_.empty()){
            return true;
        } else {
            return false;
        }        
    }

    size_t Size() const{
        return deque_.size();
    }

    T& operator[](size_t index){
        return deque_[index];
    }

    const T& operator[](size_t index) const{
        return deque_[index];
    }

    T& At(size_t index){
        if (index >= deque_.size()-1){
            throw runtime_error("Out of range");
        }
        return deque_.at(index);
    }

    const T& At(size_t index) const{
        if (index >= deque_.size()-1){
            throw runtime_error("Out of range");
        }
        return deque_.at(index);
    }

    typename vector<T>::iterator Front(){
        return deque_.begin();
    }
    const typename vector<T>::iterator Front() const{
        return deque_.begin();
    }

    typename vector<T>::iterator Back(){
        return deque_.end();
    }
    const typename vector<T>::iterator Back() const{
        return deque_.end();
    }

    void PushFront(const T value){
        front_.push_back(value);
        UpdateDeque();
    }
    void PushBack(const T value){
        back_.push_back(value);
        UpdateDeque();
    }

private:
    vector<T> front_;
    vector<T> back_;
    vector<T> deque_;
void UpdateDeque(){
    deque_.clear();
    deque_.insert(deque_.end(), front_.begin(), front_.end());
    deque_.insert(deque_.end(), back_.begin(), back_.end());
}    
};

int main() {
    Deque<int> d;
    if (d.Empty())     {
        cout << "Deque is empty" << endl;
    }
    
    for (int i =0; i<10; ++i){
        d.PushBack(i);
    }

    for (int i =0; i<10; ++i){
        d.PushFront(-i);
    }
    
    int num = d.Size();
    cout << num << endl;

    for (int i=0; i<num; ++i){
        cout << d[i] << ' ';
    }
    cout << endl;

    d[0] = 100;
    cout << d.At(0);
    // cout << d.At(0) << endl;    
    return 0;
}
