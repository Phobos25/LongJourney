/*
 * matrix.cpp
 *
 *  Created on: Jun 14, 2021
 */

#include <iostream>
#include <string>
#include <exception>
#include <vector>

using namespace std;

class Matrix{
public:
  Matrix(){
    rows = 0;
    cols = 0;    
  };

  Matrix(int num_rows, int num_cols){        
    Reset(num_rows, num_cols);
  };

  void Reset (int num_rows, int num_cols){
    if (num_rows<0 || num_cols < 0){
      throw out_of_range("out of range");
    }
    if (num_rows == 0 || num_cols == 0){
      rows = 0;
      cols = 0;
      vector<vector<int>> new_vector(rows, vector<int> (cols));
      v = new_vector;
    }else {
      rows = num_rows;
      cols = num_cols;
      vector<vector<int>> new_vector(rows, vector<int> (cols));
      v = new_vector;
    }    
    
  }

  int At (int row, int col) const{
    // TODO: change it later
    if (row<0 || col < 0){
      throw out_of_range("out of range");
    }
    if (row > rows-1 || col > cols-1){
      throw out_of_range("out of range");
    }

    return v[row][col];
  }

  int& At (int row, int col) {
    if (row<0 || col < 0){
      throw out_of_range("out of range");
    }
    if (row > rows-1 || col > cols-1){
      throw out_of_range("out of range");
    }
    return v[row][col];
  }

  int GetNumRows() const{
    return rows;
  }

  int GetNumColumns() const {
    return cols;
  }

  bool IsMatrixEmpty() const{
    if (GetNumRows() == 0 || GetNumColumns() == 0){
      return true;
    }else {
      return false;
    }
    
  }

private:
  int rows;
  int cols;
  vector<vector<int>> v;
};

istream& operator>> (istream& stream, Matrix& matrix){
  int rows;
  int cols;
  stream >> rows >> cols;
  matrix = Matrix(rows, cols);
  for (int i=0; i<rows; ++i){
    for (int j=0; j<cols; ++j){
      stream >> matrix.At(i,j);
    }
  }
  return stream;
}

ostream& operator<< (ostream& stream, const Matrix& matrix){
  stream << matrix.GetNumRows() << ' ' << matrix.GetNumColumns() << endl;
  for (int i=0; i<matrix.GetNumRows(); ++i){
    for (int j=0; j<matrix.GetNumColumns(); ++j){
      stream << matrix.At(i,j) << ' ';
    }
    stream << endl;
  }
  return stream;
}

bool operator==(const Matrix& lhs, const Matrix& rhs){  
  if (lhs.IsMatrixEmpty()){
    if (rhs.IsMatrixEmpty()){
      return true;
    }
  }
  
  if (lhs.GetNumColumns() == rhs.GetNumColumns() &&
      lhs.GetNumRows() == rhs.GetNumRows()){
    int rows = lhs.GetNumRows();
    int cols = lhs.GetNumColumns();
    if (rows == 0 && cols == 0){
      return true;
    }
    for (int i=0; i<rows; ++i){
      for (int j=0; j<cols; ++j){
        if (lhs.At(i,j) != rhs.At(i,j)){
          return false;
        }
      }
    }
  }
  else {
    return false;
  }
  return true;
}

Matrix operator+ (const Matrix& lhs, const Matrix& rhs){
  if (lhs.GetNumColumns() != rhs.GetNumColumns() ||
        lhs.GetNumRows() != rhs.GetNumRows()){
    throw invalid_argument("invalid argument");
  }else {
    int rows = lhs.GetNumRows();
    int cols = lhs.GetNumColumns();
    Matrix result_matrix(rows, cols);
    for (int i=0; i<rows; ++i){
      for (int j=0; j<cols; ++j){
        result_matrix.At(i,j) = lhs.At(i, j) + rhs.At(i,j);
      }
    }
    return result_matrix;
  }
}

int main(){
  Matrix one(2,2);
  Matrix two;
  cout << one << endl;
  //one.At(2,2) = 0;
  return 0;
}


