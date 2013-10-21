/*
 * SimpleLinalg.hpp
 *
 *  Created on: Oct 9, 2013
 *      Author: hannes
 */

#ifndef EIGENLINALG_HPP_
#define EIGENLINALG_HPP_

#include <Eigen/Core>
#include <Eigen/Geometry>

namespace eigen_linalg {

template <typename DERIVED>
using MatrixBase = Eigen::MatrixBase<DERIVED>;

template <typename Scalar, int Rows, int Cols>
using Matrix = Eigen::Matrix<Scalar, Rows, Cols>;

template <int Dim_>
using Vector = Matrix<double, Dim_, 1>;

typedef int MatrixSize;


template<typename T>
struct MatrixConvertible {
  typedef const T &  type;
  static inline type asMatrixConvertible(const T&t){
    return t;
  }
};

template<typename T>
inline typename MatrixConvertible<T>::type asMatrixConvertible(const T & t) {
  return MatrixConvertible<T>::asMatrixConvertible(t);
}

template<>
struct MatrixConvertible<std::initializer_list<double>> {
  typedef Eigen::VectorXd type;
  static inline Eigen::VectorXd asMatrixConvertible(std::initializer_list<double> t, int size = -1){
    if(size == -1) size = t.size();
    Eigen::VectorXd v(size);
    int i = 0;
    for(double d : t){
      v[i++] = d;
    }
    for(; i < size ; i++){v[i] = 0.0;}
    return v;
  }
};

template <typename T>
T & toEigen(T&t){
  return t;
}

template <typename T>
T && toEigen(T&&t){
  return std::move(t);
}


}

#ifndef EXP_LINALG
#define EXP_LINALG
#define TYPED_EXP_NAMESPACE_POSTFIX _eig

namespace linalg = eigen_linalg;

#endif
#endif /* EIGENLINALG_HPP_ */