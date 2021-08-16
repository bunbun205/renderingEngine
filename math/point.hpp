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
        Point2 &operator - ();
        Point2 &operator += (const Vector2<T> &v);
	Point2 &operator -= (const Vector2<T> &v);

public:
        T x, y;
};

// 2D Point aliases

typedef Point2<double> Point2f;
typedef Point2<int>    Point2i;

// 2D Point inline function prototypes

template<typename T> std::ostream &operator << (std::ostream &out, const Point2<T> &p);
template<typename T> Point2<T> operator + (const Point2<T> p, const Vector2<T> v);
template<typename T> Point2<T> operator - (const Point2<T> p, const Vector2<T> v);
template<typename T> Vector2<T> operator - (const Point2<T> p1, const Point2<T> p2);
template<typename T> T distance(const Point2<T> &p1, const Point2<T> &p2);
template<typename T> T distanceSquared(const Point2<T> &p1, const Point2<T> &p2);
template<typename T> Point2<T> Lerp(T t, const Point2<T> &p1, const Point2<T> &p2);
template<typename T> Point2<T> Max(const Point2<T> &p1, const Point2<T> &p2);
template<typename T> Point2<T> Min(const Point2<T> &p1, const Point2<T> &p2);
template<typename T> Point2<T> Floor(const Point2<T> &p);
template<typename T> Point2<T> Ceil(const Point2<T> &p);
template<typename T> Point2<T> Abs(const Point2<T> &p);

/**********************************************************************3D POINT**********************************************************************/

template <typename T> class Point3 {

public:
        Point3();
        Point3(T a);
        Point3(T X, T Y, T Z);
        Point3(const Point3<T> &p);

        T operator [] (int i) const;
	T &operator[] (int i);
        Point3 &operator - ();
        Point3 &operator += (const Vector3<T> &v);
	Point3 &operator -= (const Vector3<T> &v);

public:
        T x, y, z;
};

// 3D Point aliases

typedef Point3<double> Point3f;
typedef Point3<int>    Point3i;

// 3D Point inline function prototypes

template<typename T> std::ostream &operator << (std::ostream &out, const Point3<T> &p);
template<typename T> Point3<T> operator + (const Point3<T> p, const Vector3<T> v);
template<typename T> Point3<T> operator - (const Point3<T> p, const Vector3<T> v);
template<typename T> Vector3<T> operator - (const Point3<T> p1, const Point3<T> p2);
template<typename T> T distance(const Point3<T> &p1, const Point3<T> &p2);
template<typename T> T distanceSquared(const Point3<T> &p1, const Point3<T> &p2);
template<typename T> Point3<T> Lerp(T t, const Point3<T> &p1, const Point3<T> &p2);
template<typename T> Point3<T> Max(const Point3<T> &p1, const Point3<T> &p2);
template<typename T> Point3<T> Min(const Point3<T> &p1, const Point3<T> &p2);
template<typename T> Point3<T> Floor(const Point3<T> &p);
template<typename T> Point3<T> Ceil(const Point3<T> &p);
template<typename T> Point3<T> Abs(const Point3<T> &p);