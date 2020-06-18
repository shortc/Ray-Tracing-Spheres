#include <math.h>
#include "sphere.h"
#include "rt.h"
#include "sphere.h"
#include "vec.h"

/*
 * @author: Christopher Short
 * @version: 2018.04.21
 */

//checks to see if there is an intersection
int intersect_sphere(RAY_T ray, SPHERE_T sph, double *t, VEC_T *int_pt, VEC_T *normal){
    
	double A, B, C;
	double t_0, t_1;

	A = 1;

	B = 2 * (ray.dir.x * (ray.or.x - sph.ctr.x) 
			+ ray.dir.y * (ray.or.y - sph.ctr.y)
			+ ray.dir.z * (ray.or.z - sph.ctr.z));
	
	C = pow((ray.or.x - sph.ctr.x), 2) 
		+ pow((ray.or.y - sph.ctr.y), 2)
		+ pow((ray.or.z - sph.ctr.z), 2) - pow(sph.rad, 2);
	
	if ((pow(B, 2) - (4 * A * C)) > 0) {
		
		//quadratic equation	
		t_0 = (-B + sqrt( pow(B, 2) - 4 * A * C)) / (2 * A);
		t_1 = (-B - sqrt( pow(B, 2) - 4 * A * C)) / (2 * A);

		if (t_0 < t_1) *t = t_0;

		else
			*t = t_1;

		//calculates intersection point
		int_pt -> x = ray.or.x + ray.dir.x * *t;
		int_pt -> y = ray.or.y + ray.dir.y * *t;
		int_pt -> z = ray.or.z + ray.dir.z * *t;

		//calculates normal vector
		normal -> x = (int_pt -> x - sph.ctr.x) / sph.rad;
		normal -> y = (int_pt -> y - sph.ctr.y) / sph.rad;
		normal -> z = (int_pt -> z - sph.ctr.z) / sph.rad;
	
		return 1;
	}

	else
		return 0;
}

