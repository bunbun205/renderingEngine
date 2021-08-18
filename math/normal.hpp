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

// 3D Normal inline functions

template<typename T> inline std::ostream &operator << (std::ostream &out, const Normal3<T> &n) {

        return out << n.x << ' ' << n.y << ' ' << n.z;
}

template<typename T> inline Vector3<T> operator + (const Normal3<T> &n, const Vector3<T> &v) {

        return Vector3<T>(n.x + v.x, n.y + v.y, n.z + v.z);
}

template<typename T> inline Vector3<T> operator + (const Vector3<T> &v, const Normal3<T> &n) {

        return n + v;
}

template<typename T> inline Vector3<T> operator - (const Normal3<T> &n, const Vector3<T> &v) {

        return Vector3<T>(n.x - v.x, n.y - v.y, n.z - v.z);
}

template<typename T> inline Vector3<T> operator - (const Vector3<T> &v, const Normal3<T> &n) {

        return Vector3<T>(v.x - n.x, v.y - n.y, v.z - n.z);
}

template<typename T> inline Normal3<T> operator * (T s, const Normal3<T> &n) {

        return Normal3<T>(s * n.x, s * n.y, s * n.z);
}

template<typename T> inline Normal3<T> operator * (const Normal3<T> &n, T s) {

        return s * n;
}

template<typename T> inline Normal3<T> operator / (const Normal3<T> &n, T s) {

        return (1 / s) * n;
}

template<typename T> inline T dot(const Normal3<T> &n, const Vector3<T> &v) {

        return n.x * v.x + n.y * v.y + n.z * v.z;
}

template<typename T> inline Vector3<T> cross(const Normal3<T> &n, const Vector3<T> &v) {

        return Vector3<T>(n.y * v.z - n.z * v.y,
                          n.z * v*x - n.x * v.z,
                          n.x * v.y - n.y * v.x);
}

template<typename T> inline T dot(const Vector3<T> &v, const Normal3<T> &n) {

        return dot(n, v);
}

template<typename T> inline Vector3<T> cross(const Vector3<T> &v, const Normal3<T> &n) {

        return -cross(n, v);
}

template<typename T> inline Normal3<T> normalize(Normal3<T> n) {

        return n / n.length();
}

template<typename T> inline Normal3<T> faceForward(const Normal3<T> &n, const Vector3<T> &v) {

        return (dot(n, v) < 0.T) ? -n : n;
}