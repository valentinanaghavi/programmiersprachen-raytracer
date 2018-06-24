#define CATCH_CONFIG_RUNNER

#include <catch.hpp>

#include <glm/vec3.hpp>
#include <cmath>
#include <string>

#include<glm/glm.hpp>
#include<glm/gtx/intersect.hpp>

#include "../framework/sphere.hpp"
#include "../framework/box.hpp"
#include "../framework/color.hpp"
#include "../framework/Ray.hpp"


//aufgabe 5.6
TEST_CASE( "intersect_ray_sphere" , "[intersect]")
  {
    // Ray
    glm::vec3 ray_origin{0.0f , 0.0f , 0.0f };
    // ray direction has to be normalized !
    // you can use :
    // v = glm :: normalize(some_vector)
 
    glm::vec3 ray_direction {0.0f , 0.0f, 1.0f };

    // Sphere
    glm::vec3 sphere_center {0.0f ,0.0f , 5.0f };
    float sphere_radius {1.0f };

    float distance = 0.0f ;

    auto result = glm::intersectRaySphere (
    ray_origin , ray_direction ,
    sphere_center ,
    sphere_radius * sphere_radius , // squared radius !!!
    distance );

    REQUIRE ( distance == Approx (4.0f ));
}

//aufgabe 5.8
TEST_CASE("virtual_destructor" , "[virtual]")
  {
    Color red{255,0,0};
    glm::vec3 position{0.0f, 0.0f, 0.0f };

    Sphere* s1 = new Sphere{position, 1.2f, " sphere0 " , red};
    Shape* s2 = new Sphere{position,1.2f,"sphere1", red};

    s1->print(std::cout);
    s2->print(std::cout);

    delete s1 ;
    delete s2 ;
  }





int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}



