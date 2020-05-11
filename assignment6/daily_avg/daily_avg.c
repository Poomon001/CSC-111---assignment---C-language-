/*  daily_avg.c
   CSC 111 - Fall 2019 - Assignment 6
   Purpose to find average of temperature
   B. Bird
   (Poomrapee Chuthamsatid/V00942601/17 Nov 2019)
*/
#include <stdio.h>

int main(){
    int month = 0;
    int day = 0;
    int hour = 0;
    int min = 0;
    int station_number = 0;
    float temperature = 0;

    /*task1*/
    double arrayData[13][32][2] = {0};//0 = sum of # of temp, 1 = sum of temp in the day

    //import file.txt
    FILE* input_file = fopen("input_data.txt", "r");
    FILE* output_file = fopen("daily_averages_summary.txt", "w");

    //exit if import doesn't work
    if (input_file == NULL){
        printf("Unable to open the file for reading\n");
        return 1; //Exit the program (since we can't do anything else without a file)
    }
    if (output_file == NULL){
        printf("Unable to open the file for reading\n");
        return 1; //Exit the program (since we can't do anything else without a file)
    }

    //loop to get data from input_file
    while(fscanf(input_file, "%d %d %d %d %d %f", &month, &day, &hour, &min, &station_number, &temperature) == 6){
        /***************************************************task1********************************************************************/
        arrayData[month][day][1] = arrayData[month][day][1] + temperature;//store sum of temp
        arrayData[month][day][0] = arrayData[month][day][0] + 1;//store sum of # of temp in a day
    }//while

    for(int month = 0;  month < 13 ; month++){
        for (int day = 0; day < 32; day++) {
            if(arrayData[month][day][0] != 0) {
                fprintf(output_file, "%d %d %0.2lf\n", month, day, (arrayData[month][day][1] / arrayData[month][day][0]));
            }//if
        }//for
    }//for

    fclose(output_file);
    fclose(input_file);
    return 0;
}