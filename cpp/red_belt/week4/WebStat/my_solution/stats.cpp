#include "stats.h"

Stats::Stats(){
    method_stats = {{"GET", 0}, {"POST", 0}, 
                    {"PUT", 0}, {"DELETE", 0}, 
                    {"UNKNOWN", 0}};
    uri_stats = {{"/", 0}, {"/order", 0}, 
                 {"/product", 0}, {"/basket", 0}, 
                 {"/help", 0}, {"unknown", 0}};
}

void Stats::AddMethod(string_view method){
    if (method_stats.find(method) != method_stats.end()){
        ++method_stats[method];
    } else {
        ++method_stats["UNKNOWN"];
    }
}

void Stats::AddUri(string_view uri){
    if (uri_stats.find(uri) != uri_stats.end()){
        ++uri_stats[uri];
    } else {
        ++uri_stats["unknown"];
    }
}

const map<string_view, int>& Stats::GetMethodStats() const {
    return method_stats;    
}

const map<string_view, int>& Stats::GetUriStats() const {
    return uri_stats;       
}

vector<string_view> Split(const string_view& str) {  
  
  vector<string_view> result;
  size_t pos = 0;  //string view не дружит с итераторами
  const size_t pos_end = str.npos; //работает только с подряд идущими строками

  while (true){
    size_t space = str.find(' ', pos); // ищем пустую строку с позиции pos
    
    result.push_back(
      space == pos_end
      ? str.substr(pos)
      : str.substr(pos, space-pos)
    );

    if (space == pos_end){
      break;
    } else {
      pos = space + 1;
    }
  }
  return result;
}

HttpRequest ParseRequest(string_view line){
    line.remove_prefix(min(line.find_first_not_of(" "), line.size()));
    HttpRequest request;
    const auto words = Split(line);
    if (!words.empty()){
        request.method = words[0];
        request.uri = words[1];
        request.protocol = words[2];
    }
    return request;    
}
