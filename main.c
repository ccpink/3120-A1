#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    //Initialize Variables
    FILE *fp;
    char buffer[1024];
    char *input;
    size_t len;
    const char *delimiter= " ";
    char *tokens;
    char *token_next;
    //Scan User" Input
    printf("Please Enter Your Sentence: ");
    fgets(buffer, sizeof(buffer), stdin);
    //remove the \n added by fgets
    buffer[strcspn(buffer, "\n\r")] = 0;
    //Allocated string into a string.
    len = strlen(buffer);
    input = (char *)malloc((len + 1) * sizeof(char));
    strcpy(input, buffer);
    //Tokenize the string
    tokens = strtok(input, delimiter);
    //Open File
    fp = fopen("output.txt", "w");
    //print out each word
    while (tokens != NULL) {
        //print word in console
        printf("%s\n", tokens);
        //next token
        token_next = strtok(NULL, delimiter);
        if (token_next != NULL){
            //store in file with a new line character
            fprintf(fp,"%s\n", tokens);
        }else {
            //store in file without adding a newline character as this is the end.
            fprintf(fp,"%s", tokens);
        }
        tokens = token_next;
    }
    //Close File
    fclose(fp);
    //free values
    free(input);
    return 0;
}