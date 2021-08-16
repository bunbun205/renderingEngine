#include <point.hpp>

/**********************************************************************2D POINT**********************************************************************/

// 2D Point memeber methods definition

template<typename T> inline Point2<T>::Point2() { x = y = (T)0; }

template<typename T> inline Point2<T>::Point2(T a) { x = y = a; }

template<typename T> inline Point2<T>::Point2(T X, T Y) { x = X; y = Y; }

template<typename T> inline Point2<T>::Point2(const Point2<T> &p) { x = p.x; y = p.y; }

template<typename T> inline T Point2<T>::operator [] (int i) const {

        assert(i < 2 && i >= 0);
        if(i == 0) return x;
        return y;
}

template<typename T> inline T &Point2<T>::operator[] (int i) {

        assert(i < 2 && i >= 0);
        if(i == 0) return x;
        return y;
}

template<typename T> inline Point2<T> Point2<T>::operator - () const {

        return Point2<T>(-x, -y);
}

template<typename T> inline Point2<T> &Point2<T>::operator += (const Vector2<T> &v) {

        x += v.x; y += v.y;
        return *this;
}

template<typename T> inline Point2<T> &Point2<T>::operator -= (const Vector2<T> &v) {

        x -= v.x; y -= v.y;
        return *this;
}

// 2D Point inline functions definition

template<typename T> inline std::ostream &operator << (std::ostream &out, const Point2<T> &p) {

        return out << x << ' ' << y;
}

template<typename T> inline Point2<T> operator + (const Point2<T> p, const Vector2<T> v) {

        return Point2<T>(p.x + v.x, p.y + v.y);
}

template<typename T> inline Point2<T> operator - (const Point2<T> p, const Vector2<T> v) {

        return Point2<T>(p.x - v.x, p.y - v.y);
}

template<typename T> inline Vector2<T> operator - (const Point2<T> p1, const Point2<T> p2) {

        return Vector2<T>(p1.x - p2.x, p1.y - p2.y);
}

template<typename T> inline T distance(const Point2<T> &p1, const Point2<T> &p2) {

        return (p1 - p2).length();
}

template<typename T> inline T distanceSquared(const Point2<T> &p1, const Point2<T> &p2) {

        return (p1 - p2).lengthSquared();
}

template<typename T> inline Point2<T> Lerp(T t, const Point2<T> &p1, const Point2<T> &p2) {

        return Point2<T>((1 - t) * p1.x + t * p2.x, (1 - t) * p1.y + t * p2.y);
}

template<typename T> inline Point2<T> Max(const Point2<T> &p1, const Point2<T> &p2) {

        return Point2<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y));
}

template<typename T> inline Point2<T> Min(const Point2<T> &p1, const Point2<T> &p2) {

        return Point2<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y));
}

template<typename T> inline Point2<T> Floor(const Point2<T> &p) {

        return Point2<T>(std::floor(p.x), std::floor(p.y));
}

template<typename T> inline Point2<T> Ceil(const Point2<T> &p) {

        return Point2<T>(std::ceil(p.x), std::ceil(p.y));
}

template<typename T> inline Point2<T> Abs(const Point2<T> &p) {

        return Point2<T>(std::abs(p.x), std::abs(p.y));
}

/**********************************************************************3D POINT**********************************************************************/

// 3D Point member methods definition

template<typename T> inline Point3<T>::Point3() { x = y = z = (T)0; }

template<typename T> inline Point3<T>::Point3(T a) { x = y = z = a; }

template<typename T> inline Point3<T>::Point3(T X, T Y, T Z) { x = X; y = Y; z = Z; }

template<typename T> inline Point3<T>::Point3(const Point3<T> &p) { x = p.x; y = p.y; z = p.z; }

template<typename T> inline T Point3<T>::operator [] (int i) const {

        assert(i < 3 && i >= 0);
        if(i == 0) return x;
        if(i == 1) return y;
        return z;
}

template<typename T> inline T &Point3<T>::operator[] (int i) {

        assert(i < 3 && i >= 0);
        if(i == 0) return x;
        if(i == 1) return y;
        return z;
}

template<typename T> inline Point3<T>  Point3<T>::operator - () const {

        return Point3<T>(-x, -y, -z);
}

template<typename T> inline Point3<T>  &Point3<T>::operator += (const Vector3<T> &v) {

        x += v.x; y += v.y; z += v.z;
        return *this;
}

template<typename T> inline Point3<T>  &Point3<T>::operator -= (const Vector3<T> &v) {

        x -= v.x; y -= v.y; z -= v.z;
}

// 3D Point inline functions definition

template<typename T> inline std::ostream &operator << (std::ostream &out, const Point3<T> &p) {

        return out << p.x << ' ' << p.y << ' ' << p.z;
}

template<typename T> inline Point3<T> operator + (const Point3<T> p, const Vector3<T> v) {

        return Point3<T>(p.x + v.x, p.y + v.y, p.z + v.z);
}

template<typename T> inline Point3<T> operator - (const Point3<T> p, const Vector3<T> v) {

        return Point3<T>(p.x - v.x, p.y - v.y, p.z - v.z);
}

template<typename T> inline Vector3<T> operator - (const Point3<T> p1, const Point3<T> p2) {

        return Vector3<T>(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
}

template<typename T> inline T distance(const Point3<T> &p1, const Point3<T> &p2) {

        return (p1 - p2).length();
}

template<typename T> inline T distanceSquared(const Point3<T> &p1, const Point3<T> &p2) {

        return (p1 - p2).lengthSquared();
}

template<typename T> inline Point3<T> Lerp(T t, const Point3<T> &p1, const Point3<T> &p2) {

        return Point3<T>((1 - t) * p1.x + t * p2.x, (1 - t) * p1.y + t * p2.y, (1 - t) * p1.z + t * p2.z);
}

template<typename T> inline Point3<T> Max(const Point3<T> &p1, const Point3<T> &p2) {

        return Point3<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z))
}

template<typename T> inline Point3<T> Min(const Point3<T> &p1, const Point3<T> &p2) {

        return Point3<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y), std::min(p1.z, p2.z))
}

template<typename T> inline Point3<T> Floor(const Point3<T> &p) {

        return Point3<T>(std::floor(p.x), std::floor(p.y), std::floor(p.z));
}

template<typename T> inline Point3<T> Ceil(const Point3<T> &p) {

        return Point3<T>(std::ceil(p.x), std::ceil(p.y), std::ceil(p.z));
}

template<typename T> inline Point3<T> Abs(const Point3<T> &p) {

        return Point3<T>(std::abs(p.x), std::abs(p.y), std::abs(p.z));
}