#include "sphere.hpp"

#include <iostream>
#include <math.h>
#include <string>

Sphere :: Sphere(glm::vec3 const& center , float const& radius , std::string const& name, Color const& color ): //radius ohne &const
    Shape(name , color),
    center_{center},
    radius_{radius}
    {};

Sphere :: Sphere():
    Shape(),
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

std::ostream& Sphere :: print(std::ostream& os ) const
    {
        Shape::print(os);
        os << "area: " << area() << " \n volume: " << volume() << " \n center: (" << center_.x << ", " << center_.y << ", " << center_.z << ") \n radius: "  << radius_ << " \n";
        
        return os;
    }

    
