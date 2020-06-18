#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rt.h"
#include "vec.h"
#include "obj.h"
#include "light.h"

/**
* Ray Tracer
*
* Given an input of spheres, creates a ppm image of the spheres
*
* @author Christopher Short
* @version 2018.04.26
*/ 


//reads in from file
void read_objs (OBJ_T **list) {
	
	// initialize variables
	double rad;
	VEC_T ctr;
	double r, g, b;
	OBJ_T *node;
	
	// list points to nothing
	*list = NULL;

	// reads in from txt file
	while(scanf("%lf %lf %lf %lf %lf %lf %lf", &ctr.x, &ctr.y, &ctr.z, &rad, 
				&r, &g, &b) == 7) {
		
		// sets OBJ_T variables
		node = (OBJ_T *) malloc(sizeof(OBJ_T));
		node -> sph.ctr.x = ctr.x;
		node -> sph.ctr.y = ctr.y;
		node -> sph.ctr.z = ctr.z;
		node -> sph.rad = rad;
		node -> color.R = r;
		node -> color.G = g;
		node -> color.B = b;
		
		// addds node to list
		node -> next = *list;
		*list = node;
	}	
}

// gets color from closest sphere
COLOR_T trace(RAY_T ray, OBJ_T *list, LIGHT_T light) {
	
	OBJ_T *curr;
	OBJ_T *closest_obj;

	COLOR_T color;

	VEC_T int_pt;
	VEC_T normal;
	VEC_T closest_normal;
	VEC_T closest_int_pt;

	double t;
	double min_t;

	min_t = 1000;
	color.R = 0;
	color.G = 0;
	color.B = 0;
	closest_obj = NULL;

	// goes through linked list
	for(curr = list; curr != NULL; curr = curr -> next) {

		// if there is an intersection, gets color
		if(intersect_sphere(ray, curr -> sph, &t, &int_pt, &normal)) {
		
			if ( t < min_t) {
				min_t = t;	
				closest_int_pt = int_pt;
				closest_normal = normal;
				closest_obj = curr;
				color = curr -> color;
			}
		}
	}
	if (closest_obj != NULL) {
		color = illuminate(ray, light, color, closest_int_pt, 
			closest_normal);
	}

	return color;
}

// prints to ppm image file
int main() {

	RAY_T ray;
	SPHERE_T sph;
	OBJ_T *list;

	COLOR_T color;

	LIGHT_T light;
	light.loc.x = 5.0;
	light.loc.y = 10.0;
	light.loc.z = 0.0;
	
	int x3D, y3D;

	double t;	

	unsigned char r, g, b;
	
	//reads in from file
	read_objs (&list);

	printf("P6\n1000 1000\n255\n");
	
	//iterates through pixels
	for (y3D = 0; y3D < 1000; y3D++) {
	
		for (x3D = 0; x3D < 1000; x3D++) {
			
			ray.or.x = 0;
			ray.or.y = 0;
			ray.or.z = 0; //this might need to be 1
			
			ray.dir.x = -0.5 + (x3D / 1000.0);
			ray.dir.y = 0.5 - (y3D / 1000.0);
			ray.dir.z = 1;
	
			ray.dir = normalize(ray.dir);
	
			color.R = 0;
			color.G = 0;
			color.B = 0;

			t = 1;

			//if (intersect_sphere(ray, sph, &t) == 1) 
			color = trace(ray, list, light);

			if (color.R > 1.0) color.R = 1.0;
			if (color.G > 1.0) color.G = 1.0;
			if (color.B > 1.0) color.B = 1.0;

			//prepares rbg vals for printing
			r = (unsigned char)(color.R * 255);
			g = (unsigned char)(color.G * 255);
			b = (unsigned char)(color.B * 255);

			printf ("%c%c%c", r, g, b);

		}
	}

	return 0;
}

