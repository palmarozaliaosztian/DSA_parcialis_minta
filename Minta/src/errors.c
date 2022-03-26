//
// Created by palma on 3/26/2022.
//

#include "errors.h"

void printErrorMessage(enum ErrorType errorType) {
    switch (errorType) {
        case MEMORY_ALLOCATION:
            printf("Bad memory allocation error\n");
            break;
        case FILE_NOT_FOUND:
            printf("File not found exception\n");
            break;
        case NULL_POINTER_EXCEPTION:
            printf("NULL pointer exception\n");
            break;
        case ADD_PRODUCT_ERROR:
            printf("Cannot add new product exception\n");
            break;
        default:
            printf("Ismeretlen hiba \n");
            break;
    }
    exit(-1);
}
