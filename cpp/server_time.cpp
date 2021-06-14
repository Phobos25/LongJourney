#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <numeric>
#include <iomanip>

using namespace std;

string AskTimeServer(){
   string text = "";
   return text;
 }

class TimeServer {
public:
  string GetCurrentTime(){
    try {
      string temp = AskTimeServer();
      Date date = ParseDate(temp);
      stringstream convert;
      convert << setw(2) << setfill('0') << date.hour   << ':'
              << setw(2) << setfill('0') << date.minute << ':'
              << setw(2) << setfill('0') << date.second;
      last_fetched_time = convert.str();
    }catch(system_error& e){
      return last_fetched_time;
    }
    catch (exception& ex){
      throw runtime_error(ex.what());
    }
    return last_fetched_time;
  };

private:
  string last_fetched_time = "00:00:00";
  struct Date{
    int hour;
    int minute;
    int second;
    };

  void CheckNextAndSkip(stringstream& stream){
    if (stream.peek() != ':'){
      throw system_error(error_code());
    }
    stream.ignore(1);
  }

  Date ParseDate(string& s){
    Date date;
    stringstream stream(s);
    stream >> date.hour;
    CheckNextAndSkip(stream);
    stream >> date.minute;
    CheckNextAndSkip(stream);
    stream >> date.second;
    return date;
  }
};

int main(){
  // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
  TimeServer ts;
  try {
    cout << ts.GetCurrentTime() << endl;
  } catch (exception& e) {
    cout << "Exception got: " << e.what() << endl;
  }
  return 0;
}
