//
// Created by palma on 3/26/2022.
//

#ifndef MINTA_CARSTACK_H
#define MINTA_CARSTACK_H


#include "car.h"

typedef struct {
    unsigned int capacity;
    int top;
    Car** cars;
}CarStack;


void createCarStack(CarStack **carStack, unsigned int capacity);
void push(CarStack *carStack, Car *car);
void pop(CarStack *carStack);
Car* top(CarStack *carStack);
bool stackIsEmpty(CarStack *carStack);
bool stackIsFull(CarStack *carStack);
void deleteCarStack(CarStack **carStack);

#endif //MINTA_CARSTACK_H
