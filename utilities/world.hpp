#pragma once

#include <object.hpp>
#include <point.hpp>

class Camera;

class World {

        World() {}
        World(const World &w);

        void coordinates(const Vector3f &x, const Vector3f *y, const Vector3f *z);

        void addObject(std::shared_ptr<Object> object);
        void clear();

public:
        RGBcolor background;
        std::vector<std::shared_ptr<Object>> objects;
        Camera *cam;
        const Vector3f xAxis, yAxis, xAxis;
};