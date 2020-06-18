/**
* @author Christopher Short
* @version 2018.03.26
*/

#ifndef RT_H
#define RT_H

#include "vec.h"

typedef struct {
	VEC_T or;
	VEC_T dir;
} RAY_T;

typedef struct {
	double R;
	double G;
	double B;
} COLOR_T;

#endif

