#include <vector.hpp>

/**********************************************************************2D VECTOR**********************************************************************/

// 2D Vector member methods definition

template<typename T> inline Vector2<T>::Vector2() { x = y = 0.0; }

template<typename T> inline Vector2<T>::Vector2(T a) { x = y = a; }

template<typename T> inline Vector2<T>::Vector2(T X, T Y) { x = X; y = Y; }

template<typename T> inline Vector2<T>::Vector2(const Vector2 &v) {x = v.x; y = v.y; }

template<typename T> inline T Vector2<T>::operator [] (int i) const {

        assert(i == 0 || i == 1);
        if(i == 0) return x;
        return y;
}

template<typename T> inline T &Vector2<T>::operator[] (int i) {

        assert(i == 0 || i == 1);
        if(i == 0) return x;
        return y;
}

template<typename T> inline Vector2<T> Vector2<T>::operator - () const {

        return Vector3<T>(-x, -y);
}

template<typename T> inline Vector2<T> &Vector2<T>::operator += (const Vector2<T> &v) {

        x += v.x; y += v.y;
        return *this;
}

template<typename T> inline Vector2<T> &Vector2<T>::operator -= (const Vector2<T> &v) {

        x -= v.x; y -= v.y;
        return *this;
}

template<typename T> inline Vector2<T> &Vector2<T>::operator *= (const T s) {

        x *= s; y *= s;
        return *this;
}

template<typename T> inline Vector2<T> &Vector2<T>::operator /= (const T s) {

        return *this *= 1 / s;
}

template<typename T> inline T Vector2<T>::length() {

        return std::sqrt(lengthSquared());
}

template<typename T> inline T Vector2<T>::lengthSquared() {

        return x * x + y * y;
}

/**********************************************************************3D VECTOR**********************************************************************/

// 3D Vector member methods definition

template<typename T> inline Vector3<T>::Vector3() { x = y = z = 0.0; }

template<typename T> inline Vector3<T>::Vector3(T a) { x = y = z = a; }

template<typename T> inline Vector3<T>::Vector3(T X, T Y, T Z) { x = X; y = Y; z = Z; }

template<typename T> inline Vector3<T>::Vector3(const Vector3 &v) { x = v.x; y = v.y; z = v.z; }

template<typename T> inline T Vector3<T>::operator [] (int i) const {

        assert(i >= 0 && i <= 2);
        if(i == 0) return x;
        if(i == 1) return y;
        return z;
}

template<typename T> inline T &Vector3<T>::operator[] (int i) {

        assert(i >= 0 && i <= 2);
        if(i == 0) return x;
        if(i == 1) return y;
        return z;
}

template<typename T> inline Vector3<T> Vector3<T>::operator - () const {

        return Vector3<T>(-x, -y, -z);
}

template<typename T> inline Vector3<T> &Vector3<T>::operator += (const Vector3<T> &v) {

        x += v.x; y += v.y; z += v.z;
        return *this;
}

template<typename T> inline Vector3<T> &Vector3<T>::operator -= (const Vector3<T> &v) {

        x -= v.x; y -= v.y; z -= v.z;
        return *this;
}

template<typename T> inline Vector3<T> &Vector3<T>::operator *= (const T s) {

        x *= s; y *= s; z *= s;
        return *this;
}

template<typename T> inline Vector3<T> &Vector3<T>::operator /= (const T s) {

        return *this *= 1 / s;
}

template<typename T> inline T length() {

        return std::sqrt(lengthSquared());
}

template<typename T> inline T lengthSquared() {

        return x * x + y * y + z * z;
}