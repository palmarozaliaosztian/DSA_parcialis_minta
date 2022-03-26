//
// Created by palma on 3/24/2022.
//

#include "car.h"

void car_stock(Car **car)
{
    (*car) = malloc(sizeof(Car));
    if((*car)==NULL)
    {
        printErrorMessage(MEMORY_ALLOCATION);
    }
    (*car)->brand = malloc(MAX_BRAND*sizeof(char));
    (*car)->nr_plate = malloc(MAX_NRPLATE*sizeof(char));
    if((*car)->brand==NULL || (*car)->nr_plate==NULL)
    {
        printErrorMessage(MEMORY_ALLOCATION);
    }
    id_nr++;
    (*car)->id = id_nr;
}

void printCar(Car *car)
{
    if(car) {
        printf("Car details:\n");
        printf("\tID: %i\n", car->id);
        printf("\tBrand: %s\n", car->brand);
        printf("\tNr_Plate: %s\n", car->nr_plate);
        printf("\tYear: %i\n", car->year);
        printf("\tType: %s\n", getCarType(car->type));
        printf("\tColor: %s\n\n", getCarColor(car->color));
    }
    else printf("Car is NULL\n");
}

char *getCarColor(enum Color color) {
    switch (color) {
        case BLACK:
            return "Black";
        case WHITE:
            return "White";
        case RED:
            return "RED";
        case GREEN:
            return "Green";
        case YELLOW:
            return "Yellow";
        case BLUE:
            return "Blue";
        default:
            return "Undefined";
    }
}

char* nr_plateType(Car* car){
    if(car->nr_plate[1] < 'A' || car->nr_plate[1] > 'Z')
        return "B";
    else{
        char* nr = (char*) calloc(2, sizeof(char ));
        strncpy(nr, car->nr_plate, 2);
        nr[2] = '\0';
        return nr;
    }
}


char* getCarType(enum Type type)
{
    switch (type) {
        case BENZIN:{
            return "Benzin";
        }
        case HYBRID:{
            return "Hybrid";
        }
        case DIESEL:
            return "Diesel";
        case GAS:
            return "Gas";
        default:{
            return "Unknown";
        }
    }
}

void car_delete(Car **car) {
    if((*car)) {
        free((*car)->nr_plate);
        free((*car)->brand);
        free(*car);
        (*car) = NULL;
        printf("Car deleted\n");
    }
}
