/*  analyze_text.c
   CSC 111 - Fall 2019 - Assignment 8
   Purpose to analze words
   (Poomrapee Chuthamsatid/V00942601/1 DEC 2019)
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
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
    int j = 0;
    int k = 0;
    int isUnique = 1;
    int wordCount = 0;
    int countUniqueWord = 0;
    /*task3*/
    int numUniqueWord = 0;
    char listOfNumChar[10000] = {0};//number of char of each word
    char listOfNumUniqueChar[10000] = {0};
    int z = 0;
    int longest = 0;
    int shortest = 100;
    int length = 0;
    int x1 = 0;
    int frequencyArray[1000] = {0};
    int frequency = 0;
    int mostFrequency = 0;

    while((c = fgetc(input_file)) != EOF){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '-') || (c == '\'')) {//isalpha(char)
            stringChar[h] = c;
            charCount++;
            h++;
            isSpace = 0;//reset space count
        }//if

        if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '-') || (c == '\'')) && (isSpace == 0) ) {
            printf("here %c", c);
            if ((stringChar[i] >= 'a' && stringChar[i] <= 'z') || (stringChar[i] >= 'A' && stringChar[i] <= 'Z') ||
                (stringChar[i] == '-') || (stringChar[i] == '\'')) {
                while (stringChar[i] != '\0') {
                    //printf("%c", stringChar[i]);
                    stringWord[j][k] = stringWord[j][k] + tolower(stringChar[i]);//task2

                    k++;//move the position of char
                    i++;
                }//while
            }//if
            stringWord[j][k + 1] = '\0';//add '\0' to the last char array when the word finish
            j++;//move the number of the word
            k = 0;//reset the starting index of the next word to 0

            /*task1*/
            isSpace = 1;//if therse is space or newline, count a space or a newline
            charCount = 0;//reset word count when the word is finish
                wordCount++;
            //printf("\n");//create new line for a new word
        }//if
    }//while

    /*compare word*/
    for(int a = 0; a < wordCount; a++) {
        isUnique = 1;
        for (int b = 0; b < wordCount; b++) {
            if ((strcmp(uniqueWordList[b], stringWord[a]) == 0)) {
                isUnique = 0; //no the word not unique
            }//if
        }//for
            if (isUnique == 1 ) {
                numUniqueWord++;
                countUniqueWord++;
                isUnique = 0;
                //copy from stringWord to uniqueWordList
                for(int c = 0; c < 100; c++) {
                    uniqueWordList[x1][c] = stringWord[a][c];
                }//for
                x1++;
                /*task3*/
                listOfNumChar[z] = c;//store number of char of each word (c is num of char)
                z++;
            }//if
        }//for
//printf("%d", wordCount);

    /*compare word*/
    /*Solution to duel with lastword bug (when the while loop hit EOF and skip the last loop for the last word)*/
    //if it is a special symbol or \n or a space skips this
    charCount = 0;
    if((stringChar[i] >= 'a' && stringChar[i] <= 'z') || (stringChar[i] >= 'A' && stringChar[i] <= 'Z') || (stringChar[i] == '-') || (stringChar[i] == '\'')) {
        while (stringChar[i] != '\0'){

            stringWord[j][k] = stringWord[j][k] + tolower(stringChar[i]);//task2
            i++;//number of char
            k++;//number of char
        }//while


       // printf("\n");//create new line for a new word
        isUnique = 1;
        for (int b = 0; b < wordCount; b++) {
            if ((strcmp(uniqueWordList[b], stringWord[j]) == 0)) {

                isUnique = 0; //no the word not unique, dont print
            }//if
        }//for
        if (isUnique == 0) {
                wordCount++;//it is not unique word
        }//if
         listOfNumChar[z] = k;
        if (isUnique == 1) {
            isUnique = 0;
            //copy from stringWord to uniqueWordList
            for(int c = 0; c < 100; c++) {
                uniqueWordList[numUniqueWord][c] = stringWord[j][c];
            }//for
            //printf("%s\n", uniqueWordList[numUniqueWord]);
                wordCount++;

            countUniqueWord++;
        }//if
    }//if



    /*Solution to duel with lastword bug (when the while loop hit EOF and skip the last loop for the last word)*/
