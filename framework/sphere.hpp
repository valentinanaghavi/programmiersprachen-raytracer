#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include <glm/vec3.hpp>

#include "shape.hpp"

class Sphere :: public Shape
{

public:
    Sphere(glm::vec3 center &const , int radius &const);
    Sphere();
    ~Sphere();

    getCenter(glm::vec3 center &const);
    getRadius(int radius &const);

    void area() const override; //abstrakte M. = rein virtuelle Methode
    void volume() const override;
    

private:
    glm::vec3 center_ ;
    int radius_ ;
    /* data */
};




#endif // define BUW_SPHERE_HPP