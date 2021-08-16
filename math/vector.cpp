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

// 3D Vector inline functions definition

template<typename T> inline std::ostream &operator << (std::ostream &out, const Vector3<T> &v) {

        return out << x << ' ' << y << ' ' << z;
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