//printf("%d", countUniqueWord);
    /*task3*/
    //get num of char from last word
    //if it is a character
    if((stringChar[i] >= 'a' && stringChar[i] <= 'z') || (stringChar[i] >= 'A' && stringChar[i] <= 'Z') || (stringChar[i] == '-') || (stringChar[i] == '\'') ) {
        //printf("Word (%d characters): ", wordCount);
        while (stringChar[i] != '\0'){
            //printf("%c", stringChar[i]);
            charCount++;
            i++;
        }//while
    }//if

    //count chars of each word
    for (int l = 0; l <= countUniqueWord; ++l) {
        int countchar = 0;
        for (int j = 0; j < 100; ++j) {
            if((uniqueWordList[l][j] >= 'a' && uniqueWordList[l][j] <= 'z') || (uniqueWordList[l][j] == '-') ||
               (uniqueWordList[l][j] == '\'')){
                countchar++;
            }//if
        }//for
        listOfNumUniqueChar[l] = countchar;
    }//for

        /*find longest word*/
        for(int x = 0; x < countUniqueWord; x++){
            if(listOfNumUniqueChar[x] > longest && listOfNumUniqueChar[x] > 0){
                longest = listOfNumUniqueChar[x];
        }//if
    }//for
    //printf("The longest is %d\n", longest);

    /*find shortest*/
    for(int y = 0; y < countUniqueWord; y++){
        if(listOfNumUniqueChar[y] < shortest && listOfNumUniqueChar[y] > 0){
            shortest = listOfNumUniqueChar[y];
        }//if
    }//for
    //printf("The shortest is %d\n", shortest);

    //result
    printf("Total words: %d\n", wordCount);
    printf("Unique words: %d\n", countUniqueWord);

/*print longest word*/
printf("Longest words:\n");
for(int w = 0; w <= countUniqueWord; w++){
    for(int v = 0;v < 100;v++) {
        if ((uniqueWordList[w][v] >= 'a' && uniqueWordList[w][v] <= 'z') || (uniqueWordList[w][v] == '-') ||
            (uniqueWordList[w][v] == '\'')) {
            length++;
        }//if
    }//for
    if(length == longest){

        printf("  %s\n", uniqueWordList[w]);
    }//if
    length = 0;//reset length of word
}//for


/*print shortest word*/
    printf("\nShortest words:\n");
    for(int w = 0; w <= countUniqueWord; w++){
        for(int v = 0;v < 100;v++) {
            if ((uniqueWordList[w][v] >= 'a' && uniqueWordList[w][v] <= 'z') || (uniqueWordList[w][v] == '-') ||
                (uniqueWordList[w][v] == '\'')) {
                length++;
            }//if
        }//for
        if(length == shortest){
            printf("  %s\n", uniqueWordList[w]);
        }//if
        length = 0;//reset length of word
    }//for
    printf("\n");

    /*FREQUEBTCY*/
    /*FREQUEBTCY*/
    for(int o = 0; o < wordCount; o++) {
        frequency = 0;
        for(int p = 0; p < wordCount; p++) {
            if(((strcmp(uniqueWordList[o], stringWord[p])) == 0) && stringWord[p] != NULL && stringWord[p] != 0){
                frequency = frequency + 1;
            }//if
        }//for
        frequencyArray[o] = frequency;
    }//for
    for(int oo = 0; oo < countUniqueWord; oo++) {
        //printf("%s", uniqueWordList[oo]);
       //printf("%d\n", frequencyArray[oo]);
       //enter if statement if meeting more frequency word
        if(frequencyArray[oo] > mostFrequency && frequencyArray[oo] != 0){
            mostFrequency = frequencyArray[oo];//mostFrequency becomes most frequency
        }//if
    }//for
    printf("Most frequently occurring words:\n");
    for(int q =0;q < countUniqueWord; q++){
        if(mostFrequency == frequencyArray[q]){
            printf("  %s\n", uniqueWordList[q]);
        }//if
    }//for


    fclose(input_file);
    return 0;
}
