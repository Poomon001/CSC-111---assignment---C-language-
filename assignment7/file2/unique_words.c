/*  unique_words.c
   CSC 111 - Fall 2019 - Assignment 8
   Purpose to print unique words
   B. Bird
   (Poomrapee Chuthamsatid/V00942601/1 DEC 2019)
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
// task2 //1. store a word in array1(currentWord) of 1d from char //2. compare array1 to array2 is there is the word in the array
// 2(listOfWord)
// 3. if not
// 4. store that word in array2(listOfWord) and increase array2's index
// 5. print the word
// 6. print the word
int main() {
    //import file.txt
    FILE* input_file = fopen("input_text.txt", "r");

    //exit if import doesn't work
    if (input_file == NULL){
        printf("Unable to open the file for reading\n");
        return 1; //Exit the program (since we can't do anything else without a file)
    }
    char c = 0;
    char stringChar[10000] = {0};
    int charCount = 0;
    int i = 0;
    int h = 0;
    int isSpace = 0;

    /*task2*/
    char uniqueWordList[10000][100] = {0};//a list of unique word
    char stringWord[10000][100] = {};//contain a word in chars
    //char numWord [10000][1] = {0};//[String word with \0] & [number of time word appear]
    int j = 0;
    int k = 0;
    int isUnique = 1;
    int wordCount = 0;
    int countUniqueWord = 0;
    int numUniqueWord = 0;



    while((c = fgetc(input_file)) != EOF){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '-') || (c == '\'')) {//isalpha(char)
            stringChar[h] = c;
            charCount++;
            h++;
            isSpace = 0;//reset space count
        }//if

        if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '-') || (c == '\'') ) && (isSpace == 0)) {
            if((stringChar[i] >= 'a' && stringChar[i] <= 'z') || (stringChar[i] >= 'A' && stringChar[i] <= 'Z') || (stringChar[i] == '-') || (stringChar[i] == '\'') ) {
                while (stringChar[i] != '\0') {
                    // printf("%c", stringChar[i]);
                    stringWord[j][k] = stringWord[j][k] + tolower(stringChar[i]);//task2

                    k++;//move the position of char
                    i++;
                }//while
            }//if
            stringWord[j][k+1] = '\0';//add '\0' to the last char array when the word finish
            j++;//move the number of the word
            k = 0;//reset the starting index of the next word to 0

            /*task1*/
            isSpace = 1;//if therse is space or newline, count a space or a newline
            charCount = 0;//reset word count when the word is finish
            wordCount++;
            //printf("\n");//create new line for a new word
        }//if
    }//while



    /*Solution to duel with lastword bug (when the while loop hit EOF and skip the last loop for the last word)*/
//  printf("Word (%d characters): ", charCount);
    //char stringWord[100] = {0};
    /* while (stringChar[i] != '\0') {
 //        printf("%c", stringChar[i]);
         stringWord[j] = stringWord[j] + stringChar[i];
         i++;
         j++;
     }//while
     stringWord[][j+1] = '\0';//add '\0' to the last char when the word finish
     printf("%s", stringWord);
     j = 0;//if therse is space or newline, count a space or a newline*/

//printf("%s", stringWord[6]);
    for(int a = 0; a < wordCount; a++) {
        isUnique = 1;
        for (int b = 0; b < wordCount; b++) {
            if ((strcmp(uniqueWordList[b], stringWord[a]) == 0)) {
                isUnique = 0; //no the word not unique
            }//if
        }//for
        if (isUnique == 1) {
            numUniqueWord++;
            isUnique = 0;
            //copy from stringWord to uniqueWordList
            for(int c = 0; c < 100; c++) {
                uniqueWordList[a][c] = stringWord[a][c];
            }//for
            printf("%s\n", stringWord[a]);
            countUniqueWord++;
        }//if
    }//for

    /*Solution to duel with lastword bug (when the while loop hit EOF and skip the last loop for the last word)*/
    //if it is a special symbol or \n or a space skips this
    if((stringChar[i] >= 'a' && stringChar[i] <= 'z') || (stringChar[i] >= 'A' && stringChar[i] <= 'Z') || (stringChar[i] == '-') || (stringChar[i] == '\'') ) {
        while (stringChar[i] != '\0'){
           // printf("%c", stringChar[i]);
            stringWord[j+1][k] = stringWord[j+1][k] + tolower(stringChar[i]);//task2
            i++;
            k++;
        }//while
        isUnique = 1;
        for (int b = 0; b < wordCount; b++) {
            if ((strcmp(uniqueWordList[b], stringWord[j + 1]) == 0)) {
                isUnique = 0; //no the word not unique, dont print
            }//if
        }//for
        if (isUnique == 1) {
            isUnique = 0;
            //copy from stringWord to uniqueWordList
            for(int c = 0; c < 100; c++) {
                uniqueWordList[numUniqueWord+1][c] = stringWord[j+1][c];
            }//for
            printf("%s\n", uniqueWordList[numUniqueWord+1]);
            countUniqueWord++;
        }//if
    }//if
    /*Solution to duel with lastword bug (when the while loop hit EOF and skip the last loop for the last word)*/




//printf("%d", countUniqueWord);
    for(int i = 0; i < 30; i++){
        // printf("\n");
        // printf("%s", uniqueWordList[i]);
    }
    fclose(input_file);
    return 0;
}
