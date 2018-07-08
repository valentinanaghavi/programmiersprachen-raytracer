#include "box.hpp"

#include <iostream>
#include <string>
#include <glm/vec3.hpp>

Box :: Box(glm::vec3 const& min  , glm::vec3 const& max , std::string const& name, Material const& material):
    Shape(name , material),
    min_{min},
    max_{max}
    {};

Box :: Box () :
    Shape(),
    min_{0.0 , 0.0 , 0.0},
    max_{0.0 , 0.0 , 0.0}
    {};

Box :: ~Box()
    {};

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

std::ostream& Box :: print(std::ostream& os ) const
    {
        Shape::print(os);
        os << "area: " << area() << " \n volume: " << volume() << " \n minimum: (" << min_.x << ", " << min_.y << ", " << min_.z << ") \n maximum: (" << max_.x << ", " << max_.y << ", " << max_.z << ")" << " \n";
        
        return os;
    }


bool Box :: intersect( Ray const& ray , float& t ) const 
    {
        float t_x_min;
        float t_x_max;
        float t_y_min;
        float t_y_max;
        float t_z_min;
        float t_z_max;

        if (ray.direction.x >= 0)
        {
            t_x_min = (min_.x -ray.origin.x) / ray.direction.x ;
            t_x_max = (max_.x -ray.origin.x) / ray.direction.x ;
        }
        else
        {
            t_x_min = (max_.x -ray.origin.x) / ray.direction.x ;
            t_x_max = (min_.x -ray.origin.x) / ray.direction.x ;

        }

        if (ray.direction.y >= 0)
        {
            t_y_min = (min_.y -ray.origin.y) / ray.direction.y ;
            t_y_max = (max_.y -ray.origin.y) / ray.direction.y ;
        }
        else
        {
            t_y_min = (max_.y -ray.origin.y) / ray.direction.y ;
            t_y_max = (min_.y -ray.origin.y) / ray.direction.y ;

        }

        if((t_x_min > t_y_max) || (t_y_min > t_x_max))
        {
            return false;
        }
        
        if(t_y_min > t_x_min)
        {
            t_x_min = t_y_min;

        }
        if(t_y_max < t_x_max)
        {
            t_x_max = t_y_max;
            
        }


        if (ray.direction.z >= 0)
        {
            t_z_min = (min_.z -ray.origin.z) / ray.direction.z ;
            t_z_max = (max_.z -ray.origin.z) / ray.direction.z ;
        }
        else
        {
            t_z_min = (max_.z -ray.origin.z) / ray.direction.z ;
            t_z_max = (min_.z -ray.origin.z) / ray.direction.z ;

        }

        if((t_x_min >t_z_max) || (t_z_min > t_x_max))
        {
            return false;
        }

        if(t_z_min > t_x_min)
        {
            t_x_min = t_z_min;
        }
        if(t_z_max < t_x_min)
        {
            t_x_max = t_z_max;
        }

        return((t_x_min < 0 ) && (t_x_max > t));
        }

