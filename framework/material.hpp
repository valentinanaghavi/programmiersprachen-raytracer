#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <string>
#include "color.hpp"

struct Material
{
    //constructors
    Material();
    Material(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float m);
    
    //function
    std::ostream& print(std::ostream& os ) const ;

    //members
    std::string name_;
    Color ka_;
    Color kd_;
    Color ks_;
    float m_;

};
//free function
std::ostream& operator << (std::ostream& os, Material const& material);

#endif //define MATERIAL_HPP