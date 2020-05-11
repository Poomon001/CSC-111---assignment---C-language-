/* matrix_and_vector.c
   CSC 111 - Fall 2019 - Assignment 5

   (Poomrapee Chuthamsatid/V00942601/3 Nov 2019)
   objective: The program that calculates vector and matrix

   B. Bird - 10/13/2019
*/

#include <math.h> //For the sqrt() function

#define MATRIX_MAX  100

//Define new types for Vectors and Matrices
//Notice that the MATRIX_MAX constant is used to limit the maximum
//size of a matrix or vector.
typedef double Vector[MATRIX_MAX];
typedef double Matrix[MATRIX_MAX][MATRIX_MAX];

//In all of the functions below, all arguments of type Matrix
//or Vector are passed by reference (since they are array types).


/****************************** VECTOR FUNCTIONS ******************************/

/* set_vector(Vout, vector_size, value)
   Given a scalar value, a reference to a vector and a size,
   set the elements of Vout at indices 0, 1, 2, ..., vector_size - 1
   to the provided value. Do not set any other indices of the vector.
*/
void set_vector(Vector Vout, int vector_size, double value){
    for(int i = 0; i <=  vector_size - 1; i++) {
        Vout[i] = value;
    }//for
}//set_vector


/* add_scalar_to_vector(V, Vout, vector_size, value)
   Given an input vector V, an output vector V, a size and a value,
   set every element of Vout to be the corresponding element
   of V plus the provided value. Only use indices 0 - (vector_size-1).
   Do not modify any elements of the input vector V.
*/

void add_scalar_to_vector(Vector V, Vector Vout, int vector_size, double value){
    for(int i = 0; i <=  (vector_size-1); i++) {
        Vout[i] = V[i]+value;
    }//for
}//add_scalar_to_vector

/* mul_vector_by_scalar(V, Vout, vector_size, value)
   Given an input vector V, an output vector V, a size and a value,
   set every element of Vout to be the corresponding element
   of V multiplied by the provided value. Only use indices 0 - (vector_size-1).
   Do not modify any elements of the input vector V.
*/
void mul_vector_by_scalar(Vector V, Vector Vout, int vector_size, double value){
    for(int i = 0; i <=  (vector_size-1); i++) {
        Vout[i] = V[i]*value;
    }//for
}//mul_vector_by_scalar

/* vector_sum(V, vector_size)
   Given a vector V and its size, return the sum of all elements of V.
   Do not modify any elements of the input vector V.
*/
double vector_sum(Vector V, int vector_size){
    double sum = 0;
    for(int i = 0; i <=  (vector_size-1); i++) {
        sum = sum + V[i];
    }//for
    return sum;
}//vector_sum


/* dot_product(V1, V2, vector_size)
   Given two vectors V1 and V2, along with their size (which is assumed
   to be the same for both input vectors), return the dot product of
   V1 and V2.
   Do not modify any elements of the input vectors V1 and V2.
*/
double dot_product(Vector V1, Vector V2, int vector_size){
    double dotProduct = 0;
    for(int i = 0; i <=  (vector_size-1); i++) {
        dotProduct = dotProduct + (V1[i] * V2[i]);
    }//for
    return dotProduct;
}//dot_product

/* norm(V, vector_size)
   Given a vector V and its size, return the norm (length) of V.
   Recall that the length of a vector V is the square root
   of the dot product of V with itself.
   Do not modify any elements of the input vector V.
*/
double norm(Vector V, int vector_size){
    double length = 0;
    for(int i = 0; i <=  (vector_size-1); i++) {
        length = length + V[i]*V[i];
    }//for
    length = sqrt(length);
    return length;
}//norm


/* add_vectors(V1, V2, Vout, vector_size)
   Given two input vectors V1 and V2, an output vector Vout, and a size,
   store the (elementwise) vector sum V1 + V2 into Vout. Do not set
   any indices beyond vector_size-1.
   Do not modify any elements of the input vectors V1 and V2.
*/
void add_vectors(Vector V1, Vector V2, Vector Vout, int vector_size){
    for(int i = 0; i <=  (vector_size-1); i++) {
        Vout[i] = V1[i] + V2[i];
    }//for
}//add_vectors


