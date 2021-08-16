#include <normal.hpp>

// 3D Normal member methods definition

template<typename T> inline Normal3<T>::Normal3() { x = y = z = (T)0; }

template<typename T> inline Normal3<T>::Normal3(T a) { x = y = z = a; }

template<typename T> inline Normal3<T>::Normal3(T X, T Y, T Z) { x = X; y = Y; z = Z; }

template<typename T> inline Normal3<T>::Normal3(const Normal3 &n) { x = n.x; y = n.y; z = n.z; }

template<typename T> inline T Normal3<T>::operator [] (int i) const {

        assert(i >= 0 && i <= 2);
        if(i == 0) return x;
        if(i == 1) return y;
        return z;
}

template<typename T> inline T &Normal3<T>::operator[] (int i) {

        assert(i >= 0 && i <= 2);
        if(i == 0) return x;
        if(i == 1) return y;
        return z;
}

template<typename T> inline Normal3<T> Normal3<T>::operator - () const {

        return Normal3<T>(-x, -y, -z);
}

template<typename T> inline Normal3<T> &Normal3<T>::operator += (const Normal3<T> &n) {

        x += n.x; y += n.y; z += n.z;
        return *this;
}

template<typename T> inline Normal3<T> &Normal3<T>::operator -= (const Normal3<T> &n) {

        x -= n.x; y -= n.y; z -= n.z;
        return *this;
}

template<typename T> inline Normal3<T> &Normal3<T>::operator *= (const T s) {

        x *= s; y *= s; z *= s;
        return *this;
}

template<typename T> inline Normal3<T> &Normal3<T>::operator /= (const T s) {

        return *this *= 1 / s;
}

template<typename T> inline T Normal3<T>::length() {

        return std::sqrt(lengthSquared());
}

template<typename T> inline T Normal3<T>::lengthSquared() {

        return x * x + y * y + z * z;
}

// 3D Normal inline functions definition

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