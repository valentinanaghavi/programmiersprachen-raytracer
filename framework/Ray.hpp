#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>

struct Ray
{

glm::vec3 origin = {0.0 f , 0.0 f , 0.0 f };
glm::vec3 direction = {0.0 f , 0.0 f , -1.0 f };

};

#endif //define RAY_HPP