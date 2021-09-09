#include <string>
#include "test_runner.h"

#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Editor {
 public:
  // Реализуйте конструктор по умолчанию и объявленные методы
  Editor();
  void Left();
  void Right();
  void Insert(char token);
  void Cut(size_t tokens = 1);
  void Copy(size_t tokens = 1);
  void Paste();
  string GetText() const;
private:    
  vector<char> buffer_;
  list<char> text_;
  list<char>::iterator cursor_;
};

Editor::Editor(){
  cursor_ = text_.end(); //т.к. list пустой, мы устанавливаем курсор на конец
}

void Editor::Left() {
  if (cursor_ != text_.begin()){
    --cursor_;
  }
}

void Editor::Right(){
  if (cursor_ != text_.end()){
    ++cursor_;
  }
}

void Editor::Insert(char token){
  text_.insert(cursor_, token);
}

void Editor:: Cut(size_t tokens){
  buffer_.clear();  
  buffer_.reserve(tokens);
  for (size_t i = 0; i < tokens; ++i){        
    if (cursor_ == text_.end()){
      break;
    } else {
      buffer_.push_back(*cursor_);    
      text_.erase(cursor_++);
    }    
  }   

}

void Editor:: Copy(size_t tokens){
  buffer_.clear();  
  buffer_.reserve(tokens);
  for (size_t i = 0; i < tokens; ++i){    
    buffer_.push_back(*cursor_);
    if (cursor_ == text_.end()){
      break;
    } else {
      Right();
    }    
  }
}

void Editor::Paste(){
  // вставляем скопированные объекты
  for (auto it:buffer_){
    Insert(it);
  }  
}

string Editor::GetText() const{  
  return {text_.begin(), text_.end()};
}


void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}

void TestEditing() {
  {
    Editor editor;

    const size_t text_len = 12;
    const size_t first_part_len = 7;
    TypeText(editor, "hello, world");
    for(size_t i = 0; i < text_len; ++i) {
      editor.Left();
    }
    editor.Cut(first_part_len);
    for(size_t i = 0; i < text_len - first_part_len; ++i) {
      editor.Right();
    }
    TypeText(editor, ", ");
    editor.Paste();
    editor.Left();
    editor.Left();
    editor.Cut(3);
    
    ASSERT_EQUAL(editor.GetText(), "world, hello");
  }
  {
    Editor editor;
    
    TypeText(editor, "misprnit");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Cut(1);
    editor.Right();
    editor.Paste();
    
    ASSERT_EQUAL(editor.GetText(), "misprint");
  }
}

void TestReverse() {
  Editor editor;

  const string text = "esreveR";
  for(char c : text) {
    editor.Insert(c);
    editor.Left();
  }
  
  ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
  Editor editor;
  ASSERT_EQUAL(editor.GetText(), "");
  
  editor.Left();
  editor.Left();
  editor.Right();
  editor.Right();
  editor.Copy(0);
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
  Editor editor;

  editor.Paste();
  TypeText(editor, "example");
  editor.Left();
  editor.Left();
  editor.Paste();
  editor.Right();
  editor.Paste();
  editor.Copy(0);
  editor.Paste();
  editor.Left();
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);
  return 0;
}