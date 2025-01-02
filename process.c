/*
Junhui Park
CS50 Period 5
5 November 2024
Process Code - Case sensitive
*/

//import libraries
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

//main
int main(int argc, char* argv[]) {
    //define all variables
    char userChar; //character that user is looking for
    char userFile[30]; //file name to search the words + characters
    char fileLetter; //current character being read from the file
    int charCount = 0; //letter count for user's letter
    int wordCount = 0; //total word count
    int insideWord = 0; //flag to indicate if we are inside a word or not

    //user input
    printf("Please enter a character: "); //get user character
    scanf("%s", &userChar); //assign user input to userChar
    printf("Please enter a file to process: "); //get file name
    scanf("%s", userFile); //assign file name to userFile variable

    //open file that corresponds to the user's file name
    FILE *file = fopen(userFile, "r");
    //error message if file cannot be opened (file name does not match with anything else)
    if (file == NULL) {
        //error message
        printf("Error opening file.\n");
        return 1; //exit program
    }

    //while loop; loop through each character in the file
    //CASE SENSITIVE - only looks for lowercase if you put lowercase
    //file character is not the end of the file (EOF = end of file)
    while((fileLetter = fgetc(file)) != EOF) {
        if (fileLetter == userChar) {
            //increment character count if file letter matches user's letter
            charCount++;
        }

        //check for word boundaries
        //blank, new line, tab = outside a word = do not increment counter
        if (fileLetter == ' ' || fileLetter == '\n' || fileLetter == '\t') {
            //set indicator of word boundary = 0
            //outside a word
            insideWord = 0;
        } else if (insideWord == 0) { //inside a word
            //set indicator of word boundary = 1
            insideWord = 1;
            //increment word counter since we are inside a word
            wordCount++;
        }
    }

    //close file when done
    fclose(file);

    //print the summary of word count and character count
    printf("There are %d words in this file, and the letter '%c' occurs %d times.\n", wordCount, userChar, charCount);

    //end of program
    return 0;

}
