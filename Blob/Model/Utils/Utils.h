#ifndef UTILS_H
#define UTILS_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>
#include <random>

class Utils {
    public :
        /* FUNCTION */
        static int generateRandomNumber(int lo, int hi);
        static float generateRandomFNumber();
};

#endif // UTILS_H
