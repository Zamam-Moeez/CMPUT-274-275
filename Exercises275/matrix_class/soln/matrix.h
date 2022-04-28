#ifndef __MATRIX_H_
#define __MATRIX_H_
 

#include <cstddef>
#include <iostream>
#include <array>




using namespace std;

// A dynamic array that can be resized when desired.
class Matrix {

  

public:

/*
Parametrized constructor that takes num_rows as rows, num_columns as colums
and init as initial float value of all entries of Matrix object created

Arguements:

size_t num_rows
size_t num_columns
float init

Returns:

None

*/
  Matrix(size_t num_rows, size_t num_columns, float init);

/*
Parametrixed constructor that takes num_rows ad rows, num_coums as columns
and float pointer array arr_ptr as consecutive entries of the Matrix object created

ArguementsL

size_t num_rows
size_t num_columns
float* arr_ptr

Returns:

None

*/
  Matrix(size_t num_rows, size_t num_columns, float * arr_ptr);

/*
Copy constructor that does deep copy on existing Matrix object m

Arguememnts:

Matrix& m

Returns:

None

*/
  Matrix(const Matrix& m); 

/*
Destructor deallocates all memory for Matrix object once out of scope

Arguements:

None

Returns:

None

*/
  ~Matrix();

/*
Overloaded addition operator. Does matrix addtion between Matrix object and m and returns
the new Matrix object

Argumements:

Matrix& m

Returns:

Matrix newmat

*/
  Matrix operator+(const Matrix& m); //adds

/*
Overloaded subtraction operator. Does matrix subtraction between Matrix object and m and returns
the new Matrix object

Argumements:

Matrix& m

Returns:

Matrix newmat

*/
  Matrix operator-(const Matrix& m); //subtract

/*
Overloaded unary negation operator. Returns a new Matrix object that is the negation of current object

Argumements:

None

Returns:

Matrix newmat

*/
  Matrix operator- (); //unary

/*
Overloaded multiplication operator. Does matrix multiplication between Matrix object and m. Returns
the result as a new Matrix object

Argumements:

Matrix& m

Returns:

Matrix newmat

*/
  Matrix operator*(const Matrix& m);

/*
Does matrix transpose and returns new Matrix object as transposed version of current Matrix object

Arguements:

None

Returns:

Matrix newmat

*/
  Matrix transpose();

/*
Bracker operator gives access to Matrix elements at index

Arguements:

size_t index

Returns:

float* matrix[index]

*/  
  float * operator[](size_t index);

/*
Bracket operator gives access to const Matrix elements at index

Argements:

size_t index

Returns:

float* matrix[index]
*/
  const float * operator[](size_t index) const;

private:
  float **matrix; //2D array
  size_t rows; // number of rows of matrix object
  size_t cols; // number of columns of matrix
  /*
extraction operator reads num rows × num columns space separated elements
from the input stream into Matrix object m

Arguements:

istream& in
Matrix& m

Returns:

istream& in

*/
  friend istream& operator >> (istream &in, Matrix& m);

/*
insertion operator prints matrix by row, space seperated to console

Arguements:

ostream& out
Matrix& m

Returns:

ostream& out

*/
  friend ostream& operator << (ostream &out, const Matrix& m );
};

#endif