/*  extract_words.c
   CSC 111 - Fall 2019 - Assignment 8
   Purpose to print words
   (Poomrapee Chuthamsatid/V00942601/1 DEC 2019)
*/
#include <stdio.h>
#include <ctype.h>

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
    int wordCount = 0;
    int i = 0;
    int h = 0;
    int isSpace = 0;

    while((c = fgetc(input_file)) != EOF){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '-') || (c == '\'')) {//isalpha(char)
            stringChar[h] = c;
            wordCount++;
            h++;
            isSpace = 0;
        }//if

        if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '-') || (c == '\'') ) && (isSpace == 0)) {
            if((stringChar[i] >= 'a' && stringChar[i] <= 'z') || (stringChar[i] >= 'A' && stringChar[i] <= 'Z') || (stringChar[i] == '-') || (stringChar[i] == '\'') ) {
                printf("Word (%d characters): ", wordCount);
                while (stringChar[i] != '\0') {
                    printf("%c", stringChar[i]);
                    i++;
                }//while
            }//if
            isSpace = 1;
            wordCount = 0;
            printf("\n");
        }//if
    }//while

    if((stringChar[i] >= 'a' && stringChar[i] <= 'z') || (stringChar[i] >= 'A' && stringChar[i] <= 'Z') || (stringChar[i] == '-') || (stringChar[i] == '\'') ) {
        printf("Word (%d characters): ", wordCount);
        while (stringChar[i] != '\0'){
                printf("%c", stringChar[i]);
                i++;
        }//while
    }
    fclose(input_file);
    return 0;
}