//
// Created by palma on 3/24/2022.
//

#ifndef MINTA_CARARRAY_H
#define MINTA_CARARRAY_H

#include "car.h"
#define MAX_CARS 10

typedef struct {
    Car **cars;
    int nrOfCars;
    int max;
}CarArray;

void createCarArray(CarArray **carArray, int max);
void readCars(CarArray *carArray, char* fileName);
void printCars(CarArray *carArray, char* destination);
int numberOfCarsByType(CarArray *carArray, enum Type type);
Car* oldestCar(CarArray *carArray);
void deleteCars(CarArray **cars);

#endif //MINTA_CARARRAY_H
