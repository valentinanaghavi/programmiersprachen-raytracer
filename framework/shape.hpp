#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp" 
#include "Ray.hpp"
#include "material.hpp"

#include <iostream>
#include <string>
#include <memory> //manage dynamic shared_ptr

class Shape //abstrakte Basisklasse
{

public:
    Shape();
    Shape(std::string const& name , Material const& material);
    virtual ~Shape();
    //~Shape();

    virtual float area() const = 0; //pure virtual -> muss in der abgl. Klasse ueberschrieben werden, um Objekt instanziieren zu koennen , Klasse kann nicht instanziiert werden
    virtual float volume() const = 0; // Methodeninterface wird vererbt, keine Implementierung 

    std::string getName() const;
    Material getMaterial() const;

    virtual std::ostream& print(std::ostream& os ) const ;

    //aufgabe 6.3
    virtual bool intersect ( Ray const& ray , float& t ) const = 0;

private:
    std::string name_ ;
    Material material_ ;


};

    std::ostream& operator<<(std::ostream& os , Shape const& s) ;
    std::ostream& operator<<(std::ostream& os , std::shared_ptr<Shape> const& s) ;

#endif // define SHAPE_HPP 