/* elementwise_multiply_vectors(V1, V2, Vout, vector_size)
   Given two input vectors V1 and V2, an output vector Vout, and a size,
   store the (elementwise) product of V1 and V2 into Vout. To be clear,
   each element of Vout will be set to the product of the corresponding
   elements of V1 and V2. Do not set any indices beyond vector_size-1.
   Do not modify any elements of the input vectors V1 and V2.
*/
void elementwise_multiply_vectors(Vector V1, Vector V2, Vector Vout, int vector_size){
    for(int i = 0; i <=  (vector_size-1); i++) {
        Vout[i] = V1[i] * V2[i];
    }//for
}//elementwise_multiply_vectors



/****************************** MATRIX FUNCTIONS ******************************/


/* identity(M, size)
   Set the elements of the provided matrix M to be an identity matrix
   of the specified size. Do not set any other elements outside the bounds
   of the requested size.
   By definition, the identity matrix is square (so the number of rows and
   the number of columns are equal).
*/
void identity(Matrix M, int size){
    for(int i = 0; i <= size-1; i++){
        for(int j = 0;j <= size-1;j++){
            if(i == j){
                M[i][j] = 1;
            }else {
                M[i][j] = 0;
            }//if
        }//for
    }//for
}//identity

/* matrix_copy(A, B, rows, cols)
   Given an input matrix A (with the provided number of rows and columns)
   and an output matrix B, copy all elements of A into B. Do not set any
   elements of B outside the bounds provided.
   Do not modify any elements of the input matrix A.
*/
void matrix_copy(Matrix A, Matrix B, int rows, int cols){
    for(int i = 0; i <=  rows-1; i++){
        for(int j = 0;j <= cols-1;j++){
            B[i][j] = A[i][j];
        }//for
    }//for
}//matrix_copy


/* transpose(A, T, rows, cols)
   Given an input matrix A (with the provided number of rows and columns)
   and an output matrix T, set T to be the transpose of A. Note that the
   number of rows in T will be the number of columns in A and the number
   of columns in T will be the number of rows in A (by definition of the
   transpose).
   Do not modify any elements of the input matrix A.
*/
void transpose(Matrix A, Matrix T, int rows, int cols){
    for(int i = 0; i <= rows-1; i++){
        for(int j = 0;j <= cols-1;j++){
            T[j][i] = A[i][j];
        }//for
    }//for
}//transpose


/* add_matrices(A, B, C, rows, cols)
   Given two input matrices A and B (both with the number of rows/columns provided),
   set C to be the elementwise sum of A and B. Do not set any elements of C outside
   of the bounds provided.
   Do not modify any elements of the input matrices A and B.
*/
void add_matrices(Matrix A, Matrix B, Matrix C, int rows, int cols){
    for(int i = 0; i <= rows-1; i++){
        for(int j = 0;j <= cols-1;j++){
            C[i][j] = A[i][j] + B[i][j];
        }//for
    }//for
}//add_matrices

/* matrix_vector_multiply(A, V, Vout, rows, cols)
   Given an n x k matrix A and a vector V (which will have k entries), compute
   the product A*V (which will have n entries) and store the product in the provided
   output vector Vout. Do not set any elements of Vout outside of the required
   elements for the computation.
   Do not modify any elements of the input matrices A and B or the input vector V.
*/
void matrix_vector_multiply(Matrix A, Vector V, Vector Vout, int n, int k){
    for(int i = 0; i <= n-1; i++){
        double result = 0;
        for(int j = 0;j <= k-1;j++){
            result = result + (A[i][j] * V[j]);
        }//for
        Vout[i] = result;
    }//for
}//matrix_vector_multiply

/* matrix_multiply(A, B, C, Arows, Acols, Brows, Bcols)
   Given matrices A and B, compute the product C = A*B and store it in the matrix C
   provided.

   The number of rows and columns of each input matrix are provided in parameter
   values. The output matrix C will have the same number of rows as A and the
   same number of columns as B.

   If the number of columns in A is not equal to the number of rows in B,
   the multiplication is impossible. In this case, the function will return 0
   and make NO MODIFICATION to the output matrix C.

   If the multiplication is possible, the matrix C will contain the result
   and the function will return 1.

   Do not modify any elements of the input matrices A and B.

   See https://en.wikipedia.org/wiki/Matrix_multiplication for further details on matrix multiplication.
*/
int matrix_multiply(Matrix A, Matrix B, Matrix C, int Arows, int Acols, int Brows, int Bcols){
    if(Acols == Brows) {
        for (int i = 0; i <= Arows - 1; i++) {
            for (int j = 0; j <= Bcols - 1; j++) {
                C[i][j] = 0;
                for (int k = 0; k <= Acols - 1; k++) {
                    C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
                }//for
            }//for
        }//for
        return 1;
    }else{
        return 0;
    }
}//matrix_multiply
