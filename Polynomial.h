//
// Copyright (c) 2016 James A. Chappell (rlrrlrll@gmail.com)
//
// c++ class to evaluate polynomials
//
#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <vector>
#include <utility>

template<typename T> class Polynomial
{
public:
  Polynomial(typename std::vector<T>::size_type deg = 0)
      : coeff_(deg + 1, static_cast<T>(0)) {}

  Polynomial(const std::vector<T>& c) : coeff_(c) {}

  Polynomial(const T c[], typename std::vector<T>::size_type deg)
      : coeff_(c, c + deg + 1) {}

  T operator()(const T& x) const;

  std::pair<T, T> Evaluate(const T& x) const;

  typename std::vector<T>::size_type degree() const
  {
    return coeff_.size() - 1; 
  }

  void IncrementDegree(const T& new_coeff = static_cast<T>(0))
  {
    coeff_.push_back(new_coeff);
  }

  void DecrementDegree(const T& new_coeff = static_cast<T>(0))
  {
    coeff_.pop_back();
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
  static T eval(const T& y, const T&x, const T& c) { return (y * x) + c; }
};


template <typename T> inline T Polynomial<T>::operator()(const T &x) const
{
  typename std::vector<T>::const_reverse_iterator rit = coeff_.rbegin();

  T y(*rit++);

  for (; rit!= coeff_.rend() ; ++rit)
  {
    y = eval(y, x, *rit);
  }

  return y;
}

template <typename T> inline std::pair<T, T>
    Polynomial<T>::Evaluate(const T& x)  const
{
  typename std::vector<T>::const_reverse_iterator rit = coeff_.rbegin();

  T y(*rit++);
  T dy(static_cast<T>(0));

  for (; rit!= coeff_.rend() ; ++rit)
  {
    dy = eval(dy, x, y);
    y = eval(y, x, *rit);
  }

  return std::make_pair(y, dy);
}

#endif
