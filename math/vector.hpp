#pragma once

#include <matrix.hpp>

/**********************************************************************2D VECTOR**********************************************************************/
template<typename T> class Vector2 {

public:
	Vector2();
	Vector2(T a);
	Vector2(T X, T Y);
	Vector2(const Vector2 &v);

	T operator [] (int i) const;
	T &operator[] (int i);
	Vector2 &operator += (const Vector2<T> &v);
	Vector2 &operator -= (const Vector2<T> &v);
	Vector2 &operator *= (const T s);
	Vector2 &operator /= (const T s);
	T length();
	T lengthSquared();

public:
	T x, y;
};

// 2D Vector aliases

typedef Vector2<double> Vector2f;
typedef Vector2<int>    Vector2i;

// 2D Vector inline function prototypes

template<typename T> std::ostream &operator << (std::ostream &out, const Vector2<T> &v);
template<typename T> Vector2<T> operator + (const Vector2<T> &u, const Vector2<T> &v);
template<typename T> Vector2<T> operator - (const Vector2<T> &u, const Vector2<T> &v);
template<typename T> Vector2<T> operator * (T s, const Vector2<T> &v);
template<typename T> Vector2<T> operator * (const Vector2<T> &v, T s);
template<typename T> Vector2<T> operator * (const Vector2<T> &v, Matrix<T, 2> &m);
template<typename T> Vector2<T> operator * (Matrix<T, 2> &m, const Vector2<T> &v);
template<typename T> Vector2<T> operator / (const Vector2<T> &v, T s);
template<typename T> T dot(const Vector2<T> &u, const Vector2<T> &v);
template<typename T> Vector2<T> cross(const Vector2<T> &u, const Vector2<T> &v);
template<typename T> Vector2<T> normalize(Vector2<T> v);

/**********************************************************************3D VECTOR**********************************************************************/

template<typename T> class Vector3 {

public:
	Vector3();
	Vector3(T a);
	Vector3(T X, T Y, T Z);
	Vector3(const Vector3 &v);

	T operator [] (int i) const;
	T &operator[] (int i);
	Vector3 &operator += (const Vector3<T> &v);
	Vector3 &operator -= (const Vector3<T> &v);
	Vector3 &operator *= (const T s);
	Vector3 &operator /= (const T s);
	T length();
	T lengthSquared();

public:
	T x, y, z;
};

// 3D Vector aliases

typedef Vector3<double> Vector3f;
typedef Vector3<int>    Vector3i;

// 3D Vector inline function prototypes

template<typename T> std::ostream &operator << (std::ostream &out, const Vector3<T> &v);
template<typename T> Vector3<T> operator + (const Vector3<T> &u, const Vector3<T> &v);
template<typename T> Vector3<T> operator - (const Vector3<T> &u, const Vector3<T> &v);
template<typename T> Vector3<T> operator * (T s, const Vector3<T> &v);
template<typename T> Vector3<T> operator * (const Vector3<T> &v, T s);
template<typename T> Vector3<T> operator * (const Vector3<T> &v, Matrix<T, 3> &m);
template<typename T> Vector3<T> operator * (Matrix<T, 3> &m, const Vector3<T> &v);
template<typename T> Vector3<T> operator / (const Vector3<T> &v, T s);
template<typename T> T dot(const Vector3<T> &u, const Vector3<T> &v);
template<typename T> Vector3<T> cross(const Vector3<T> &u, const Vector3<T> &v);
template<typename T> Vector3<T> normalize(Vector3<T> v);