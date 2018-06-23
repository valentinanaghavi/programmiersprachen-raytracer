#include "box.hpp"

#include <iostream>

Box :: Box(glm::vec3 const& min  , glm::vec3 const& max ):
    min_{min},
    max_{max}
    {}

Box :: Box () :
    min_{0.0 , 0.0 , 0.0},
    max_{0.0 , 0.0 , 0.0}
    {}

Box :: ~Box()
    {}

glm::vec3 const& Box :: getMax() const //warum const& ??
    {
        return max_ ;
    }

glm::vec3 const& Box :: getMin() const
    {
        return min_ ;
    }

float Box :: area() const //abstrakte M. = rein virtuelle Methode
    {
        glm::vec3 diffVec = max_ - min_ ;
        return 2*( diffVec.x * diffVec.y + diffVec.x * diffVec.z + diffVec.y * diffVec.z) ; //std::abs
    }

float Box :: volume() const
    {
        glm::vec3 diffVec = max_ - min_ ;
        return diffVec.x * diffVec.y * diffVec.z ;
    }

