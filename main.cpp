#include <iostream>
#include <stdlib.h>
#include "math_tools.h"
#include "display_tools.h"

int main() {

    Matriz A, inversaA;

    zeroes(A, 3);

    A.at(0).at(0) = 2; A.at(0).at(1) = 2; A.at(0).at(2) = 3;
    A.at(1).at(0) = 4; A.at(1).at(1) = 5; A.at(1).at(2) = 6;
    A.at(2).at(0) = 7; A.at(2).at(1) = 8; A.at(2).at(2) = 9;

    inversaMatriz(A, inversaA);
    showMatriz(inversaA);

    return 0;
}
