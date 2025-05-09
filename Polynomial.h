// Copyright (c) 2016 James A. Chappell (rlrrlrll@gmail.com)
//
// c++ class to evaluate polynomials
//
#pragma once

#include <vector>

namespace Storage_B
{
  namespace Polynomials
  {
    template<typename T> class Polynomial
    {
    public:
      explicit Polynomial(const T& c = static_cast<T>(0),
                          typename std::vector<T>::size_type deg = 0)
        : coeff_(deg + 1, c) {}

      explicit Polynomial(const std::vector<T>& c) : coeff_(c) {}

      Polynomial(const T c[], typename std::vector<T>::size_type deg)
          : coeff_(c, c + deg + 1) {}

      Polynomial(const Polynomial<T>&) = default;
      Polynomial(Polynomial<T>&&) = default;
      Polynomial<T>& operator=(const Polynomial<T>&) = default;
      Polynomial<T>& operator=(Polynomial<T>&&) = default;

      ~Polynomial() = default;

      auto operator()(const T& x) const;
      auto eval(const T& x) const;

      auto degree() const
      {
        return coeff_.size() - 1; 
      }

      void IncrementDegree(const T& new_coeff = static_cast<T>(0))
      {
        coeff_.push_back(new_coeff);
      }

      auto DecrementDegree()
      {
        auto val = coeff_.back();

        coeff_.pop_back();

        return val;
      }

      auto& operator[](typename std::vector<T>::size_type idx)
      {
        return coeff_[idx];
      }

      const auto& operator[](typename std::vector<T>::size_type idx) const
      {
        return coeff_[idx];
      }

    private:
      std::vector<T> coeff_;
      static auto eval(const T& y, const T&x, const T& c)
      {
        return (y * x) + c;
      }
    };


    template <typename T> inline auto Polynomial<T>::operator()(const T &x) const
    {
      auto rit = coeff_.rbegin();

      auto y(*rit++);

      for (; rit!= coeff_.rend() ; ++rit)
      {
        y = eval(y, x, *rit);
      }

      return y;
    }

    template <typename T> inline auto Polynomial<T>::eval(
          const T& x) const
    {
      auto rit = coeff_.rbegin();

      struct { T y, dy; } res = { *rit++ , static_cast<T>(0) };

      for (; rit!= coeff_.rend() ; ++rit)
      {
        res.dy = eval(res.dy, x, res.y);
        res.y = eval(res.y, x, *rit);
      }

      return res;
    }
  }
}
