/* 
 * @author: Christopher Short
 * @version: 2018.04.21
 */

#ifndef SPHERE_H
#define SPHERE_H

#include "rt.h"
#include "vec.h"

typedef struct{
	VEC_T ctr;
	double rad;
}SPHERE_T;

int intersect_sphere(RAY_T ray, SPHERE_T sphere, double *t, VEC_T *int_pt, VEC_T *normal);

#endif
