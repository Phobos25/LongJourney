#include "database.h"

void Database::Add (const Date& date, const string& event){
//add
}

void Database::Print(const ostream& os) const{
//  print
}

int Database::RemoveIf(shared_ptr<Node>& predicate){
  return 1;
}

string Database::FindIf(shared_ptr<Node>& predicate){
  return "FindIf";
}

string Database::Last(const Date& date){
  return "Last";
}