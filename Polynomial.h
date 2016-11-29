//
// Copyright (c) 2016 James A. Chappell (rlrrlrll@gmail.com)
//
// c++ class to evaluate polynomials
//
#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <vector>

template<typename T> class Polynomial
{
public:
  Polynomial(typename std::vector<T>::size_type deg = 0);

  Polynomial(const std::vector<T>& c) : coeff_(c) {} 

  Polynomial(const T c[], typename std::vector<T>::size_type deg);

  T operator()(const T& x) const;

  typename std::vector<T>::size_type degree() const
  {
    return coeff_.size() - 1; 
  }

  void IncrementDegree(const T& new_coeff = static_cast<T>(0))
  {
    coeff_.push_back(new_coeff);
  }

  T& operator[](typename std::vector<T>::size_type idx)
  {
    return coeff_.at(idx);
  }

  const T& operator[](typename std::vector<T>::size_type idx) const
  {
    return coeff_.at(idx);
  }

private:
  std::vector<T> coeff_;
};


template <typename T> inline Polynomial<T>::Polynomial(const T *c,
    typename std::vector<T>::size_type deg) 
{
  for (typename std::vector<T>::size_type i = 0 ; i <= deg; i++)
  {
    coeff_.push_back(c[i]);
  }
}

template <typename T> inline Polynomial<T>::Polynomial(
      typename std::vector<T>::size_type deg)
{
  for (typename std::vector<T>::size_type i = 0 ; i <= deg ; i++)
  {
    coeff_.push_back(static_cast<T>(0));
  }
}

template <typename T> inline T Polynomial<T>::operator()(const T &x) const
{
  typename std::vector<T>::const_reverse_iterator rit = coeff_.rbegin();

  T val(static_cast<T>(0));
  for (; rit!= coeff_.rend() ; ++rit)
  {
    val = (val * x) + *rit;
  }

  return val;
}

#endif
