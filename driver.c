#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_ll.h"

void check (int num){
    printf("check: %d\n", num);
}

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols) {
    FILE *fptr;
    fptr = fopen(fname, "r");

    if (fptr == NULL) {
        printf("Poor path\n");
        exit(-42);
    } else {
        printf("success!\n");
    }
    char buf[BUFSIZ];
    *numRows = 0;
    while (fgets(buf, sizeof(buf), fptr)) {
        grid[*numRows] = (char *) malloc(sizeof(char)*strlen(buf));
        strcpy(grid[*numRows], buf);
        *numRows = *numRows+1;
        *numCols = (strlen(buf));

    }

}
void showWorld(char *grid[], int numRows, int numCols){
    for (int i=0; i<numRows; i++){
        for (int j=0; j<numCols; j++){

            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void floodFill(int Row, int Col, char color, char replace, char* grid[], int numRows, int numCols, Stack312 *s) {
    for (int i = Row - 1; i < Row + 2; i++) {
        if ((i < 0) || i >= numRows) {
            continue;
        }
        for (int j = Col - 1; j < Col + 2; j++) {
            if ((j < 0) || j >= numCols) {
                continue;
            }
            if (grid[i][j] == replace) {
                grid[i][j] = color;
                Pixel p = {i, j, color};
                push(p, s);
            }
        }
    }
    if(isEmpty(*s)){
        return;
    }
    else {
        Pixel temp = pop(s);
        floodFill(temp.row, temp.col, color, replace, grid, numRows, numCols, s);
    }
}

Pixel promptUser(int rows, int cols){
    Pixel input = {-2, -2, -2};
    printf("Enter Row Between 0 and %d : ", rows-1);
    scanf("%d", &input.row);
    printf("Enter Column Between 0 and %d : ", cols-1);
    scanf("%d", &input.col);
    printf("Enter Color (letter): ");
    scanf(" %c", &input.color);
    if(input.row == -1 || input.col == -1)
        exit(0);
    return input;
}

char *picture[80];
int Rows;
int Cols;
Stack312 stack;
bool running = true;

int main(int argc, char *argv[]) {
    char *fName = argv[1];
    printf("fileName: %s\n", fName);
    makeStack(&stack);
    populateWorld(fName, picture, &Rows, &Cols);
    printf("%d, %d \n", Rows, Cols);
    showWorld(picture, Rows, Cols);
    while(running){
        printf("\n");
        Pixel input= promptUser(Rows, Cols);
        while(input.row < -1 || input.row >= Rows || input.col <-1 || input.col >=Cols){
            input = promptUser(Rows, Cols);
        }
        floodFill(input.row, input.col, input.color, picture[input.row][input.col], picture, Rows, Cols, &stack);
        printf("-------------------------\n");
        showWorld(picture, Rows, Cols);
    }

}

