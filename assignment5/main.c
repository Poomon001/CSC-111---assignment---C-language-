/* vector_tester1.c
   CSC 111 - Fall 2019 - Assignment 5


   B. Bird - 10/13/2019
*/


#include <stdio.h>
#include <math.h>
#include "matrix_and_vector.h"

//print_vector(V, size)
//Print the contents of the vector V
void print_vector(Vector V, int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%.2f ", V[i]);
    printf("\n");
}

int main(){

    Vector V = {1, 2, 3, 4, 5};
    Vector W = {0, 1, 0, 1, 0};
    Vector X = {10, 20, 30, 3.5, 3.6, 3.1415, 1.7};
    Vector Y = {111, 116, 225, 230, 265, 370};
    Vector Z = {0, 0, 0, 999, 999};

    Vector Q;

    printf("Testing set_vector:\n");
    set_vector(Z, 3, 6);
    printf("Result (1): ");
    print_vector(Z, 5);
    set_vector(Z, 5, 1.87);
    printf("Result (2): ");
    print_vector(Z, 5);
    printf("\n");



    printf("Testing add_scalar_to_vector:\n");
    //Set the first 100 elements of Q to -999
    set_vector(Q, 100, -999);
    add_scalar_to_vector(V, Q, 5, 1.5);
    printf("Result (1): ");
    print_vector(Q, 5);

    //Now call add_scalar_to_vector but deliberately decrease
    //the provided size (so the last two elements should remain
    //as -999).
    set_vector(Q, 100, -999);
    add_scalar_to_vector(V, Q, 3, 1.5);
    printf("Result (2): ");
    print_vector(Q, 5);
    printf("\n");




    printf("Testing mul_vector_by_scalar:\n");
    set_vector(Q, 100, -999);
    mul_vector_by_scalar(V, Q, 5, 2);
    printf("Result (1): ");
    print_vector(Q, 5);

    set_vector(Q, 100, -999);
    mul_vector_by_scalar(V, Q, 3, 0);
    printf("Result (2): ");
    print_vector(Q, 5);
    printf("\n");




    printf("Testing vector_sum:\n");
    printf("Result (first three elements of V): %.2f\n", vector_sum(V, 3));
    printf("Result (first five elements of V): %.2f\n", vector_sum(V, 5));
    printf("\n");


    printf("Testing dot_product:\n");
    printf("Result (V dot W, size 3): %.2f\n", dot_product(V, W, 3));
    printf("Result (V dot W, size 5): %.2f\n", dot_product(V, W, 5));
    printf("Result (W dot X, size 5): %.2f\n", dot_product(W, X, 5));
    printf("\n");


    printf("Testing norm:\n");
    printf("Result (norm of V, 3 elements): %.2f\n", norm(V, 3));
    printf("Result (norm of W, 5 elements): %.2f\n", norm(W, 5));
    printf("Result (norm of X, 7 elements): %.2f\n", norm(X, 7));
    printf("\n");



    printf("Testing add_vectors:\n");
    set_vector(Q, 100, -999);
    add_vectors(V, W, Q, 3);
    printf("Result (V + W, 3 elements): ");
    print_vector(Q, 5);

    set_vector(Q, 100, -999);
    add_vectors(V, W, Q, 5);
    printf("Result (V + W, 5 elements): ");
    print_vector(Q, 5);

    set_vector(Q, 100, -999);
    add_vectors(X, Y, Q, 6);
    printf("Result (X + Y, 6 elements): ");
    print_vector(Q, 6);
    printf("\n");



    printf("Testing elementwise_multiply_vectors:\n");
    set_vector(Q, 100, -999);
    elementwise_multiply_vectors(V, W, Q, 3);
    printf("Result (V * W, 3 elements): ");
    print_vector(Q, 5);

    set_vector(Q, 100, -999);
    elementwise_multiply_vectors(V, W, Q, 5);
    printf("Result (V * W, 5 elements): ");
    print_vector(Q, 5);

    set_vector(Q, 100, -999);
    elementwise_multiply_vectors(X, Y, Q, 6);
    printf("Result (X * Y, 6 elements): ");
    print_vector(Q, 6);
    printf("\n");

    return 0;
}
