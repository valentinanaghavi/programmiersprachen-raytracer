#define CATCH_CONFIG_RUNNER

#include <catch.hpp>

#include <glm/vec3.hpp>
#include <cmath>
#include <string>

#include<glm/glm.hpp>
#include<glm/gtx/intersect.hpp>

#include "../framework/sphere.hpp"
#include "../framework/material.hpp"
#include "../framework/scene.hpp"
#include "../framework/box.hpp"
#include "../framework/color.hpp"
#include "../framework/Ray.hpp"
/*
//aufgabe 5.2 + 5.3
TEST_CASE("general_methods_Box_Sphere" , "[ShapeMethods]")
  {
      glm::vec3 center {5.0 , 5.0 , 5.0} ;
      glm::vec3 min {2.0 ,0.0 , 0.0} ;
      glm::vec3 max {50.0 , 10.0 , 3.0};
      float radius {5.0f};
      Color color {0.0f , 1.0f , 0.0f};

      Sphere sphere1{center,radius,"Kugel",color};
      Sphere sphere2{};
      Box box1{min,max,"Box" , color};
      Box box2{};

    SECTION("constructor")
    {
      REQUIRE(sphere1.getCenter().x==center.x); 
      REQUIRE(sphere1.getCenter().y==center.y);
      REQUIRE(sphere1.getCenter().z==center.z);
      REQUIRE(sphere1.getRadius()==5.0f);
      REQUIRE(sphere1.getColor().r==0.0f);
      REQUIRE(sphere1.getColor().g==1.0f);
      REQUIRE(sphere1.getColor().b==0.0f);
      REQUIRE(sphere1.getName().compare("Kugel")==0.0);

      REQUIRE(sphere2.getCenter().x== 0.0); 
      REQUIRE(sphere2.getCenter().y== 0.0);
      REQUIRE(sphere2.getCenter().z== 0.0);
      REQUIRE(sphere2.getRadius()==0.0f);
      REQUIRE(sphere2.getColor().r==0.0f);
      REQUIRE(sphere2.getColor().g==0.0f);
      REQUIRE(sphere2.getColor().b==0.0f);
      REQUIRE(sphere2.getName().compare("NoName")==0.0);

      REQUIRE(box1.getMin().x==min.x);
      REQUIRE(box1.getMin().y==min.y);
      REQUIRE(box1.getMin().z==min.z);
      REQUIRE(box1.getMax().x==max.x);
      REQUIRE(box1.getMax().y==max.y);
      REQUIRE(box1.getMax().z==max.z);
      REQUIRE(box1.getName().compare("Box")==0.0);
      REQUIRE(box1.getColor().r==0.0f);
      REQUIRE(box1.getColor().g==1.0f);
      REQUIRE(box1.getColor().b==0.0f);

      REQUIRE(box2.getMin().x==0.0);
      REQUIRE(box2.getMin().y==0.0);
      REQUIRE(box2.getMin().z==0.0);
      REQUIRE(box2.getMax().x==0.0);
      REQUIRE(box2.getMax().y==0.0);
      REQUIRE(box2.getMax().z==0.0);
      REQUIRE(box2.getName().compare("NoName")==0.0);
      REQUIRE(box2.getColor().r==0.0f);
      REQUIRE(box2.getColor().g==0.0f);
      REQUIRE(box2.getColor().b==0.0f);

    }

    SECTION("volume")
    {
      REQUIRE(sphere1.volume() == Approx(523.5987756f));
      REQUIRE(sphere2.volume() == Approx(0.0f));
      REQUIRE(box1.volume() == Approx(1440.0f));
      REQUIRE(box2.volume() == Approx(0.0f));
    }

    SECTION("area")
    {
      REQUIRE(sphere1.area() == Approx(314.1592654f));
      REQUIRE(sphere2.area() == Approx(0.0f));
      REQUIRE(box1.area() == Approx(1308.0f));
      REQUIRE(box2.area() == Approx(0.0f));
    }
  }
//aufgabe5.5
TEST_CASE( "print_and_operator<<" , "[Shape]")
  {
      glm::vec3 center {5.0 , 5.0 , 5.0} ;
      glm::vec3 min {2.0 ,0.0 , 0.0} ;
      glm::vec3 max {50.0 , 10.0 , 3.0};
      float radius {5.0f};
      Color color {0.0f , 1.0f , 0.0f};

      Sphere sphere1{center,radius,"Kugel",color};
      Sphere sphere2{};
      Box box1{min,max,"Box" , color};


      std::cout<<sphere1<<"\n";
      std::cout<<box1<<"\n";
      std::cout<<sphere2<<"\n";

  }

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

    
    glm::vec3 center3{0.0,0.0,2.0};
    float radius3{0.5f};
    Color color{1.0f,1.0f,1.0f};
    Sphere sphere3{center3,radius3,"Kugel 2",color};
    float distance_2 = 0.0f;

    REQUIRE(!sphere3.intersect(Ray{},distance_2));

    glm::vec3 center4{0.0,0.0, -2.0};
    float radius4{2.0f};
    Sphere sphere4{center4,radius4,"Kugel 3",color};
    float distance_3 = 0.0f ;

    REQUIRE(sphere4.intersect(Ray{},distance_3));
}

//aufgabe 5.8
TEST_CASE("virtual_destructor" , "[virtual]")
  {
    std::cout << "<<<<<<<<<Aufgabe 5.8 >>>>>>>>>>>\n";
    Color red{255,0,0};
    glm::vec3 position{0.0f, 0.0f, 0.0f };

    Sphere* s1 = new Sphere{position, 1.2f, " sphere0 " , red};
    Shape* s2 = new Sphere{position,1.2f,"sphere1", red};

    s1->print(std::cout);
    s2->print(std::cout);

    delete s1 ;
    delete s2 ;
  }

TEST_CASE("aufgabe 5.7" , "[dynamischStatisch]")
{
  std::cout << "<<<<<<<<<Aufgabe 5.7 >>>>>>>>>>>\n";
  Color red {255 , 0 , 0};
  glm::vec3 position {0.0f , 0.0f , 0.0f };
  std::shared_ptr<Sphere>s1= std::make_shared<Sphere>( position , 1.2f , " sphere0 ", red );
  std::shared_ptr<Shape>s2 = std::make_shared<Sphere>( position , 1.2f , " sphere1 ", red  );
  s1->print(std::cout);
  s2->print(std::cout);
}


TEST_CASE("aufgabe 6.3" , "[intersectRayBox]")
{
  glm::vec3 min3 {-2.0 ,0.0 , 0.0} ;
  glm::vec3 min4 {2.0 ,0.0 , 0.0} ;
  glm::vec3 max {50.0 , 10.0 , 3.0};
  Material material{};
  float t = 50.0f;
  Box box3{min3,max,"Box" , material};
  Box box4{min4,max,"Box" , material};

  REQUIRE(box3.intersect(Ray{},t));
  REQUIRE(!box4.intersect(Ray{},t));
  Material m{};
  m.print(std::cout);
  std::cout<<m<<"\n";
}  
*/

TEST_CASE("aufgabe6.5", "[sceneSDF]")
{
  std::shared_ptr<Scene>scene = std::make_shared<Scene>();
  read_sdf("/home/valentina/programmiersprachen-raytracer/source/example.txt" , *scene);
  //search_map("red", scene);
 // search_set("blue", scene);
 // search_vector("green", scene);

  std::cout << "material green: " ;
  if(find_material("green", *scene)==0) 
  std::cout << "green"; 
  std::cout << "\n";

  REQUIRE(find_material("pink",*scene) == nullptr);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}



