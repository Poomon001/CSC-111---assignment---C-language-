/* station extremes.c
   CSC 111 - Fall 2019 - Assignment 6
   Purpose to find extreme max and extreme min of temperatures
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

    /*task3*/
    double arrayData3[1000][12] = {0};//extra [12] = eligibility
    int arrayCheck3[1000] = {0};
    double maxTemp = 0;
    double minTemp = 0;

    //import file.txt
    FILE* input_file = fopen("input_data.txt", "r");
    FILE* output_file3 = fopen("station_extremes.txt", "w");

    //exit if import doesn't work
    if (input_file == NULL){
        printf("Unable to open the file for reading\n");
        return 1; //Exit the program (since we can't do anything else without a file)
    }
    if (output_file3 == NULL){
        printf("Unable to open the file for reading\n");
        return 1; //Exit the program (since we can't do anything else without a file)
    }

    //loop to get data from input_file
    while(fscanf(input_file, "%d %d %d %d %d %f", &month, &day, &hour, &min, &station_number, &temperature) == 6){
        /***************************************************task3********************************************************************/
        if(day != 0) {
            if(arrayCheck3[station_number] == 0) {
                arrayCheck3[station_number] = 1;
                arrayData3[station_number][0] = station_number;
                arrayData3[station_number][1] = temperature;
                arrayData3[station_number][2] = month;//store month of extreme min temp
                arrayData3[station_number][3] = day;//store date of extreme min temp
                arrayData3[station_number][4] = hour;//store hour of extreme min temp
                arrayData3[station_number][5] = min;//store minute of extreme min temp
                arrayData3[station_number][6] = temperature;
                arrayData3[station_number][7] = month;//store month of extreme max temp
                arrayData3[station_number][8] = day;//store date of extreme max temp
                arrayData3[station_number][9] = hour;//store hour of extreme max temp
                arrayData3[station_number][10] = min;//store minute of extreme max temp
                arrayData3[station_number][11] = 1;//make it eligible = 1
            }
            if(arrayData3[station_number][11] == 1) {
                if (temperature < arrayData3[station_number][1]) {
                    arrayData3[station_number][0] = station_number;//store station number
                    arrayData3[station_number][1] = temperature;//store extreme min temp
                    arrayData3[station_number][2] = month;//store month of extreme min temp
                    arrayData3[station_number][3] = day;//store date of extreme min temp
                    arrayData3[station_number][4] = hour;//store hour of extreme min temp
                    arrayData3[station_number][5] = min;//store minute of extreme min temp
                }//if
                if (temperature > arrayData3[station_number][6]) {
                    arrayData3[station_number][6] = temperature;//store extreme max temp
                    arrayData3[station_number][7] = month;//store month of extreme max temp
                    arrayData3[station_number][8] = day;//store date of extreme max temp
                    arrayData3[station_number][9] = hour;//store hour of extreme max temp
                    arrayData3[station_number][10] = min;//store minute of extreme max temp
                }
            }//if
        }//if
    }//while

   for(int station_number = 0; station_number < 1000; station_number++){
       if(arrayCheck3[station_number] != 0) {
           fprintf(output_file3, "Station %d: Minimum = %.2f degrees (%02d/%02d %02d:%02d), Maximum = %.2f degrees (%02d/%02d %02d:%02d)\n",
                  (int)arrayData3[station_number][0], arrayData3[station_number][1], (int)arrayData3[station_number][2],
                  (int)arrayData3[station_number][3], (int)arrayData3[station_number][4], (int)arrayData3[station_number][5],
                  arrayData3[station_number][6], (int)arrayData3[station_number][7], (int)arrayData3[station_number][8],
                  (int)arrayData3[station_number][9], (int)arrayData3[station_number][10]);
       }//if
    }//for
    fclose(output_file3);
    fclose(input_file);
    return 0;
}