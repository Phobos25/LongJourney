#include <iostream>
#include <vector>
#include <map>
#include <string>
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
    Hotel(long long t, string hotel_name, int id, int count)        
        : name(hotel_name)        
        {            
        }

    void BookRoom(long long t, int id, int count){
        users[t] = User(id, count);
        CheckTime(t);
    }

    int ShowClients(){
        return users.size();
    }

    int ShowRooms(){
        int result = 0;
        for (auto& [key,value]: users){
            result += value.count;
        }
        return result;
    }
    string GetHotelName() const{
        return name;
    }
private:
    static const int ONE_DAY = 86400;
    static const int ROOM_COUNT = 1000;
    map<long long, User> users;
    
    const string name;    
    void CheckTime(const long long& t){
        long long old_time;
        for (auto& it : users){
            old_time = it.first;
            break;
        }
        if ((t - old_time)> ONE_DAY){
            auto it = users.begin();
            users.erase(it);
        }
    }
};

int main() {
    int qu;
    string com;
    string name;
    long long time;
    int id;
    int rooms;
    for (int i=0; i<qu; ++i){
        cin >> com;
        if (com == "BOOK"){
            cin >> time >> name >> id >> rooms;
            
        } else if (com =="ROOMS"){

        } else if (com == "CLIENTS"){

        }
    }
    return 0;
}