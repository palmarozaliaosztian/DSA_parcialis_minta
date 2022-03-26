//
// Created by palma on 3/26/2022.
//

#include "carStack.h"

void createCarStack(CarStack **carStack, unsigned int capacity) {
    *carStack = (CarStack *) malloc (sizeof(CarStack));
    if(!(*carStack))
    {
        printErrorMessage(MEMORY_ALLOCATION);
    }
    (*carStack)->cars = (Car**) malloc (capacity * sizeof (Car*));
    if(!(*carStack)->cars)
    {
        printErrorMessage(MEMORY_ALLOCATION);
    }
    (*carStack)->capacity = capacity;
    (*carStack)->top = -1;
}

void push(CarStack *carStack, Car *car) {
    if(!stackIsFull(carStack)){
        carStack->top++;
        carStack->cars[carStack->top]=car;
    }
}

void pop(CarStack *carStack) {
    if ( !stackIsEmpty(carStack) ){
        car_delete(&carStack->cars[carStack->top]);
        carStack->cars[carStack->top] = NULL;
        --carStack->top;
    }
}

Car *top(CarStack *carStack) {
    if ( !stackIsEmpty(carStack) ){
        return carStack->cars[carStack->top];
    }
    return NULL;
}

bool stackIsEmpty(CarStack *carStack) {
    return (carStack->top == -1);
}

bool stackIsFull(CarStack *carStack) {
    return (carStack->top == (carStack->capacity - 1));
}

void deleteCarStack(CarStack **carStack) {
    if(*carStack) {
        for (int i = 0; i < (*carStack)->capacity; ++i) {
            car_delete(&(*carStack)->cars[i]);
        }
        free((*carStack)->cars);
        free(*carStack);
        *carStack = NULL;
        printf("CarStack deleted\n");
    }
}
