#include <math.h>
#include "vec.h"
/**
* @author Christopher Short
* @version 2018.03.26
*/

//normalizes a given vector and returns VEC_T
VEC_T normalize(VEC_T v) {
	
	double dis, dis_sqrt;
	VEC_T norm_v;	

	dis = (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
	dis_sqrt = sqrt(dis);

	norm_v.x = v.x / dis_sqrt;
	norm_v.y = v.y / dis_sqrt;
	norm_v.z = v.z / dis_sqrt;

	return norm_v;
}

//calculates dot product of two vectors
double dot (VEC_T v1, VEC_T v2) {
	double dot_prod;
	dot_prod = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return dot_prod;
}
