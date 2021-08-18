#pragma once

#include <matrix.hpp>

// 3D Normal forward declaration

template<typename T> class Normal3;

/**********************************************************************2D VECTOR**********************************************************************/
template<typename T> class Vector2 {

public:
	Vector2();
	Vector2(T a);
	Vector2(T X, T Y);
	Vector2(const Vector2 &v);

	T operator [] (int i) const;
	T &operator[] (int i);
	Vector2 operator - () const;
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

// 2D Vector inline fuctions definition

template<typename T> inline std::ostream &operator << (std::ostream &out, const Vector2<T> &v) {

        return out << x << ' ' << y;
}

template<typename T> inline Vector2<T> operator + (const Vector2<T> &u, const Vector2<T> &v) {

        return Vector2<T>(u.x + v.x, u.y + v.y);
}

template<typename T> inline Vector2<T> operator - (const Vector2<T> &u, const Vector2<T> &v) {

        return Vector2<T>(u.x - v.x, u.y - v.y);
}

template<typename T> inline Vector2<T> operator * (T s, const Vector2<T> &v) {

        return Vector2<T>(s * v.x, s * v.y);
}

template<typename T> inline Vector2<T> operator * (const Vector2<T> &v, T s) {

        return s * v;
}

template<typename T> inline Vector2<T> operator * (const Vector2<T> &v, Matrix<T, 2> &m) {

        return Vector2<T>(v.x * (m(0, 0) + m(1, 0)), v.y * (m(0, 1) + m(1, 1)));
}

template<typename T> inline Vector2<T> operator * (Matrix<T, 2> &m, const Vector2<T> &v) {

        return Vector2<T>(v.x * (m(0, 0) + m(0, 1)), v.y * (m(1, 0) + m(1, 1)));
}

template<typename T> inline Vector2<T> operator / (const Vector2<T> &v, T s) {

        return (1 / s) * v;
}

template<typename T> inline T dot(const Vector2<T> &u, const Vector2<T> &v) {

        return u.x * v.x + u.y * v.y;
}

template<typename T> inline Vector2<T> normalize(Vector2<T> v) {

        return v / v.length();
}

/**********************************************************************3D VECTOR**********************************************************************/

template<typename T> class Vector3 {

public:
	Vector3();
	Vector3(T a);
	Vector3(T X, T Y, T Z);
	Vector3(const Vector3 &v);
	explicit Vector3(const Normal3<T> &n) { x = n.x; y = n.y; z = n.z; }

	T operator [] (int i) const;
	T &operator[] (int i);
	Vector3 operator - () const;
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

// 3D Vector inline functions definition

template<typename T> inline std::ostream &operator << (std::ostream &out, const Vector3<T> &v) {

        return out << v.x << ' ' << v.y << ' ' << v.z;
}

template<typename T> inline Vector3<T> operator + (const Vector3<T> &u, const Vector3<T> &v) {

        return Vector3<T>(u.x + v.x, u.y + v.y, u.z + v.z);
}

template<typename T> inline Vector3<T> operator - (const Vector3<T> &u, const Vector3<T> &v) {

        return Vector3<T>(u.x - v.x, u.y - v.y, u.z - v.z);
}

template<typename T> inline Vector3<T> operator * (T s, const Vector3<T> &v) {

        return Vector3<T>(s * v.x, s * v.y, s * v.z);
}

template<typename T> inline Vector3<T> operator * (const Vector3<T> &v, T s) {

        return s * v;
}

template<typename T> inline Vector3<T> operator * (const Vector3<T> &v, Matrix<T, 3> &m) {

        return Vector2<T>(v.x * (m(0, 0) + m(1, 0 + m(2, 0))), v.y * (m(0, 1) + m(1, 1) + m(2, 1)), v.z * (m(0, 2) + m(1, 2) + m(2, 2)));
}

template<typename T> inline Vector2<T> operator * (Matrix<T, 2> &m, const Vector2<T> &v) {

        return Vector2<T>(v.x * (m(0, 0) + m(0, 1) + m(0, 2)), v.y * (m(1, 0) + m(1, 1) + m(1, 2)), v.z * (m(2, 0) + m(2, 1) + m(2, 2)));
}

template<typename T> inline Vector3<T> operator / (const Vector3<T> &v, T s) {

        return (1 / s) * v;
}

template<typename T> inline T dot(const Vector3<T> &u, const Vector3<T> &v) {

        return u.x * v.x + u.y * v.y + u.z * v.z;
}

template<typename T> inline Vector3<T> cross(const Vector3<T> &u, const Vector3<T> &v) {

        return Vector3<T>(u.y * v.z - u.z * v.y,
                          u.z * v*x - u.x * v.z,
                          u.x * v.y - u.y * v.x);
}

template<typename T> inline Vector3<T> normalize(Vector3<T> v) {

        return v / v.length();
}