#include "sphere.hpp"

#include<glm/glm.hpp>
#include<glm/gtx/intersect.hpp>
#include <glm/vec3.hpp>

#include <iostream>
#include <math.h>
#include <string>
#include "Ray.hpp"

Sphere :: Sphere():
    Shape{},
    center_{0.0 , 0.0 , 0.0}, 
    radius_{0.0f}
    {
        std::cout << "default Constructor class Sphere - Child" << std::endl ;
    };

Sphere :: Sphere(glm::vec3 const& center , float const& radius , std::string const& name, Material const& material): //radius ohne &const
    Shape{name , material},
    center_{center},
    radius_{radius}
    {
       // std::cout << "Construcotr class Sphere - Child" << std::endl ;
    };


Sphere :: ~Sphere()
    {
       // std::cout << "Destructor class Sphere - Child" << std::endl ;
    };


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
        Shape::print(os);   //prints name and material
        os << "area: " << area() << " \n volume: " << volume() << " \n center: (" << center_.x << ", " << center_.y << ", " << center_.z << ") \n radius: "  << radius_ << " \n";
        
        return os;
    }

bool Sphere :: intersect (Ray const& ray, float& distance) const
    {
        //ray.direction = glm::normalize(ray.direction); //vielleicht auskommentieren , Richtung muss normalisiert sein!
        return glm::intersectRaySphere(ray.origin,ray.direction, center_, radius_*radius_, distance); 
        //Berrechnung/Ueberpruefung des Schnitts von Strahl und Kugel
        // ray starting - normalisierte Richtung des Strahl - Kugel Mittelpunkt - quadrierter radius - Schnitt Abstand
    }


    
