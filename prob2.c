#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  SIZE 100

// *** Function Protoypes ***
char *newString(char *str, int size);
void showArray(char **strings);

int main(int argc, char *argv[]){
    char **arrayStr = malloc((SIZE + 1) * sizeof(char *));
    int count = 0;
    char buffer[256];
    int length;

    FILE *file = fopen("input.txt", "r'");
    if(file == NULL){
        return 1;
    }

    //for file change 'stdin' to 'file'
    //example below
    //while(count < SIZE && fgets(buffer, sizeof(buffer), file) != NULL)
    while(count < SIZE && fgets(buffer, sizeof(buffer), stdin) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';

        length = strlen(buffer);

        arrayStr[count] = newString(buffer, length);
        count++;

    }
    //NULL-terminate after last string
    arrayStr[count] = NULL;

    showArray(arrayStr);
    
    //throws away individual string
    for(int i = 0; i < count; i++){
        free(arrayStr[i]);
    }

    //throws away array holding pointers
    free(arrayStr);

    fclose(file);

    return 0;
}

char *newString(char *str, int size){
    char *heap = malloc((size + 1) * sizeof(char));

    if(heap == NULL){
        printf("Memory Allocation failed\n");
        return NULL;
    }

    strcpy(heap, str);

    return heap;
}

void showArray(char **array){
    char **pointer = array;

    while(*pointer != NULL){
        printf("%s\n", *pointer);
        pointer++;
    }
}