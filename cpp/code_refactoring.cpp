#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{
public:
    virtual void Walk(const string& destination) const = 0;

    Person(const string& name, const string occupation){
        name_ = name;
        occupation_ = occupation;
    }
    string GetOccupation() const{
        return occupation_;
    }
    string GetName() const{
        return name_;
    }
private:
    string occupation_;
    string name_;
};

class Student: public Person {
public:

    Student(const string& name, const string& favouriteSong)
    : Person(name,"Student") {        
        FavouriteSong = favouriteSong;        
    }

    void Learn() {
        cout << "Student: " << GetName() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Student: " << GetName() << " walks to: " << destination << endl;
        cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() {
        cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

public:
    string FavouriteSong;
};


class Teacher: public Person {
public:

    Teacher(const string& name, const string& subject)
    : Person(name, "Teacher") {        
        Subject = subject;        
    }

    void Teach() {
        cout << "Teacher: " << GetName() << " teaches: " << Subject << endl;
    }

    void Walk(const string& destination) const override{
        cout << "Teacher: " << GetName() << " walks to: " << destination << endl;
    }

public:
    string Subject;
};


class Policeman: public Person {
public:
    Policeman(const string& name)
    : Person(name, "Policeman"){       
    }

    void Check(Person& person){
        cout << "Policeman: " << GetName() << " checks "
             << person.GetOccupation() << ". " << person.GetOccupation() 
             << "'s name is: " << person.GetName() << endl;
    }

    void Walk(const string& destination) const override{
        cout << "Policeman: " << GetName() << " walks to: " << destination << endl;
    }

};

void VisitPlaces(const Person& person, const vector<string>& places){
    for(auto p: places){
        person.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");
    
    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
