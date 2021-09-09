#include <ray.hpp>


Point3f Ray::origin() const {

        return o;
}

Vector3f Ray::direction() const {

        return d;
}

Point3f Ray::at(double t) {

        return o + t * d;
}