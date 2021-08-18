#include <camera.hpp>

Camera::Camera() : position(Point3f(0.0, 0.0, 0.0)), lookAt(Point3f(0.0, 0.0, -1.0)), vertical(Vector3f(0.0, 1.0, 0.0)){

        setLocalAxes();
}

Camera::Camera(Point3f pos, Point3f la) : position(pos), lookAt(la), vertical(0.0, 1.0, 0.0) {

        setLocalAxes();
}

void Camera::setPosition(Point3f p) {

        position = p;
}

void Camera::setPosition(double x, double y, double z) {

        position = Point3f(x, y, z);
}

void Camera::setLookAt(Point3f p) {

        lookAt = p;
}

void Camera::setLookAt(double x, double y, double z) {

        lookAt = Point3f(x, y, z);
}

void Camera::setLocalAxes() {

        zAxis = position - lookAt;
        zAxis = normalize(zAxis);
        xAxis = cross(zAxis, vertical);
        xAxis = normalize(xAxis);
        yAxis = cross(zAxis, xAxis);
}
