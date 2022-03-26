//
// Created by palma on 3/24/2022.
//

#include "carArray.h"

void createCarArray(CarArray **carArray, int max) {
    (*carArray) = (CarArray*) malloc(sizeof(CarArray));
    if(!(*carArray)){
        printf("Helyfoglalasi hiba!\n");
        exit(-1);
    }
    (*carArray)->cars = malloc(max * sizeof(Car));
    if(!(*carArray)->cars){
        printf("Helyfoglalas nope!\n");
        exit(-1);
    }
    (*carArray)->max = max;
    (*carArray)->nrOfCars = 0;
    for (int i = 0; i < max; ++i) {
        (*carArray)->cars[i] = NULL;
    }
}

void readCars(CarArray *carArray, char *fileName) {
    freopen(fileName, "r", stdin);
    scanf("%i", &carArray->nrOfCars);
    for (int i = 0; i < carArray->nrOfCars; ++i) {
        car_stock(&carArray->cars[i]);
        scanf("\n%[^\n]", carArray->cars[i]->brand);
        scanf("\n%[^\n]", carArray->cars[i]->nr_plate);
        scanf("%i", &carArray->cars[i]->year);
        scanf("%i", &carArray->cars[i]->color);
        scanf("%i", &carArray->cars[i]->type);
    }
}

void printCars(CarArray *carArray, char *destination) {
    freopen(destination, "w", stdout);
    for (int i = 0; i < carArray->nrOfCars; ++i) {
        printCar(carArray->cars[i]);
    }
    freopen("CON", "w", stdout);
}

int numberOfCarsByType(CarArray *carArray, enum Type type) {
    int nrOfCars = 0;
    for (int i = 0; i < carArray->nrOfCars; ++i) {
        if(carArray->cars[i]->type == type) {
            nrOfCars++;
        }
    }

    return nrOfCars;
}

Car *oldestCar(CarArray *carArray) {
    int minYear = carArray->cars[0]->year;
    int oldestCarPosition = -1;
    for (int i = 1; i < carArray->nrOfCars; ++i) {
        if(carArray->cars[i]->year < minYear) {
            minYear = carArray->cars[i]->year;
            oldestCarPosition = i;
        }
    }
    if(oldestCarPosition != -1) {
        return carArray->cars[oldestCarPosition];
    }
    return NULL;

}

void deleteCars(CarArray **cars) {
    if(*cars) {
        for (int i = 0; i < (*cars)->max; ++i) {
            car_delete(&(*cars)->cars[i]);
        }
        free((*cars)->cars);
        free(*cars);
        *cars = NULL;
        printf("CarArray deleted\n");
    }
}


