#include <math.h>
#include "light.h"
#include "vec.h"
#include "rt.h"

/*
 * @author: Christopher Short
 * @version: 2018.04.21
 */

COLOR_T illuminate(RAY_T ray, LIGHT_T light, COLOR_T surface_col, 
    VEC_T int_pt, VEC_T normal) {
   
    COLOR_T color;
    VEC_T light_vec;
    VEC_T regular;

    //calculates light vector
    light_vec.x = light.loc.x - int_pt.x; 
    light_vec.y = light.loc.y - int_pt.y;
    light_vec.z = light.loc.z - int_pt.z;

    //normalize light and normal vectors
    light_vec = normalize(light_vec);
    normal = normalize(normal);

    //ambient
    color.R = 0.2 * surface_col.R;
    color.G = 0.2 * surface_col.G;
    color.B = 0.2 * surface_col.B;

    //diffuse
    if (dot(light_vec, normal) > 0.0) {
        color.R += (dot(light_vec, normal)) * surface_col.R;
        color.G += (dot(light_vec, normal)) * surface_col.G;
        color.B += (dot(light_vec, normal)) * surface_col.B;
    

        //specular
        regular.x = light_vec.x - (normal.x * 2 * dot(light_vec, normal));
        regular.y = light_vec.y - (normal.y * 2 * dot(light_vec, normal));
        regular.z = light_vec.z - (normal.z * 2 * dot(light_vec, normal));
        regular = normalize(regular);
    
        if (dot(regular, ray.dir) > 0.0) {
            color.R += pow(dot(regular, ray.dir), 200);
            color.G += pow(dot(regular, ray.dir), 200);
            color.B += pow(dot(regular, ray.dir), 200);
        }
    }

    return color;
}

