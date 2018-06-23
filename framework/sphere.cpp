#include "sphere.hpp"

#include <iostream>
#include <math.h>

Sphere :: Sphere(glm::vec3 const& center , float const& radius ): //radius ohne &const
    center_{center},
    radius_{radius}
    {};

Sphere :: Sphere():
    center_{0.0 , 0.0 , 0.0}, 
    radius_{0.0f}
    {};

Sphere :: ~Sphere()
    {};

glm::vec3 const& Sphere :: getCenter() const
    {
        return center_ ;
    }

float const& Sphere :: getRadius() const //nur const , ohne &
    {
        return radius_ ;
    }

float Sphere :: area() const  //abstrakte M. = rein virtuelle Methode
    {
        return 4.0f * M_PI * radius_ * radius_ ; 
    }

float Sphere :: volume() const
    {
        return (4.0f / 3.0f) * M_PI * radius_ * radius_ * radius_ ; //std::abs
    } 



    
