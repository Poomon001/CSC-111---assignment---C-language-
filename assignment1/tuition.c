/* tuition.c
   CSC 111 - Fall 2019 - Assignment 1

   B. Bird - 08/13/2019
   (Poomrapee Chuthamsatid/V00942601/13 Sep 2019)
*/

#include <stdio.h>

int main(){
    /* INPUT DATA */
    /* You may modify the values of each variable below, but DO NOT rename the variables or move the declarations. */

    double specialized_engineering_units = 1.5;
    double normal_units = 7.5;

    double cost_per_specialized_engineering_unit = 1793.01;
    double cost_per_normal_unit = 1661.73;

    /* END OF INPUT DATA */
    /* Implement your solution below this line */

    //store the result of Speciallized units x its cost
    double result1 = specialized_engineering_units*cost_per_specialized_engineering_unit;

    //store the result of normal units x its cost
    double result2 = normal_units*cost_per_normal_unit;

    //store total units
    double totalUnit = specialized_engineering_units + normal_units;

    //store total cost
    double totalCost = result1 + result2;


    //print the result statement
    printf("Specialized Engineering units: %.1f, Cost per unit: $%.2f, Total cost: $%.2f \n", specialized_engineering_units, cost_per_specialized_engineering_unit, result1);
    printf("Normal units: %.1f, Cost per unit: $%.2f, Total cost: $%.2f \n", normal_units, cost_per_normal_unit, result2);
    printf("Total units: %.1f, Total tuition: $%.2f \n", totalUnit, totalCost);
    return 0;
}
