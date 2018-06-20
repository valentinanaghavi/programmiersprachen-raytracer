#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

#include<glm/vec3.hpp>

#include "shape.hpp"

class Box :: public Shape
{
public:
    Box(glm::vec3 min &const , glm::vec3 max &const);
    Box();
    ~Box();

    getMax(glm::vec3 min &const);
    getMin(glm::vec3 max &const);

    void area() const override; //abstrakte M. = rein virtuelle Methode
    void volume() const override;

private:
    glm::vec3 min_ ;
    glm::vec3 max_ ;
};



#endif // define BUW_BOX_HPP