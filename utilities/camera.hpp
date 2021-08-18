#pragma once

#include <world.hpp>

class Camera {

public:
        Camera();
        Camera(Point3f pos, Point3f la);

        void setPosition(Point3f p);
        void setPosition(double x, double y, double z);
        void setLookAt(Point3f p);
        void setLookAt(double x, double y, double z);
        void setLocalAxes();

protected:
        Point3f position;
        Point3f lookAt;
        Vector3f vertical;
        Vector3f xAxis, yAxis, zAxis;
};