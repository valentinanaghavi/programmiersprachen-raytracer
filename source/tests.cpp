#define CATCH_CONFIG_RUNNER

#include <catch.hpp>

#include <glm/vec3.hpp>
#include <cmath>

#include<glm/glm.hpp>
#include<glm/gtx/intersect.hpp>

#include "../framework/sphere.hpp"
#include "../framework/box.hpp"
#include "../framework/color.hpp"

TEST_CASE( "intersect_ray_sphere" , "[intersect]")
  {
    // Ray
    glm::vec3 ray_origin{0.0f , 0.0f , 0.0f };1
    // ray direction has to be normalized !
    // you can use :
    //
    v = glm :: normalize ( some_vector )
    glm :: vec3 ray_direction {0.0 f , 0.0 f , 1.0 f };

    // Sphere
    glm :: vec3 sphere_center {0.0 f ,0.0 f , 5.0 f };
    float sphere_radius {1.0 f };

    float distance = 0.0 f ;

    auto result = glm::intersectRaySphere (
    ray_origin , ray_direction ,
    sphere_center ,
    sphere_radius * sphere_radius , // squared radius !!!
    distance );

    REQUIRE ( distance == Approx (4.0 f ));
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
