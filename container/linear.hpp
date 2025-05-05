
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer: virtual public PreOrderMappableContainer<Data>, virtual public PostOrderMappableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer<Data>& operator=(const LinearContainer<Data>&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  LinearContainer<Data>& operator=(LinearContaine<Data>r&&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const LinearContainer<Data>& x)const noexcept = delete; // Comparison of abstract types is possible.
  bool operator!=(const LinearContainer<Data>& x)const noexcept = delete; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member functions

  const Data& operator[](const ulong index) const; // (non-mutable version; concrete function must throw std::out_of_range when out of range)

  const Data& Front() const; // (non-mutable version; concrete function must throw std::length_error when empty)

  const Data& Back() const; // (non-mutable version; concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  void Traverse(TraverseFun& x) override; // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  void PreOrderTraverse(TraverseFun& x) override; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  void PostOrderTraverse(TraverseFun& x) override; // Override PostOrderTraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableLinearContainer: virtual public LinearContainer<Data>, virtual public PreOrderMappableContainer<Data>, virtual public PostOrderMappableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MutableLinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableLinearContainer<Data>& operator=(const MutableLinearContainer<Data>&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  MutableLinearContainer<Data>& operator=(MutableLinearContainer<Data>&&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  Data& operator[](ulong index); // (mutable version; concrete function must throw std::out_of_range when out of range)

  Data& Front(); // (mutable version; concrete function must throw std::length_error when empty)

  Data& Back(); // (mutable version; concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  void Map(MapFun& x) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  void PreOrderMap(MapFun& x) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  void PostOrderMap(MapFun& x) override; // Override PostOrderMappableContainer member

};

template <typename Data>
class SortableLinearContainer: virtual public MutableLinearContainer {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~SortableLinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  SortableLinearContainer<Data>& operator=(const SortableLinearContainer<Data>&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  SortableLinearContainer<Data>& operator=(SortableLinearContainer<Data>&&) = delete; // Move assignment of abstract types is not be possible.

  /* ************************************************************************ */

  // Specific member function

  virtual void Sort() = 0;

protected:

  // Auxiliary member functions

  // ...

};

/* ************************************************************************** */

}

//#include "linear.cpp"

#endif
