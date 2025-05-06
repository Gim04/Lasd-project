
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : virtual public MutableLinearContainer<Data>, virtual public ResizableContainer {

private:

  // ...

protected:

  // using Container::???;

  // ...

public:

  // Default constructor
  Vector() = default;

  /* ************************************************************************ */

  // Specific constructors
  Vector(const ulong size); // A vector with a given initial dimension
  Vector(const TraversableContainer<Data>&); // A vector obtained from a TraversableContainer
  Vector(const MappableContainer<Data>&); // A vector obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  Vector (const Vector<Data>&);

  // Move constructor
  Vector (Vector<Data>&&);

  /* ************************************************************************ */

  // Destructor
  ~Vector() = default;

  /* ************************************************************************ */

  // Copy assignment
  Vector<Data>& operarator=(const Vector<Data>&);

  // Move assignment
  Vector<Data>& operarator=(Vector<Data>&&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Vector<Data>& x) const noexcept;
  bool operator!=(const Vector<Data>& x) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableLinearContainer)

  Data& operator[](ulong index) override; // Override MutableLinearContainer member (must throw std::out_of_range when out of range)

  Data& Front() override; // Override MutableLinearContainer member (must throw std::length_error when empty)

  Data& Back() override; // Override MutableLinearContainer member (must throw std::length_error when empty)
  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data& operator[](const ulong index) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  const Data& Front() const override; // Override LinearContainer member (must throw std::length_error when empty)

  const Data& Back() const override; // Override LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  void Resize(ulong size) override; // Override ResizableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

template <typename Data>
class SortableVector : virtual public Vector<Data>, virtual public SortableLinearContainer<Data>{

private:

  // ...

protected:

  // using Container::???;

  // ...

public:

  // Default constructor
  SortableVector() = default;

  /* ************************************************************************ */

  // Specific constructors
  SortableVector(const ulong size); // A vector with a given initial dimension
  SortableVector(const TraversableContainer<Data>&); // A vector obtained from a TraversableContainer
  SortableVector(const Mappable<Data>&); // A vector obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  SortableVector(const SortableVector<Data>&);

  // Move constructor
  SortableVector(SortableVector<Data>&&);

  /* ************************************************************************ */

  // Destructor
  ~SortableVector() = default;

  /* ************************************************************************ */

  // Copy assignment
  SortableVector<Data>& operator=(const SortableVector<Data>&);

  // Move assignment
  SortableVector<Data>& operator=(SortableVector<Data>&&);
protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
