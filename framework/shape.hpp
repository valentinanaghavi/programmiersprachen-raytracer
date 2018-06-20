#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include<glm/vec3.hpp>

class Shape
{

public:
    Shape(/* args */);
    ~Shape();

    virtual void area() const; //pure virtual -> muss in der abgl. Klasse ueberschrieben werden, um Objekt instanziieren zu koennen , Klasse kann nicht instanziiert werden
    virtual void volume() const; // Methodeninterface wird vererbt, keine Implementierung 

private:
    /* data */

};

class Sphere :: public Shape 
{

};

class Box :: public Shape
{

};

#endif // define BUW_WINDOW_HPP