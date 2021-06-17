#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct Date{
    int year;
    int month;
    int day;    
};

auto GetRank(const Date& date){
    return tie (date.year, date.month, date.day);
}

bool operator < (const Date& lhs, const Date& rhs){
    return GetRank(lhs) < GetRank(rhs);        
}

int main (){

    cout << (Date{2017, 6, 8} < Date{2017, 1, 26}) << endl;
    return 0;
}