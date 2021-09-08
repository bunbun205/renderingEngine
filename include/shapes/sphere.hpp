#pragma once

#include <object.hpp>

class Sphere : public Object {

public:
        Sphere();
        Sphere(const Point3f center, const double radius);

public:
        Point3f c;
        double  r;
};