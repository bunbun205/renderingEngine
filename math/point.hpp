#pragma once

#include <vector.hpp>

/**********************************************************************2D POINT**********************************************************************/

template <typename T> class Point2 {

public:
        Point2();
        Point2(T a);
        Point2(T X, T Y);
        Point2(const Point2<T> &p);
        explicit Point2(const Point3<T> &p) { x = p.x; y = p.y; }

        T operator [] (int i) const;
	T &operator[] (int i);
        Point2 operator - () const;
        Point2 &operator += (const Vector2<T> &v);
	Point2 &operator -= (const Vector2<T> &v);

public:
        T x, y;
};

// 2D Point aliases

typedef Point2<double> Point2f;
typedef Point2<int>    Point2i;

// 2D Point inline functions

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

template <typename T> class Point3 {

public:
        Point3();
        Point3(T a);
        Point3(T X, T Y, T Z);
        Point3(const Point3<T> &p);

        T operator [] (int i) const;
	T &operator[] (int i);
        Point3 operator - ()const;
        Point3 &operator += (const Vector3<T> &v);
	Point3 &operator -= (const Vector3<T> &v);

public:
        T x, y, z;
};

// 3D Point aliases

typedef Point3<double> Point3f;
typedef Point3<int>    Point3i;

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