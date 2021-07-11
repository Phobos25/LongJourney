#include "database.h"

using namespace std;

class Database{
public:
  void Add(const std::string& date, const std::string& event);
  void Print(std::ostream& os);
  int RemoveIf(std::shared_ptr<Node>&  predicate );
  std::string FindIf(std::shared_ptr<Node>&  predicate );
};

void Database::Add (const string& date, const string& event){
//add
}

void Database::Print(ostream& os){
//  print
}

int Database::RemoveIf(shared_ptr<Node> & predicate){

}

