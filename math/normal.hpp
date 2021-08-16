#pragma once

#include <vector.hpp>

template <typename T>class Normal3 {

public:
        Normal3();
	Normal3(T a);
	Normal3(T X, T Y, T Z);
	Normal3(const Normal3<T> &n);
        explicit Normal3(const Vector3<T> &v) { x = v.x; v = v.y; z = v.z; }

	T operator [] (int i) const;
	T &operator[] (int i);
	Normal3 operator - () const;
        Normal3 &operator += (const Normal3<T> &n);
	Normal3 &operator -= (const Normal3<T> &n);
	Normal3 &operator *= (const T s);
	Normal3 &operator /= (const T s);
	T length();
	T lengthSquared();

public:
        T x, y, z;
};

// 3D Normal aliases

typedef Normal3<double> Normal3f;
typedef Normal3<int>    Normal3i;

// 3D Normal inline function prototypes

template<typename T> std::ostream &operator << (std::ostream &out, const Normal3<T> &n);
template<typename T> Vector3<T> operator + (const Normal3<T> &n, const Vector3<T> &v);
template<typename T> Vector3<T> operator + (const Vector3<T> &v, const Normal3<T> &n);
template<typename T> Vector3<T> operator - (const Normal3<T> &n, const Vector3<T> &v);
template<typename T> Vector3<T> operator - (const Vector3<T> &v, const Normal3<T> &n);
template<typename T> Normal3<T> operator * (T s, const Normal3<T> &n);
template<typename T> Normal3<T> operator * (const Normal3<T> &n, T s);
template<typename T> Normal3<T> operator / (const Normal3<T> &n, T s);
template<typename T> T dot(const Normal3<T> &n, const Vector3<T> &v);
template<typename T> Vector3<T> cross(const Normal3<T> &n, const Vector3<T> &v);
template<typename T> T dot(const Vector3<T> &v, const Normal3<T> &n);
template<typename T> Vector3<T> cross(const Vector3<T> &v, const Normal3<T> &n);
template<typename T> Normal3<T> normalize(Normal3<T> n);
template<typename T> Normal3<T> faceForward(const Normal3<T> &n, const Vector3<T> &v);