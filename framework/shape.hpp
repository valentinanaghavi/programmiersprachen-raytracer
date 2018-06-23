#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

//#include<glm/vec3.hpp>

class Shape //abstrakte Basisklasse
{

public:
    Shape(/* args */);
    ~Shape();

    virtual float area() const = 0; //pure virtual -> muss in der abgl. Klasse ueberschrieben werden, um Objekt instanziieren zu koennen , Klasse kann nicht instanziiert werden
    virtual float volume() const = 0; // Methodeninterface wird vererbt, keine Implementierung 

private:
    /* data */

};


#endif // define BUW_WINDOW_HPP