#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

// TAirport should be enum with sequential items and last item TAirport::Last_
template <typename TAirport>
class AirportCounter {
public:
  // конструктор по умолчанию: список элементов пока пуст
  AirportCounter();

  // конструктор от диапазона элементов типа TAirport
  template <typename TIterator>
  AirportCounter(TIterator begin, TIterator end);

  // получить количество элементов, равных данному
  size_t Get(TAirport airport) const;

  // добавить данный элемент
  void Insert(TAirport airport);

  // удалить одно вхождение данного элемента
  void EraseOne(TAirport airport);

  // удалить все вхождения данного элемента
  void EraseAll(TAirport airport);

  using Item = pair<TAirport, size_t>;
  using Items = array<Item,static_cast<uint64_t>(TAirport::Last_)>;

  // получить некоторый объект, по которому можно проитерироваться,
  // получив набор объектов типа Item - пар (аэропорт, количество),
  // упорядоченных по аэропорту
  Items GetItems() const;

private:
  array<size_t, static_cast<uint64_t>(TAirport::Last_)> data_;
  const size_t size_ = static_cast<uint64_t>(TAirport::Last_);
};

template <typename TAirport>
AirportCounter<TAirport>::AirportCounter(){
  data_.fill(0);
}

template <typename TAirport>
template <typename TIterator>
AirportCounter<TAirport>::AirportCounter(TIterator begin, TIterator end){
  auto it = begin;
  while (it != end){
    data_[static_cast<uint64_t>(*it)]++;
    ++it;
  }
}

template <typename TAirport>
size_t AirportCounter<TAirport>:: Get(TAirport airport) const{
  auto it = static_cast<uint64_t>(airport);
  return data_[it];
}

template <typename TAirport>
void AirportCounter<TAirport>:: Insert(TAirport airport){
  auto it = static_cast<uint64_t>(airport);
  data_[it]++;
}

template <typename TAirport>
void AirportCounter<TAirport>:: EraseOne(TAirport airport){
  auto it = static_cast<uint64_t>(airport);
  if (data_.at(it) > 0){
    data_[it]--;
  }
}

template <typename TAirport>
void AirportCounter<TAirport>:: EraseAll(TAirport airport){
  auto it = static_cast<uint64_t>(airport);
  data_[it] = 0;
}

template <typename TAirport>
array<pair<TAirport, size_t>,static_cast<uint64_t>(TAirport::Last_)> AirportCounter<TAirport>:: GetItems() const{
  Items item_array;
  for (size_t i=0; i<size_; ++i){
    item_array[i] = make_pair(static_cast<TAirport>(i), data_[i]);
  }
  return item_array;
}

int main() {
  enum class MoscowAirport {
    VKO,
    SVO,
    DME,
    ZIA,
    Last_
  };

  const vector<MoscowAirport> airports = {
      MoscowAirport::SVO,
      MoscowAirport::VKO,
      MoscowAirport::ZIA,
      MoscowAirport::SVO,
  };
  AirportCounter<MoscowAirport> airport_counter(begin(airports), end(airports));
  cout << "SVO:" <<airport_counter.Get(MoscowAirport::SVO) << endl;
  cout << "DME:" <<airport_counter.Get(MoscowAirport::DME) << endl;
  cout << "ZIA:" <<airport_counter.Get(MoscowAirport::ZIA) << endl;
  cout << "VKO:" <<airport_counter.Get(MoscowAirport::VKO) << endl;
  return 0;
}