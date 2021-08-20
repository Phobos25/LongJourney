#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>

using namespace std;

struct User{
    int id;
    int count;
    User(int i, int c){
        id = i;
        count = c;
    }
};

class Hotel{
public:
    Hotel(){}
    
    void BookRoom(int64_t time, string hotel_name, uint64_t id, int room_count){        
        clients_[hotel_name][time][id] += room_count;
        curr_time = time;
        DelAllKeepLastDay();
    }

    uint64_t ShowClients(string hotel_name){
        return clients_[hotel_name][curr_time].size();
    }

    int ShowRooms(string hotel_name){
        int result = 0;
        for (const auto& [id, room]: clients_[hotel_name][curr_time]){
            result += room;
        }
        return result;
    }
    
private:
    static const int ONE_DAY_IN_SECONDS = 86'400;
    map<string, map<int64_t, map<uint64_t, int>>> clients_;
    int64_t curr_time;

    void DelAllKeepLastDay(string hotel_name){
        for (auto& m: clients_.at(hotel_name)){
            if (curr_time - ONE_DAY_IN_SECONDS >= m.first){
                
            }
        }
    }
};

int main() {
    
    return 0;
}