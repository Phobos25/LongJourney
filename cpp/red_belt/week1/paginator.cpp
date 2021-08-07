#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

template <typename Iterator>
class Paginator{
private:
    Iterator begin_, end_;
    size_t page_size_;
    size_t num_pages;
public:
    Paginator(Iterator b, Iterator e, size_t p_s)   
        : begin_(b)
        , end_ (e)
        , page_size_(p_s)
        {
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
 
template <typename C> ??? Paginate(C& c, size_t page_size)

vector<vector<Application>> DistributeAmongScreens(const vector<Application>& apps) {  
  vector<vector<Application>> result;  
  for (const auto& page : Paginate(apps, 20)) {
    result.push_back({page.begin(), page.end()});
  }
  // result[0] - все приложения, которые попадают на первый экран,
  // result[1] - все приложения, которые попадают на второй экран и т.д.
  return result;
}

int main() {

}