#include "shape.hpp"

Shape :: Shape():
    name_{"NoName"},
    material_{Material{}}
    {
       // std::cout << "default C'tor class Shape" << std::endl ;
    };

Shape :: Shape(std::string const& name , Material const& material):
    name_{name},
    material_{material}
    {
       // std::cout << "Constructor class Shape" << std::endl ;
    };

Shape :: ~Shape()
    {
      //  std::cout << "Destructor class Shape" << std::endl ;
    };

std::string Shape :: getName() const
    {
        return name_ ;
    }
Material Shape :: getMaterial() const
    {
        return material_ ;
    }

std::ostream& Shape::print(std::ostream& os) const
	{
		os << "new shape: \n" << "name: " << name_ << " \n Material: " << material_ << "\n";
		return os;
	}

std::ostream& operator<<(std::ostream& os, Shape const& s)
	{
		return s.print(os);
    }

std::ostream& operator<<(std::ostream& os, std::shared_ptr<Shape> const& s)
    {
        return s->print(os);
    }

