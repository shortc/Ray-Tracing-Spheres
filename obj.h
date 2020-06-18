/*
 * @author: Christopher Short
 * version: 2018.04.21
 */

#ifndef OBJ_H
#define OBJ_H

#include "sphere.h"
#include "rt.h"

typedef struct NODE{
	SPHERE_T sph;
    COLOR_T color;
    struct NODE *next;
} OBJ_T;

#endif

