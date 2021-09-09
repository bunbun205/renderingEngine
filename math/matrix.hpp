#pragma once

#include <header.hpp>

// 2D and 3D Vector classes forward declarations

template<typename T> class Vector2;
template<typename T> class Vector3;
template<typename T> class Point2;
template<typename T> class Point3;

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

        Matrix operator -() const;        
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

using Matrix2f = Matrix<double, 2>;
using Matrix3f = Matrix<double, 3>;
using Matrix4f = Matrix<double, 4>;
using Matrix2i = Matrix<int, 2>;
using Matrix3i = Matrix<int, 3>;
using Matrix4i = Matrix<int, 4>;

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

#define Identity4i Matrix3i(1, 0, 0, 0,\
                            0, 1, 0, 0,\
                            0, 0, 1, 0,\
                            0, 0, 0, 1)

// Diagonal matrix definition

#define diagMat3i(s) Matrix3i((s), 0,  0,\
                               0, (s), 0,\
                               0,  0, (s))

#define diagMat4i(s) Matrix4i((s), 0,  0,  0,\
                               0, (s), 0,  0,\
                               0,  0, (s), 0,\
                               0,  0,  0, (s))

#define diagMat3f(s) Matrix3f((s), 0.0, 0.0,\
                              0.0, (s), 0.0,\
                              0.0, 0.0, (s))

#define diagMat4f(s) Matrix4f((s), 0.0, 0.0, 0.0,\
                              0.0, (s), 0.0, 0.0,\
                              0.0, 0.0, (s), 0.0,\
                              0.0, 0.0, 0.0, (s))


// Matrix inline functions

template <typename T, int S> inline std::ostream &operator << (std::ostream& out, const Matrix<T, S> &m) {

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                       out << m(i, j) << "  ";
                }

                out << std::endl;
        }

        return out;
}

template <typename T, int S> inline Matrix<T, S> operator + (const Matrix<T, S> &n, const Matrix<T, S> &m) {

        Matrix<T, S> mat;

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                        mat(i, j) = n(i, j) + m(i, j);
                }
        }

        return mat;
}

template <typename T, int S> inline Matrix<T, S> operator - (const Matrix<T, S> &n, const Matrix<T, S> &m) {

        Matrix<T, S> mat;

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                        mat(i, j) = n(i, j) - m(i, j);
                }
        }

        return mat;
}

template <typename T, int S> inline Matrix<T, S> operator * (const Matrix<T, S> &n, const Matrix<T, S> &m) {

        Matrix<T, S> mat;

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                        T sum = 0;

                        for(int x = 0; x < S; x++) {

                                sum += n(i, x) * m(x, j);
                        }

                        mat(i, j) = sum;
                }
        }

        return mat;
}

template <typename T, int S> inline Matrix<T, S> operator * (const Matrix<T, S> &m, T s) {

        Matrix<T, S> mat;

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                        mat(i, j) = s * m(i, j);
                }
        }

        return mat;
}

template <typename T, int S> inline Matrix<T, S> operator * (T s, const Matrix<T, S> &m) {

        return m * s;
}

template <typename T, int S> inline Matrix<T, S> operator / (const Matrix<T, S> &m, T s) {

        return m * (1 / s);
}

template <typename T, int S> inline Matrix<T, S-1> cofactor(const Matrix<T, S> &m, int x, int y) {

        Matrix<T, S-1> temp;

        for(int i = 0; i < x; i++) {

                for(int j = 0; j < y; j++) {

                        temp(i, j) = m.matrix[i][j];
                }
        }

        for(int i = x + 1; i < S; i++) {

                for(int j = y + 1; j < S; j++) {

                        temp(i - 1, j - 1) = m.matrix[i][j];
                }
        }

        return temp;
}

template <typename T, int S> inline T determinant(const Matrix<T, S> &m) {

        if(S == 1) return m(0, 0);

        T sum = (T)0;

        for(int i = 0; i < S; i++) {

                sum += pow(-1, i) * m(0, i) * determinant(cofactor(m, 0, i));
        }

        return sum;
}

template <typename T, int S> inline Matrix<T, S> transpose(const Matrix<T,S> &m) {

        T temp = 0.0;

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                        if(i >= j) break;

                        temp = m(i, j);
                        m(i, j) = m(j, i);
                        m(j, i) = temp;
                }
        }

        return m;
}

template <typename T, int S> inline  Matrix<T, S>adjoint(const Matrix<T,S> &m) {

        Matrix<T, S> mat;

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                        mat(i, j) = determinant(cofactor(m, i, j));
                }
        }

        return transpose(mat);
}

template <typename T, int S> inline Matrix<T, S> inverse(const Matrix<T,S> &m) {

        return m * adjoint(m) / determinant(m);
}