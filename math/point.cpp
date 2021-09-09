#include <point.hpp>

/**********************************************************************2D POINT**********************************************************************/

// 2D Point memeber methods definition

template<typename T> Point2<T>::Point2() { x = y = (T)0; }

template<typename T> Point2<T>::Point2(T a) { x = y = a; }

template<typename T> Point2<T>::Point2(T X, T Y) { x = X; y = Y; }

template<typename T> Point2<T>::Point2(const Point2<T> &p) { x = p.x; y = p.y; }

template<typename T> T Point2<T>::operator [] (int i) const {

        assert(i < 2 && i >= 0);
        if(i == 0) return x;
        return y;
}

template<typename T> T &Point2<T>::operator[] (int i) {

        assert(i < 2 && i >= 0);
        if(i == 0) return x;
        return y;
}

template<typename T> Point2<T> Point2<T>::operator - () const {

        return Point2<T>(-x, -y);
}

template<typename T> Point2<T> &Point2<T>::operator += (const Vector2<T> &v) {

        x += v.x; y += v.y;
        return *this;
}

template<typename T> Point2<T> &Point2<T>::operator -= (const Vector2<T> &v) {

        x -= v.x; y -= v.y;
        return *this;
}

/**********************************************************************3D POINT**********************************************************************/

// 3D Point member methods definition

template<typename T> Point3<T>::Point3() { x = y = z = (T)0; }

template<typename T> Point3<T>::Point3(T a) { x = y = z = a; }

template<typename T> Point3<T>::Point3(T X, T Y, T Z) { x = X; y = Y; z = Z; }

template<typename T> Point3<T>::Point3(const Point3<T> &p) { x = p.x; y = p.y; z = p.z; }

template<typename T> T Point3<T>::operator [] (int i) const {

        assert(i < 3 && i >= 0);
        if(i == 0) return x;
        if(i == 1) return y;
        return z;
}

template<typename T> T &Point3<T>::operator[] (int i) {

        assert(i < 3 && i >= 0);
        if(i == 0) return x;
        if(i == 1) return y;
        return z;
}

template<typename T> Point3<T>  Point3<T>::operator - () const {

        return Point3<T>(-x, -y, -z);
}

template<typename T> Point3<T>  &Point3<T>::operator += (const Vector3<T> &v) {

        x += v.x; y += v.y; z += v.z;
        return *this;
}

template<typename T> Point3<T>  &Point3<T>::operator -= (const Vector3<T> &v) {

        x -= v.x; y -= v.y; z -= v.z;
}