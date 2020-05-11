/* pi.c
   CSC 111 - Fall 2019 - Assignment 2

   B. Bird - 08/13/2019
   (Put Poomrapee Chuthamsatid/V00942601/20 Sep 2019)
*/

#include <stdio.h>

int main(){
    /* INPUT DATA */
    /* You may modify the values of each variable below, but DO NOT
       rename the variables, change their type or move the declarations. */

    int n = 17; //Number of terms in summation

    /* END OF INPUT DATA */
    /* Implement your solution below this line */
    int power1 = 0;//store power of (2*i) - 1)
    int power2 = 0;//store power of i + 1
    int count = 1;//count loop running for n times

    double sum2 = 0;//value of the first term
    double sum1 = 0;//value of the second term
    double sum4 = 0;//store value of fisrt term multiplies by second term
    double sum5 = 0;//store total value

    while (count < n+1) {
        double product1 = 1;//store product of 1/3^n
        double product3 = 1;//store product of 1/2^n
        double product2 = 1;//store product of -1^n
        double product4 = 1;//store result of second term

         power1 = ((2*count)-1);//power of first term

         //find value of the first term
         for (int j = 1; j <= power1; j++) {
             product3 = product3 * 1 / 2;
             product1 = product1 * 1 / 3;
         }//for

         power2 = count + 1;//power of second term

         //find value of the second term
         for (int k = 1; k <= power2; k++) {
             product2 = product2 * -1;//power of -1 ^ (i+1)
             product4 = (4 * product2) / ((2 * count) - 1);
         }//for

         //calculation
         sum1 = product4;
         sum2 = product1 + product3;
         sum4 = sum1 * sum2;
         sum5 = sum5 + sum4;
         count++;
    }//while
    printf("With %d terms: pi = %.15f",n, sum5);

    return 0;
}