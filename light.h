/*
 * @author: Christopher Short
 * @version: 2018.04.21
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "rt.h"
#include "vec.h"

typedef struct{
        VEC_T loc;
} LIGHT_T;

COLOR_T illuminate(RAY_T ray, LIGHT_T light, COLOR_T surface_col, 
        VEC_T int_pt, VEC_T normal);

#endif