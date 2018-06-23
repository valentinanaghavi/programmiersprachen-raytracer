#include "shape.hpp"
#include <string>

Shape :: Shape(std::string const& name , Color const& color):
    name_{name},
    color_{color}
    {}

Shape :: Shape():
    name_{"no name"},
    color_{0.0f , 0.0f , 0.0f}
    {}

Shape :: ~Shape()
    {}

std::string Shape :: getName() const
    {
        return name_ ;
    }
Color Shape :: getColor() const
    {
        return color_ ;
    }