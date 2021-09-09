#pragma once

#include <point.hpp>
#include <ray.hpp>
#include <normal.hpp>
#include <RGBcolor.hpp>

class Material;
class World;

class HitRecord {

public:
        HitRecord(const World &wr);
        HitRecord(const HitRecord &hitrec);

public:
        bool hit;
        std::shared_ptr<Material> matPtr;
        Point3f hitPoint;
        Normal3f normal;
        Ray rHit;
        int depth;
        float t;
        const World& w;
};