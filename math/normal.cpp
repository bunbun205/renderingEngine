#include <normal.hpp>

// 3D Normal member methods definition

template<typename T> Normal3<T>::Normal3() { x = y = z = (T)0; }

template<typename T> Normal3<T>::Normal3(T a) { x = y = z = a; }

template<typename T> Normal3<T>::Normal3(T X, T Y, T Z) { x = X; y = Y; z = Z; }

template<typename T> Normal3<T>::Normal3(const Normal3 &n) { x = n.x; y = n.y; z = n.z; }

template<typename T> T Normal3<T>::operator [] (int i) const {

        assert(i >= 0 && i <= 2);
        if(i == 0) return x;
        if(i == 1) return y;
        return z;
}

template<typename T> T &Normal3<T>::operator[] (int i) {

        assert(i >= 0 && i <= 2);
        if(i == 0) return x;
        if(i == 1) return y;
        return z;
}

template<typename T> Normal3<T> Normal3<T>::operator - () const {

        return Normal3<T>(-x, -y, -z);
}

template<typename T> Normal3<T> &Normal3<T>::operator += (const Normal3<T> &n) {

        x += n.x; y += n.y; z += n.z;
        return *this;
}

template<typename T> Normal3<T> &Normal3<T>::operator -= (const Normal3<T> &n) {

        x -= n.x; y -= n.y; z -= n.z;
        return *this;
}

template<typename T> Normal3<T> &Normal3<T>::operator *= (const T s) {

        x *= s; y *= s; z *= s;
        return *this;
}

template<typename T> Normal3<T> &Normal3<T>::operator /= (const T s) {

        return *this *= 1 / s;
}

template<typename T> T Normal3<T>::length() {

        return std::sqrt(lengthSquared());
}

template<typename T> T Normal3<T>::lengthSquared() {

        return x * x + y * y + z * z;
}