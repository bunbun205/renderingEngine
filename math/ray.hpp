#pragma once

#include <point.hpp>

class Ray {

public:
        Ray();
        Ray(const Point3f &origin, const Vector3f &direction) : o(origin), d(direction) { }
        Ray(const Ray &ray) : o(ray.o), d(ray.d) { }

        Point3f origin() const;
        Vector3f direction() const;

        Point3f at(double t);

public:
        Point3f  o;
        Vector3f d;
};