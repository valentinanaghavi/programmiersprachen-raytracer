#include "shape.hpp"
#include <string>
#include <iostream>


Shape :: Shape():
    name_{"NoName"},
    color_{0.0f , 0.0f , 0.0f}
    {
        std::cout << "default C'tor class Shape" << std::endl ;
    };

Shape :: Shape(std::string const& name , Color const& color):
    name_{name},
    color_{color}
    {
        std::cout << "Constructor class Shape" << std::endl ;
    };

Shape :: ~Shape()
    {
        std::cout << "Destructor class Shape" << std::endl ;
    };

std::string Shape :: getName() const
    {
        return name_ ;
    }
Color Shape :: getColor() const
    {
        return color_ ;
    }

std::ostream& Shape::print(std::ostream& os) const
	{
		os << "new shape: \n" << "name: " << name_ << " \n Color: " << color_ << "\n";
		return os;
	}

std::ostream& operator<<(std::ostream& os, Shape const& s)
	{
		return s.print(os);
    }
