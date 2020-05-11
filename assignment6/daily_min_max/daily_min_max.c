/*   daily_min_max.c
   CSC 111 - Fall 2019 - Assignment 6
   Purpose to find max and min of temperatures
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

    /*task2*/
    double arrayData2[13][32][3] = {0};//0 = min, 1 = max, 2 = eligibility
    int arrayCheck2[13][32] = {0};

    //import file.txt
    FILE* input_file = fopen("input_data.txt", "r");
    FILE* output_file2 = fopen("daily_minimum_maximum_summary.txt", "w");

    //exit if import doesn't work
    if (input_file == NULL){
        printf("Unable to open the file for reading\n");
        return 1; //Exit the program (since we can't do anything else without a file)
    }
    if (output_file2 == NULL){
        printf("Unable to open the file for reading\n");
        return 1; //Exit the program (since we can't do anything else without a file)
    }


    //loop to get data from input_file
    while(fscanf(input_file, "%d %d %d %d %d %f", &month, &day, &hour, &min, &station_number, &temperature) == 6){
        /***************************************************task2********************************************************************/
        if(day != 0) {
            if(arrayCheck2[month][day] == 0) {
                arrayCheck2[month][day] = 1;
                arrayData2[month][day][1] = temperature;
                arrayData2[month][day][0] = temperature;
                arrayData2[month][day][2] = 1;//make it eligible when [2] = 1
            }

            if (temperature >= arrayData2[month][day][1]) {
                arrayData2[month][day][1] = temperature;//store maxTemp
            }//if

            if (temperature <= arrayData2[month][day][0]) {
                arrayData2[month][day][0] = temperature;//store minTemp
            }//if
        }//if
    }//while

    for(int month = 0;  month < 13 ; month++){
        for (int day = 0; day < 32; day++) {
            //if it is eligible (there is value inside)
            if(arrayData2[month][day][2] != 0) {
                fprintf(output_file2, "%d %d %0.2lf %0.2lf\n", month, day, arrayData2[month][day][0],
                        arrayData2[month][day][1]);
            }//if
        }//for
    }//for

    fclose(output_file2);
    fclose(input_file);
    return 0;
}