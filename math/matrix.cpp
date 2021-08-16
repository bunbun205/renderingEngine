#include <matrix.hpp>

// Matrix member method definitions

template <typename T, int S> inline Matrix<T, S>::Matrix() {

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                        matrix[i][j] = (T)0.0;
                }
        }
}

template <typename T, int S> inline Matrix<T, S>::Matrix(T s) {

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                        matrix[i][j] = s;
                }
        }
}

template <typename T, int S> inline Matrix<T, S>::Matrix(const Vector2<T> &v1, const Vector2<T> &v2) {

        assert(S >= 2);

        matrix[0][0] = v1.x; matrix[0][1] = v1.y;
        matrix[1][0] = v2.x; matrix[1][1] = v2.y;
}

template <typename T, int S> inline Matrix<T, S>::Matrix(const Vector3<T> &v1, const Vector3<T> &v2, const Vector3<T> &v3) {
        
        assert(S >= 3);

        matrix[0][0] = v1.x; matrix[0][1] = v1.y; matrix[0][2] = v1.z;
        matrix[1][0] = v2.x; matrix[1][1] = v2.y; matrix[1][2] = v2.z;
        matrix[2][0] = v3.x; matrix[2][1] = v3.y; matrix[2][2] = v3.z;
}

template <typename T, int S> inline Matrix<T, S>::Matrix(const Matrix<T, S> &m) {

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                        matrix[i][j] = m(i, j);
                }
        }
}

template <typename T, int S> inline Matrix<T, S>::Matrix(T m00, T m01, T m02,
                                                         T m10, T m11, T m12,
                                                         T m20, T m21, T m22) {

        assert(S >= 3 && "Matrix out of bounds, check the order entered.\n");

        matrix[0][0] = m00; matrix[0][1] = m01; matrix[0][2] = m02;
        matrix[1][0] = m10; matrix[1][1] = m11; matrix[1][2] = m12;
        matrix[2][0] = m20; matrix[2][1] = m21; matrix[2][2] = m22;
}

template <typename T, int S> inline Matrix<T, S>::Matrix(T m00, T m01, T m02, T m03,
                                                         T m10, T m11, T m12, T m13,
                                                         T m20, T m21, T m22, T m23,
                                                         T m30, T m31, T m32, T m33) {

        assert(S >= 4 && "Matrix out of bounds, check the order entered.\n");

        matrix[0][0] = m00; matrix[0][1] = m01; matrix[0][2] = m02; matrix[0][3] = m03;
        matrix[1][0] = m10; matrix[1][1] = m11; matrix[1][2] = m12; matrix[1][3] = m13;
        matrix[2][0] = m20; matrix[2][1] = m21; matrix[2][2] = m22; matrix[2][3] = m23;
        matrix[2][0] = m30; matrix[3][1] = m31; matrix[3][2] = m32; matrix[3][3] = m33;
}

template <typename T, int S> inline Matrix<T, S> Matrix<T, S>::operator () (int i, int j) const {

        return matrix[i][j];
}

template <typename T, int S> inline Matrix<T, S> &Matrix<T, S>::operator() (int i, int j) {

        return matrix[i][j];
}

template <typename T, int S> inline Vector2<T> Matrix<T, S>::operator () (int i) const {

        assert(S == 2);

        return Vector2<T>(matrix[i][0], matrix[i][1]);
}
template <typename T, int S> inline Vector2<T> &Matrix<T, S>::operator() (int i) {

        assert(S == 2);

        return Vector2<T>(matrix[i][0], matrix[i][1]);
}

template <typename T, int S> inline Matrix<T, S> &Matrix<T, S>::operator += (const Matrix<T, S> &m) {

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                        matrix[i][j] += m(i, j);
                }
        }

        return *this;
}

template <typename T, int S> inline Matrix<T, S> &Matrix<T, S>::operator -= (const Matrix<T, S> &m) {

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                        matrix[i][j] -= m(i, j);
                }
        }

        return *this;
}

template <typename T, int S> inline Matrix<T, S> &Matrix<T, S>::operator *= (const Matrix<T, S> &m) {

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                        T sum = 0;

                        for(int x = 0; x < S; x++) {

                                sum += matrix[i][x] * m(x, j);
                        }

                        matrix[i][j] = sum;
                }
        }

        return *this;
}

template <typename T, int S> inline Matrix<T, S> &Matrix<T, S>::operator *= (const T s) {

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                        matrix[i][j] *= s;
                }
        }

        return *this;
}

template <typename T, int S> inline Matrix<T, S> &Matrix<T, S>::operator /= (const T s) {

        return *this *= 1 / s;
}

template <typename T, int S> inline T Matrix<T, S>::trace() {

        T sum = 0.0;

        for(int i = 0; i < S; i++) {

                sum += m[i][i];
        }

        return sum;
}

template <typename T, int S> inline Matrix<T, S> Matrix<T, S>::identity() {

        for(int i = 0; i < S; i++) {

                for(int j = 0; j < S; j++) {

                        if(i != j) matrix[i][j] = (T)0.0;
                        else matrix[i][j] = (T)(1.0);
                }
        }

        return this;
}

template <typename T, int S> inline bool Matrix<T, S>::orthoginal() {

        return (matrix * transpose(matrix) == identity());
}

// Matrix inline function definitions

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

                                sum += n(i, x)] * m(x, j);
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

        return *this;
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