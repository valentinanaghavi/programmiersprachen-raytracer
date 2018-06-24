#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp" 
#include <iostream>
#include <string>

class Shape //abstrakte Basisklasse
{

public:
    Shape();
    Shape(std::string const& name , Color const& color);
    virtual ~Shape();

    virtual float area() const = 0; //pure virtual -> muss in der abgl. Klasse ueberschrieben werden, um Objekt instanziieren zu koennen , Klasse kann nicht instanziiert werden
    virtual float volume() const = 0; // Methodeninterface wird vererbt, keine Implementierung 

    std::string getName() const;
    Color getColor() const;

    virtual std::ostream& print(std::ostream& os ) const ;
private:
    std::string name_ ;
    Color color_ ;


};

    std::ostream& operator<<(std::ostream& os , Shape const& s) ;

#endif // define SHAPE_HPP 

