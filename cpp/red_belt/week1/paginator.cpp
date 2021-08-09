#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

template <typename Iterator>
class IteratorRange {
private:    
    Iterator first, last;
public:
    IteratorRange (Iterator f, Iterator l)
        : first(f)
        , last(l)
        {            
        }
    Iterator begin() const {
        return first;
    }
    Iterator end() const {
        return last;
    }
    size_t size() const {
      return last - first;
    }
};

template <typename Iterator>
class Paginator{
private:
  Iterator begin_, end_;
  size_t page_size_;
public:
  Paginator(Iterator b, Iterator e, size_t p_s)
  : begin_(b)
  , end_ (e)
  , page_size_(p_s)
  {
    auto min_value = [&](Iterator it) {
      return min(distance(it, end), page_size);
    }
  }

  size_t size() const {
    return end_ - begin_;
  }

  Iterator begin() const {
    return begin_;
  }
  Iterator end() const {
    return end_;
  }
};

template <typename C>
auto Paginate(C& c, size_t page_size){
  vector<Paginator<typename C :: iterator>> result;
  auto begin = c.begin();
  auto end = c.begin() + page_size;
  while (end <= c.end()){
    result.push_back(Paginator(begin, end, page_size));
    begin = end;
    end += page_size;
  }
  return result;
};

int main() {
  vector<int> v(15);
  cout << "Paginate 1 " << Paginate(v,1).size() << endl;
  cout << "Paginate 5 " << Paginate(v,5).size() << endl;
  cout << "Paginate 10 " << Paginate(v,10).size() << endl;

  iota(begin(v), end(v), 1);

  Paginator<vector<int>::iterator> paginate_v(v.begin(), v.end(), 6);
  
  for (const auto& page : paginate_v) {
    for (int x : page) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
