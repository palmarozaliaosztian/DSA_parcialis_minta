//
// Created by palma on 3/26/2022.
//

#ifndef MINTA_ERRORS_H
#define MINTA_ERRORS_H

#include "useful.h"

enum ErrorType {
    MEMORY_ALLOCATION,
    FILE_NOT_FOUND,
    NULL_POINTER_EXCEPTION,
    ADD_PRODUCT_ERROR
};
void printErrorMessage(enum ErrorType errorType);

#endif //MINTA_ERRORS_H
