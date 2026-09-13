#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  SIZE 100

// *** Function Protoypes ***
char *newString(char *str, int size);
void showArray(char **strings, int count);

int main(int argc, char *argv[]){
    char *arrayStr[SIZE];
    int count = 0;
    char buffer[256];
    int length;

    while(count < SIZE && fgets(buffer, sizeof(buffer), stdin) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';

        length = strlen(buffer);

        arrayStr[count] = newString(buffer, length);
        count++;

    }

    showArray(arrayStr, count);
    

    for(int i = 0; i < count; i++){
        free(arrayStr[i]);
    }

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

void showArray(char **array, int size){
    for(int i = 0; i < size; i++){
        printf("%s\n", array[i]);
    }
}