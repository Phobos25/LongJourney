#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>

using namespace std;

struct Book{
    int64_t time;
    int client;
    int rooms;
};

class Hotel{
public:    
    void ReserveRoom(const Book& booking){
        bookings.push(booking);        
        room_count += booking.rooms;
        if (client_room.count(booking.client) == 0){
          client_room[booking.client] = booking.rooms;
        } else {
          client_room[booking.client] += booking.rooms;
        }
    }

    int GetRoomNumbers(const int64_t& curr_time) {      
        RemoveOldBookings(curr_time);
        return room_count;
    }

    int GetClientsNumbers(const int64_t& curr_time){
        RemoveOldBookings(curr_time);                   
        return client_room.size();    
    }

private:
    const int ONE_DAY_IN_SECONDS = 86'400;
    queue<Book> bookings;
    map<int, int> client_room;    
    int room_count = 0;
    void RemoveOldBookings(const int64_t& curr_time){
        while (!bookings.empty() && bookings.front().time <= curr_time - ONE_DAY_IN_SECONDS)
        {
            room_count -= bookings.front().rooms;
            client_room[bookings.front().client] -= bookings.front().rooms;
            auto temp =  client_room[bookings.front().client];
            if (client_room[bookings.front().client] <= 0){
                client_room.erase(bookings.front().client);
            }
            bookings.pop();
        }
    }    
};

class HotelManager{
public:
    void ReserveRoom(const string& hotel_name, const int64_t& time, int id, int rooms) {
       Book book;       
       book.time = time;
       book.client = id;
       book.rooms = rooms;              
       hotels[hotel_name].ReserveRoom(book);    
       curr_time = time;
    }

    int GetClientNumbers(const string& hotel_name){
        return hotels[hotel_name].GetClientsNumbers(curr_time);
    }
    
    int GetRoomNumbers(const string& hotel_name){
        return hotels[hotel_name].GetRoomNumbers(curr_time);
    }

private:
    int64_t curr_time;
    map<string, Hotel> hotels;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    HotelManager manager;
    int query_count;
    cin >> query_count;   
    for (int i=0; i<query_count; ++i){
        string query;
        cin >> query;
        if (query == "BOOK") {
            int64_t time;
            string hotel_name;
            int client_id, room_count;
            cin >> time >> hotel_name >> client_id >> room_count;
            manager.ReserveRoom(hotel_name, time, client_id, room_count);
        } else if (query == "CLIENTS") {
            string hotel_name;
            cin >> hotel_name;
            cout << manager.GetClientNumbers(hotel_name) << '\n';
        } else if (query == "ROOMS") {
            string hotel_name;
            cin >> hotel_name;
            cout << manager.GetRoomNumbers(hotel_name) << '\n';                            
        }
    }
    return 0;
//    BOOK 10 Hilton 1 2
//    CLIENTS Hilton
//    ROOMS Hilton
}
