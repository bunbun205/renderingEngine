#pragma once

#include <ray.hpp>
#include <RGBcolor.hpp>
#include <hitrec.hpp>

class Material;

class Object {

public:
        Object();

protected:
        HitRecord rec;
};