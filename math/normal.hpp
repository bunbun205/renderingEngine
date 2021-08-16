#pragma once

#include <vector.hpp>

template <typename T>class Normal3 {

public:
        Normal3();
	Normal3(T a);
	Normal3(T X, T Y, T Z);
	Normal3(const Vector3 &v);

	T operator [] (int i) const;
	T &operator[] (int i);
	Normal3 operator - () const;
	Normal3 &operator += (const Vector3<T> &v);
	Normal3 &operator -= (const Vector3<T> &v);
	Normal3 &operator *= (const T s);
	Normal3 &operator /= (const T s);
	T length();
	T lengthSquared();

public:
        T x, y, z;
};