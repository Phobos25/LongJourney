#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <cmath>
#include <iomanip>

using namespace std;

class Figure{
public:
  virtual string Name() = 0;
  virtual double Perimeter() = 0;
  virtual double Area() = 0;
};

class Triangle: public Figure{
public:
  Triangle(const string& name,
           const unsigned int& a,
           const unsigned int& b,
           const unsigned int& c)
  : name_(name)
  , a_(a), b_(b), c_(c){
  }

  string Name() override{
    return name_;
  }

  double Perimeter() override{
    return a_+b_+c_;
  }

  double Area() override{
    double p = 0.5 * Perimeter();
    double result =p*(p-a_)*(p-b_)*(p-c_);
    return sqrt(result);
  }

private:
  const string name_;
  const unsigned int a_, b_, c_;
};

class Rect: public Figure{
public:
  Rect(const string& name,
       const unsigned int& w,
       const unsigned int& h)
  : name_(name)
    , width_(w), height_(h){
  }

  string Name() override{
    return name_;
  }

  double Perimeter() override{
    return 2*(width_ + height_);
  }

  double Area() override{
    return width_*height_;
  }

private:
  const string name_;
  const unsigned int width_, height_;
};

class Circle: public Figure{
public:
  Circle(const string& name,
         const unsigned int& r)
  : name_(name)
  , radius_(r){
  }

  string Name() override{
    return name_;
  }

  double Perimeter() override{
    return 2 * 3.14 * radius_;
  }

  double Area() override{
    return 3.14 * radius_ * radius_;
  }

private:
  const string name_;
  const unsigned int radius_;
};

shared_ptr<Figure> CreateFigure(istringstream& is){
  string name;
  is >> name;
  if (name == "TRIANGLE"){
    unsigned int a, b, c;
    is >> a >> b >> c;
    return make_shared<Triangle>(name, a, b, c);
  }else if(name == "RECT"){
    unsigned int w, h;
    is >> w >> h;
    return make_shared<Rect>(name, w, h);
  }else if(name == "CIRCLE"){
    unsigned int r;
    is >> r;
    return make_shared<Circle>(name, r);
  }
  return make_shared<Circle>("Zero", 1);
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}



