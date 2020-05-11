/* day.c
   CSC 111 - Fall 2019 - Assignment 3

   B. Bird - 08/14/2019
   (Poomrapee/V00942601/28 Sep 2019)
*/

#include <stdio.h>
#include <stdlib.h>

//print a name of the day, date, month, year
void name (int day, int month, int year, int number){
    switch(number){
        case 1:
            printf("%d/%d/%d: Monday", year, month, day);
            break;
        case 2:
            printf("%d/%d/%d: Tuesday", year, month, day);
            break;
        case 3:
            printf("%d/%d/%d: Wednesday", year, month, day);
            break;
        case 4:
            printf("%d/%d/%d: Thursday", year, month, day);
            break;
        case 5:
            printf("%d/%d/%d: Friday", year, month, day);
            break;
        case 6:
            printf("%d/%d/%d: Saturday", year, month, day);
            break;
        case 0:
            printf("%d/%d/%d: Sunday", year, month, day);
            break;
    }//switch
}//day
//subtracy on from leap year on Jan and Feb
int itIsLeap (int fifthStep, int forthStep, int month){
    if ((fifthStep == 1) && (month == 1 || month == 2)){
        forthStep--;
    }//if
    return forthStep;
}//isLeap
//determine whather leap year or not.
int isLeap (int year){
    int mark = 0;
    //enter if statement if the year is a leap year
    if(year%4 != 0){;
        mark = 0;
    } else {
        if (year % 100 != 0) {

            mark = 1;
        } else {
            if (year % 400 != 0) {

                mark = 0;
            } else {
                mark = 1;
            }//if
        }//if
    }//if
    return mark;
}//isLeap

//calculate and reyurn data of the forth step
int F4(int thirdStep, int month){
    int forthStep = 0;
    switch (month){
        case 2:
        case 3:
        case 11:
            forthStep = thirdStep + 4;
            break;
        case 4:
        case 7:
            forthStep = thirdStep + 0;
            break;
        case 1:
        case 10:
            forthStep = thirdStep + 1;
            break;
        case 5:
            forthStep = thirdStep + 2;
            break;
        case 8:
            forthStep = thirdStep + 3;
            break;
        case 6:
            forthStep = thirdStep + 5;
            break;
        case 9:
        case 12:
            forthStep = thirdStep + 6;
            break;
    }//switch
    return forthStep;
}//forthStep

//exit if any error is detected
int errorCheck(int year, int month, int day, int isLeap){
    if (year < 1 || year > 10000){
        printf("Error: Invalid year");
        exit(0);
    }//if
    if(month < 1 || month > 12){
        printf("Error: Invalid month");
        exit(0);
    }//if
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if(day > 31 || day < 1) {
            printf("Error: Invalid day");
            exit(0);
        }//if
    }//if
    if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day > 30 || day < 1) {
            printf("Error: Invalid day");
            exit(0);
        }//if
    }//if
    if(month == 2 &&  isLeap == 1){
        if(day > 29 || day < 1) {
            printf("Error: Invalid day");
            exit(0);
        }//if
    }//if
    if(month == 2 &&  isLeap == 0){
        if(day > 28 || day < 1) {
            printf("Error: Invalid day");
            exit(0);
        }//if
    }//if
    return 0;
}//error check

int main(int argc, char** argv){
    /* INPUT DATA */
    /* You may modify the values of each variable below, but DO NOT
       rename the variables, change their type or move the declarations. */

    int year = 2019;
    int month = 9;
    int day = 23;

    /* END OF INPUT DATA */
    /* Implement your solution below this line */
    /* (you may also add new functions above main() if needed) */
    int fifthStep = 0;

    fifthStep = isLeap(year);
    errorCheck (year, month, day, fifthStep);//check error

    int firstStep = 0;
    int secondStep = 0;
    int thirdStep = 0;
    int forthStep = 0;
    int fifthStep2 = 0;
    int sixthStep = 0;
    int seventhStep = 0;
    int eighthStep = 0;
    int ninthStep = 0;

    firstStep = year%100;
    secondStep = firstStep/4;
    thirdStep = secondStep + day;
    forthStep = F4(thirdStep, month);
    fifthStep2 = itIsLeap(fifthStep, forthStep, month);
    sixthStep = fifthStep2 - (((year/100)%4)*2);
    seventhStep = year%100 + sixthStep;
    eighthStep = seventhStep + 12;
    ninthStep = eighthStep%7;
    name(day, month, year, ninthStep);
    return 0;
}


