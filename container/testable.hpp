
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TestableContainer:Container {
  // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~TestableContainer();

  /* ************************************************************************ */

  // Copy assignment
  TestableContainer<Data>& operator=(const TestableContainer<Data>&); // Copy assignment of abstract types is not possible.

  // Move assignment
  TestableContainer<Data>& operator=(TestableContainer<Data>&&); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const TestableContainer<Data>& x) const; // Comparison of abstract types is not possible.
  bool operator!=(const TestableContainer<Data>& x) const; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  bool Exists(const Data& d) const noexcept; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

}

#endif
