#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include "color.hpp" 
class Shape //abstrakte Basisklasse
{

public:
    Shape(std::string const& name , Color const& color);
    Shape();
    ~Shape();

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

#endif // define BUW_WINDOW_HPP