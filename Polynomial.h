// Copyright (c) 2025 James A. Chappell (rlrrlrll@gmail.com)
//
// c++ class to evaluate polynomials
//
#pragma once

#include <vector>

namespace Storage_B
{
  namespace Polynomials
  {
    /**
     * @brief Polynomial
     *
     * @details Represents a polynomial with coefficients and a specified degree.
     *
     * @tparam T Polynomial type
     */
    template<typename T>  class Polynomial
    {
    public:
      /**
       * Constructor
       *
       * @param c Default coefficient value for all terms of the polynomial
       * @param deg Degree of the polynomial
       */
      explicit Polynomial(const T& c = static_cast<T>(0),
                          typename std::vector<T>::size_type deg = 0)
        : coefficients_(deg + 1, c) {}

      /**
       * Constructor
       *
       * @param c A vector of coefficients representing the polynomial.
       *          The i-th element of the vector corresponds to the coefficient
       *          of the term with degree i.
       */
      explicit Polynomial(const std::vector<T>& c) : coefficients_(c) {}

      /**
       * Constructor
       *
       * @param c Array of coefficients representing the polynomial.
       *          The i-th element of the array corresponds to the coefficient
       *          of the term with degree i.
       * @param deg Degree of the polynomial. Represents the highest degree
       *            term for which a coefficient is provided in the array.
       */
      Polynomial(const T c[], typename std::vector<T>::size_type deg)
          : coefficients_(c, c + deg + 1) {}

      /**
       * Copy constructor
       *
       * @brief Creates a new polynomial as a copy of an existing one.
       *
       * @param other The polynomial to copy.
       */
      Polynomial(const Polynomial<T>& other) = default;

      /**
       * Move constructor
       *
       * @brief Constructs a new polynomial by transferring ownership of
       *        resources from an existing polynomial.
       *
       * @param other The polynomial to move.
       */
      Polynomial(Polynomial<T>&& other) = default;

      /**
       * Assignment operator
       *
       * @param other The polynomial to assign to the current instance.
       * @return A reference to the current polynomial after the assignment.
       */
      Polynomial<T>& operator=(const Polynomial<T>& other) = default;

      /**
       * Move assignment operator
       *
       * @brief Assigns the polynomial by transferring ownership of
       *        resources from an existing polynomial to the current instance.
       *
       * @param other The polynomial to move and assign to the current instance.
       * @return A reference to the current polynomial after the move assignment.
       */
      Polynomial<T>& operator=(Polynomial<T>&& other) = default;

      /**
       * Destructor
       *
       * @brief Default destructor for the Polynomial class. Automatically cleans up resources.
       */
      ~Polynomial() = default;

      /**
       * Evaluates the polynomial at a given point.
       *
       * @param x The point at which to evaluate the polynomial.
       * @return The value of the polynomial evaluated at the specified point.
       */
      auto operator()(const T& x) const;

      /**
       * Evaluates the polynomial and computes both its value and derivative at a given point.
       *
       * @param x The point at which to evaluate the polynomial and its derivative.
       * @return A structure containing the evaluated value of the polynomial and its derivative at the specified point.
       */
      auto eval(const T& x) const;

      /**
       * Retrieves the degree of the polynomial.
       *
       * @return The degree of the polynomial, which is the highest exponent with a non-zero coefficient.
       */
      auto degree() const
      {
        return coefficients_.size() - 1;
      }

      /**
       * Increments the degree of the polynomial by adding a new term.
       *
       * @param new_coeff The coefficient of the new highest-degree term to be added.
       *                  Defaults to zero if no value is provided.
       */
      void IncrementDegree(const T& new_coeff = static_cast<T>(0))
      {
        coefficients_.push_back(new_coeff);
      }

      /**
       * Decrements the degree of the polynomial by removing the highest-degree term.
       *
       * @return The coefficient of the removed highest-degree term.
       */
      auto DecrementDegree()
      {
        auto val = coefficients_.back();

        coefficients_.pop_back();

        return val;
      }

      /**
       * Accesses the coefficient of the polynomial at the specified index.
       *
       * @param idx The index of the coefficient to access.
       *            The index corresponds to the degree of the term.
       * @return A reference to the coefficient at the specified index, allowing modification.
       */
      auto& operator[](typename std::vector<T>::size_type idx)
      {
        return coefficients_[idx];
      }

      /**
       * Accesses the coefficient of the polynomial at a specified index (constant version).
       *
       * @param idx The index of the coefficient to access, corresponding to the degree of the term.
       * @return A constant reference to the coefficient at the specified index.
       */
      const auto& operator[](typename std::vector<T>::size_type idx) const
      {
        return coefficients_[idx];
      }

    private:
      std::vector<T> coefficients_;
      static auto eval(const T& y, const T&x, const T& c)
      {
        return (y * x) + c;
      }
    };


    template <typename T> inline auto Polynomial<T>::operator()(const T &x) const
    {
      auto rit = coefficients_.rbegin();

      auto y(*rit++);

      for (; rit!= coefficients_.rend() ; ++rit)
      {
        y = eval(y, x, *rit);
      }

      return y;
    }

    template <typename T> inline auto Polynomial<T>::eval(
          const T& x) const
    {
      auto rit = coefficients_.rbegin();

      struct { T y, dy; } res = { *rit++ , static_cast<T>(0) };

      for (; rit!= coefficients_.rend() ; ++rit)
      {
        res.dy = eval(res.dy, x, res.y);
        res.y = eval(res.y, x, *rit);
      }

      return res;
    }
  }
}
