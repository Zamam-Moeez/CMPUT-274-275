 /*---------------------------------------------------
 Name: Zamam Moeez
 ID: 1665264
 CMPUT 275 , Winter 2022
 CCID: zamam

 Exercise 5 Part 2: Matrix
 ---------------------------------------------------*/
#include "matrix.h"

Matrix::Matrix(size_t num_rows, size_t num_columns, float init) {
  matrix = new float * [num_rows];  // declares dynamic array of pointers
  for (int i = 0; i < num_rows; i++) {
    matrix[i] = new float[num_columns];  // each row has 1D float array
  }
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_columns; j++) {
      matrix[i][j] = init;  // assign each matrix element as init value
    }
  }
  rows = num_rows;  // assign rows as num_rows
  cols = num_columns;  // assign cols as num_columns
}

Matrix::Matrix(size_t num_rows, size_t num_columns, float * arr_ptr) {
  rows = num_rows;  // assign rows as num_rows
  cols = num_columns;  // assign cols as num_columns
  matrix = new float * [rows];  // declares dynamic array of float pointers
  for (size_t i = 0; i < rows; ++i) {
    matrix[i] = new float[cols];  // each row has 1D float array
    for (size_t j = 0; j < cols; j++) {
      matrix[i][j] = * arr_ptr;  // assign pt array value to matrix element
      arr_ptr++;  // move on to next pointer array element
    }
  }
}

Matrix::Matrix(const Matrix & m) {
  rows = m.rows;  // dimensions of matrix object are same as those of m
  cols = m.cols;
  matrix = new float * [rows];  // declare dynamic array of pointers
  for (int i = 0; i < rows; i++) {
    matrix[i] = new float[cols];  // each row has a 1D array of float
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = m.matrix[i][j];  // element in m to matrix object
    }
  }
}

Matrix::~Matrix() {
  for (int i = 0; i < rows; ++i) {
    delete[] matrix[i];  // remove each dynamic float array for each row
  }
  delete[] matrix;  // remove 2D array
}

Matrix Matrix::operator + (const Matrix & m) {
  Matrix newmat(m.rows, m.cols, 0.0);  // initialize matrix as zero matrix
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.cols; j++) {
      newmat[i][j] = this -> matrix[i][j] + m.matrix[i][j];  // store sum
    }
  }
  return newmat;  // return new matrix object
}

Matrix Matrix::operator - (const Matrix & m) {
  Matrix newmat(m.rows, m.cols, 0.0);  // initialize matrix as zero matrix
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.cols; j++) {
      newmat[i][j] = this -> matrix[i][j] - m.matrix[i][j];  // store result
    }
  }
  return newmat;  // return new matrix object
}

Matrix Matrix::operator - () {
  Matrix newmat(this -> rows, this -> cols, 0.0);  // initialize new matrix
  for (int i = 0; i < this -> rows; i++) {
    for (int j = 0; j < this -> cols; j++) {
      newmat[i][j] = -(this -> matrix[i][j]);  // assign negation to new object
    }
  }
  return newmat;  // return new matrix object
}

Matrix Matrix::operator * (const Matrix & m) {
  Matrix newmat(rows, m.cols, 0.0);  // initialize matrix as zero matrix
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < m.cols; j++)
      for (int k = 0; k < cols; k++)  // takes dot product of row and column
        newmat[i][j] += this -> matrix[i][k] * m.matrix[k][j];
  return newmat;  // return new matrix object
}

Matrix Matrix::transpose() {
  Matrix newmat(this -> cols, this -> rows, 0.0);  // new matrix swap rows,cols
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      newmat.matrix[j][i] = matrix[i][j];  // values from matrix to newmat
    }
  }
  return newmat;  // return newmat
}

float * Matrix::operator[](size_t index) {
  return matrix[index];  // return float pointer array
}

const float * Matrix::operator[](size_t index) const {
  return matrix[index];  // return float pointer array
}

ostream & operator << (ostream & out,
  const Matrix & m) {
  for (int i = 0; i < m.rows; ++i) {
    for (int j = 0; j < m.cols; ++j) {
      out << m.matrix[i][j];  // prints matrix row by row
      if (j < m.cols - 1) {
        out << " ";  // space after each element except last in row
      }
    }
    if (i < m.rows - 1) {
      out << endl;  // newline if row reaches end
    }
  }
  return out;
}

istream & operator >> (istream & in , Matrix & m) {
  for (int i = 0; i < m.rows; ++i) {
    for (int j = 0; j < m.cols; ++j) {
      in >> m.matrix[i][j];  // reads console input into matrix m
    }
  }
  return in;
}
