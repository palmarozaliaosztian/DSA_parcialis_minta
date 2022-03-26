cmake_minimum_required(VERSION 3.21)
project(Minta C)

set(CMAKE_C_STANDARD 23)

add_executable(Minta src/main.c headers/car.h src/car.c src/carArray.c headers/carArray.h src/errors.c headers/errors.h headers/useful.h src/carStack.c headers/carStack.h)



include_directories(headers)
