#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include "Ray.hpp"

#include <glm/vec3.hpp>
#include <iostream>
#include <string>


class Sphere : public Shape
{

public:
    Sphere(glm::vec3 const& center, float const& radius , std::string const& name, Color const& color);
    Sphere();
    ~Sphere();

     glm::vec3 const& getCenter() const;
     float const& getRadius() const;

    float area() const override; //abstrakte M. = rein virtuelle Methode
    float volume() const override;
    
    std::ostream& print(std::ostream& os ) const override;

    bool intersect (Ray const& ray, float& distance) const;

private:
    glm::vec3 center_ ;
    float radius_ ;

};




#endif // define SPHERE_HPP  
