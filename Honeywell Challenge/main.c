
/* 
 * File:   main.c
 * Author: Alexander Jesse Thomas
 *
 * Created on November 30, 2017, 3:20 PM
 */

//header files 
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

/*
 * This function was for testing to make sure the pointers were working properly
 * Making sure that **lines has access to everything set in the main function. 
 */
void printOutArray(char **lines, int maxLines){ //This function as only for testing 
    for(int i = 0; i <= maxLines; i++){
        printf("%s",lines[i]); //making sure lines were being saved properly 
    }
}

/*
 * This function is for comparing the strings that lines has access to 
 * This is where string.h is used because we use strcmp to compare the strings 
 * There are also lines of code in this function that were useful for testing. 
 */
void results(char **lines, int maxLines){
    
    int counter, i, j, secondCounter;
    char *null = "null";//used for getting rid of duplicate strings later in function
    printf("\nResults:\n");// Not in original problem statement but I used just to show the user where the results are being displayed
    
    for(i = 0; i <= maxLines; i++){
        
        //printf("\nentering results first loop\n"); //testing
        
        counter = 0; 
        for(j = 0; j <= maxLines; j++){
             
          //  printf("\npast counter second loop\n"); //testing
            
            if(strcmp(lines[i], lines[j]) == 0){
                counter++; 
                secondCounter++;
                if(counter > 1){ //used to avoid print duplicate values 
                    lines[j] = null;
                }
            }
            
        }
        if(secondCounter >1){
            if(lines[i] != null) //used to avoid printing duplicate values. 
            printf("%d %s",counter, lines[i]);
        }
    }
}

/*
 * Main function where User enters number of lines. 
 * This can be adjusted to the user doesn't have to enter the number of lines. 
 * It can be adjusted if we knew the number of lines the user was going to enter.
 * There are also lines of code in this function that were used for testing 
 * Lastly made sure to free allocated memory
 */
int main(int argc, char** argv) {
    
    int maxLines = 100;
    printf("Please enter the number of lines you are going to enter: ");
    scanf("%d", &maxLines);
    //printf("%d\n", maxLines); //This line was for testing 
    
    printf("Please enter your text. Please press enter after each line has been typed: \n");
    char **lines = (char**) malloc(sizeof(char*) * maxLines);
    for(int i = 0; i <= maxLines; i++){
        char *line = NULL;
        int read;
        size_t length;
        read = getline(&line, &length, stdin);
        
        lines[i] = line;
    }
    //printOutArray(lines, maxLines); // this is for testing
    results(lines, maxLines);
    free(lines);
    return (0);
}

