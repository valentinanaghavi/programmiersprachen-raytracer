#ifndef BOX_HPP
#define BOX_HPP


#include <iostream>
#include "shape.hpp"

#include <glm/vec3.hpp>

class Box : public Shape
{
public:
    Box (glm::vec3 const& min , glm::vec3 const& max);
    Box();
    ~Box();

    glm::vec3 const& getMax() const;
    glm::vec3 const& getMin() const;

    float area() const override; //abstrakte M. = rein virtuelle Methode
    float volume() const override;

private:
    glm::vec3 min_ ;
    glm::vec3 max_ ;
};



#endif // define BOX_HPP 

