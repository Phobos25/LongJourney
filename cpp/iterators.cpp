#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

template <class It>
void PrintRange(
    It range_begin,
    It range_end){
    for (auto it = range_begin;
         it != range_end; ++it){
         cout << *it << ',';
         }
    }

int main (){
    vector <string> langs = {
        "Python", "C++", "C", "Java", "C#"
    };

    // PrintRange(rbegin(langs), rend(langs));

    vector<string> c_langs;
    auto it = copy_if(begin(langs), end(langs), 
                back_inserter(c_langs),
            [] (const string& lang){
                return lang[0] == 'C';
            });
    
    // PrintRange(begin(c_langs), end(c_langs));

    set<int> a = {1, 3, 8};
    set<int> b = {3, 7, 8};
    set<int> res;
    set_intersection(begin(a), end(a), begin(b), end(b),
                inserter(res, end(res)));
    
    PrintRange(begin(res), end(res));


    // auto it = min_element(begin(langs), end(langs));
    // cout << *it << endl;

    // auto p = minmax_element(begin(langs), end(langs));
    // cout << *p.first << ' ' << *p.second << endl;
    // // мы хотим удалить все элементы начинающие с 'C'
    // auto it = remove_if(begin(langs), end(langs),
    //         [] (const string& lang){
    //         return lang[0] == 'C';
    //         });
    // // remove_if вовзаращает новый конец вектора, при этом 
    // // перемещая все другие элементы в начало вектора
    // // мы удаляем все элементы начиная с нового конца it до end
    // langs.erase(it, end(langs));
    // // как мы видим, все элементы начинающие с 'C' были удалены
    // PrintRange(begin(langs), end(langs));

    // auto it = find(begin(langs), end(langs), "C++");
    // langs.erase(it, end(langs));
    // langs.insert(begin(langs), "C++");
    // PrintRange(begin(langs), end(langs));
    return 0;
}