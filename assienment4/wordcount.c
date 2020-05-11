/* wordcount.c
   CSC 111 - Fall 2019 - Assignment 4

   (Poomrapee Chuthamsatid/V00942601/6 Oct 2019)
   objective: The program that counts and illustrates numbers of lines, words and characters from a text a user puts.
*/
#include <stdio.h>
#include <ctype.h>
int main() {

    char input = getchar();//get input from the user
    char previousWord = ' ';//every letter follow by whitespace is a word
    int wordCount = 0;
    int lineCount = 1;//1 is to include the first line
    int charCount = 0;
    int isLoopRun = 0;

    previousWord = input;//initially set the previousWord
    //if input = '#', end the loop
    while(input != '#'){
        charCount++;//count char including whitespace
        //is it space or not
        if(isspace(input)){
            if(input == '\n'){
                lineCount++;//count number of line
            }//if
        }//if

        //add one to word count if the previous char is not whitespace and then the current input is whitespace
        if((previousWord != ' ' && previousWord != '\n' && previousWord != '\t'
            && previousWord != '\v' && previousWord != '\f' && previousWord != '\r')
            && (input == ' '|| input == '\n' || input == '\t'|| input == '\v' || input == '\f'||
            input == '\r')){
            wordCount++;
        }//if
        previousWord = input;//set previousWord to be the input
        input = getchar();//move the position of a char of the input from 0 to 1 to ...n
        isLoopRun = 1;
    }//while

    //if the last word ended up without space, it is a word add one to wordCount
    if((previousWord != ' ' && previousWord != '\n' && previousWord != '\t'
        && previousWord != '\v' && previousWord != '\f' && previousWord != '\r')
        && input == '#'){
        wordCount++;
    }//if
    if((previousWord == '\n') && input == '#'){
        lineCount--;
    }//if
    if(isLoopRun == 0 && input == '#'){
        wordCount--;
        lineCount--;
    }
    printf("Characters: %d, Words: %d, Lines: %d", charCount, wordCount, lineCount);
    return 0;
}

