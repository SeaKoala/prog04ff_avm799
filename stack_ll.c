#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack_ll.h"
#define MAX_ELEMENTS 100

void makeStack(Stack312 *s){
    s->top = NULL;
}

bool isFull(Stack312 s){
    return false;
}

bool isEmpty(Stack312 s){
    if(s.top == NULL){
        return true;
    }
    return false;
}

void push(StackEntry e,Stack312 *s) {
    StackNode *temp = malloc(sizeof(StackNode));
    temp->next = s->top;
    temp->pixel = e;
    s->top = temp;
}
StackEntry pop(Stack312 *s){
    StackNode *temp = s->top;
    StackEntry retVal = temp->pixel;
    s->top = s->top->next;
    free(temp);
    return retVal;
}