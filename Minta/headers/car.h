//
// Created by palma on 3/24/2022.
//

#ifndef MINTA_CAR_H
#define MINTA_CAR_H

#include "errors.h"

enum Type{
    BENZIN,
    DIESEL,
    HYBRID,
    GAS
};
enum Color{
    RED,
    BLUE,
    YELLOW,
    WHITE,
    BLACK,
    GREEN
};

unsigned static int id_nr = 0;
typedef struct{
    unsigned int id;
    char *brand;
    char *nr_plate;
    int year;
    enum Type type;
    enum Color color;
}Car;

void car_stock(Car **car);

void printCar(Car *car);

char* getCarType(enum Type type);

char *getCarColor(enum Color color);

char* nr_plateType(Car* car);

void car_delete(Car **car);



#endif //MINTA_CAR_H
