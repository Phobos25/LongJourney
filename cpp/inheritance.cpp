#include <iostream>
using namespace std;

// допустим у нас есть какой-то волшебный мир, в котором водятся
// кошки и собаки, которые едят фрукты
// у фруктов есть определенные данные, типа здоровья, которые они восполняют
// у нас должны быть классы кошек и собак, у которых должен быть метод покушать

struct Fruit{
    int health = 0;
    string type = "fruit";
};

struct Apple : public Fruit{
    Apple() {
        health = 10;
        type = "apple";
    }    
};

struct Orange : public Fruit{
    Orange(){
        health = 5;
        type = "orange";
    }
};

struct Pineapple : public Fruit{
    Pineapple(){
        health = 15;
        type = "pineapple";
    }
};

class Animal {
public:
    string type = "animal";
    void Eat(const Fruit& f){
        cout << type <<" eats "<< f.type << ". " << f.health << " hp. " << endl;
    }
};

class Cat : public Animal{
public:
    Cat() {
        type = "cat";
    }

    void Meow() const {
        cout << "meow! " << endl;
    }   
};

class Dog : public Animal{
public:    
    Dog(){
        type = "dog";
    }
};

void DoMeal(Animal& a, Fruit& f){
    a.Eat(f);
}

int main() {
    Cat c;
    c.Meow();
    Apple a;
    Orange o;
    Pineapple p;    
    Dog d;
    DoMeal(d, p);
    return 0;
}