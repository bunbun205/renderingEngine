#pragma once

#include <headers.hpp>

// 2D and 3D Vector classes forward declarations

template<typename T> class Vector2;
template<typename T> class Vector3;

// Matrix class declaration

template <typename T, int S> class Matrix {

public:
        Matrix();
        Matrix(T s);
        Matrix(const Matrix<T, S> &m);
        Matrix(const Vector2<T> &v1, const Vector2<T> &v2);
        Matrix(const Vector3<T> &v1, const Vector3<T> &v2, const Vector3<T> &v3);
        Matrix( T m00, T m01, T m02,
                T m10, T m11, T m12,
                T m20, T m21, T m22);
        Matrix( T m00, T m01, T m02, T m03,
                T m10, T m11, T m12, T m13,
                T m20, T m21, T m22, T m23,
                T m30, T m31, T m32, T m33);

        Matrix operator () (int i, int j) const;
        Matrix &operator() (int i, int j);
        Vector2<T> operator () (int i) const;
        Vector2<T> &operator() (int i);
        Vector3<T> operator () (int i) const {

                assert(i == 3);
                return Vector3(matrix[i][0], matrix[i][1], matrix[i][2]);
        }

        Vector3<T> &operator() (int i)  {

                assert(i == 3);
                return Vector3(matrix[i][0], matrix[i][1], matrix[i][2]);
        }
        
        Matrix &operator += (const Matrix<T, S> &m);
        Matrix &operator -= (const Matrix<T, S> &m);
        Matrix &operator *= (const Matrix<T, S> &m);
        Matrix &operator *= (const T s);
        Matrix &operator /= (const T s);

        Matrix identity();

        T trace();
        bool orthoginal();

public:
        T matrix[S][S];
};

// Matrix types definitions

typedef Matrix<double, 3> Matrix3f;
typedef Matrix<double, 4> Matrix4f;
typedef Matrix<int, 3>    Matrix3i;
typedef Matrix<int, 4>    Matrix4i;

// Identity matrices definition

#define Identity3f Matrix3f(1.0, 0.0, 0.0,\
                            0.0, 1.0, 0.0,\
                            0.0, 0.0, 1.0)

#define Identity4f Matrix4f(1.0, 0.0, 0.0, 0.0,\
                            0.0, 1.0, 0.0, 0.0,\
                            0.0, 0.0, 1.0, 0.0,\
                            0.0, 0.0, 0.0, 1.0)

#define Identity3i Matrix3i(1, 0, 0,\
                            0, 1, 0,\
                            0, 0, 1)

#define Identity3i Matrix3i(1, 0, 0, 0,\
                            0, 1, 0, 0,\
                            0, 0, 1, 0,\
                            0, 0, 0, 1)

// Diagonal matrix definition

#define diagMat3i(s) Matrix3i(s, 0, 0,\
                              0, s, 0,\
                              0, 0, s)

#define diagMat4i(s) Matrix4i(s, 0, 0, 0,\
                              0, s, 0, 0,\
                              0, 0, s, 0,\
                              0, 0, 0, s)

#define diagMat3f(s) Matrix3f(  s, 0.0, 0.0,\
                              0.0,   s, 0.0,\
                              0.0, 0.0,   s)

#define diagMat4f(s) Matrix4f(  s, 0.0, 0.0, 0.0,\
                              0.0,   s, 0.0, 0.0,\
                              0.0, 0.0,   s, 0.0,\
                              0.0, 0.0, 0.0,   s)

// Matrix inline function prototypes

template <typename T, int S> std::ostream &operator << (std::ostream& out, const Matrix<T, S> &m);
template <typename T, int S> Matrix<T, S> operator + (const Matrix<T, S> &n, const Matrix<T, S> &m);
template <typename T, int S> Matrix<T, S> operator - (const Matrix<T, S> &n, const Matrix<T, S> &m);
template <typename T, int S> Matrix<T, S> operator * (const Matrix<T, S> &n, const Matrix<T, S> &m);
template <typename T, int S> Matrix<T, S> operator * (const Matrix<T, S> &m, T s);
template <typename T, int S> Matrix<T, S> operator * (T s, const Matrix<T, S> &m);
template <typename T, int S> Matrix<T, S> operator / (const Matrix<T, S> &m, T s);
template <typename T, int S> T determinant(const Matrix<T, S> &m);
template <typename T, int S> Matrix<T, S-1> cofactor(const Matrix<T, S> &m, int x, int y);
template <typename T, int S> Matrix<T, S> transpose(const Matrix<T,S> &m);
template <typename T, int S> Matrix<T, S> adjoint(const Matrix<T,S> &m);
template <typename T, int S> Matrix<T, S> inverse(const Matrix<T,S> &m);