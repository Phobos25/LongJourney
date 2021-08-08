#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

template <typename Iterator>
class Paginator{
private:
  Iterator begin_, end_;
  size_t page_size_;
  size_t num_pages;
  void CountPages(){
    int pages = end_ - begin_;
    if (pages % page_size_ != 0){
      ++num_pages;
    } else {
      num_pages = pages / page_size_;
    }
  }
public:
  Paginator(Iterator b, Iterator e, size_t p_s)
  : begin_(b)
  , end_ (e)
  , page_size_(p_s)
  {
    num_pages = 0;
    CountPages();
  }

  size_t size() const {
    return num_pages;
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
  Paginator<typename C :: iterator>  page(c.begin(), c.end(), page_size);
  return page;
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
