#include <iostream>
#include <vector>

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
        return front_.size() + back_.size();
    }

    T& operator[](size_t index){
        return front_[index];
    }

    const T& operator[](size_t index) const{
        return front_[index];
    }

    T& At(size_t index){
        if (index >= front_.size()){
            throw exception("Out of range");
        }
        return front_.at(index);
    }

    const T& At(size_t index) const{
        if (index >= front_.size()){
            throw exception("Out of range");
        }
        return front_.at(index);
    }

    typename vector<T>::iterator Front(){
        return front_.begin();
    }
    const typename vector<T>::iterator Front() const{
        return front_.begin();
    }

    typename vector<T>::iterator Back(){
        return back_.begin();
    }
    const typename vector<T>::iterator Back() const{
        return back_.begin();
    }

    void PushFront(const T value){
        front_.push_back(value);
    }
    void PushBack(const T value){
        back_.push_back(value);
    }
private:
    vector<T> front_;
    vector<T> back_;
};

int main() {
    Deque<int> d;
    if (d.Empty())     {
        cout << "Deque is empty" << endl;
    }

    d.PushFront(1);
    d.PushBack(2);
    cout << d.Size() << endl;
    return 0;
}
