
#include "carArray.h"
#include "carStack.h"

int main() {

    ///Első autó: beolvasás, kiiratás képernyőre
    Car *car1;
    car_stock(&car1);

    printf("Brand:");
    scanf("%[^\n]", car1->brand);
    printf("Nr_Plate:");
    scanf("\n%[^\n]", car1->nr_plate);
    printf("Year:");
    scanf("%i", &car1->year);
    printf("Type(0 - 3):");
    scanf("%i", &car1->type);
    printf("Color(0 - 5):");
    scanf("%i", &car1->color);

    printCar(car1);

    printf("Megye: %s\n", nr_plateType(car1));


    ///Második autó: beolvasás, kiiratás állományba

    Car *car2;
    car_stock(&car2);

    printf("Brand:");
    scanf("\n%[^\n]", car2->brand);
    printf("Nr_Plate:");
    scanf("\n%[^\n]", car2->nr_plate);
    printf("Year:");
    scanf("%i", &car2->year);
    printf("Type(0 - 3):");
    scanf("%i", &car2->type);
    printf("Color(0 - 5):");
    scanf("%i", &car2->color);



    char *fileName = malloc(MAX_BRAND* sizeof(char));
    if(!fileName) {
        printErrorMessage(FILE_NOT_FOUND);
    }
    strcpy(fileName, car2->brand);
    strcat(fileName, ".txt");

    freopen(fileName, "w", stdout);
    printCar(car2);
    printf("Megye: %s\n", nr_plateType(car2));
    freopen("CON", "w", stdout);

    if(strcmp(nr_plateType(car1), nr_plateType(car2)) == 0) {
        printf("A ket auto ugyanabbol a megyebol van\n");
    }
    else {
        printf("A ket auto nem ugyanabbol a megyebol van\n");
    }
    car_delete(&car1);
    car_delete(&car2);
    //Hozz létre egy Autógyártó típust.
    CarArray *carArray;
    createCarArray(&carArray, MAX_CARS);
    //Olvasd be az autók adatait állományból, és helyezd be ezeket a tömbe.
    readCars(carArray, "inputCar.txt");
    //Írd ki az autókat a képernyőre.
    printCars(carArray, "CON");
    //printCars(carArray, "autok_kimenet.txt");
    //Határozd meg, hogy hány DIESEL autó van.
    printf("Diesel autok szama: %i\n", numberOfCarsByType(carArray, DIESEL));
    //Melyik a legrégebbi autó?
    printf("A legregebbi auto:\n");
    printCar(oldestCar(carArray));

    //Építs fel egy Autókból álló vermet a FEKETE autókból.
    CarStack *carStack;
    createCarStack(&carStack, MAX_CARS);
    for (int i = 0; i < carArray->nrOfCars; ++i) {
        if(carArray->cars[i]->color == BLACK)
        {
            push(carStack, carArray->cars[i]);
        }
    }

    //Addig vegyél ki a veremből autókat, amíg az évjárat 2012-nél kisebb vagy üres nem lesz a verem.
    while(!stackIsEmpty(carStack) && top(carStack)->year < 2012) {
        pop(carStack);
    }
    //Írd ki ezt követően a verem legfelső elemét.
    printf("Verem tetejen levo auto:");
    printCar(top(carStack));

    deleteCars(&carArray);
    deleteCarStack(&carStack);

    return 0;
}
