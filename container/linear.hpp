
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer:PreOrderMappableContainer<Data>, PostOrderMappableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~LinearContainer();

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer& operator=(const LinearContainer&); // Copy assignment of abstract types is not possible.

  // Move assignment
  LinearContainer& operator=(LinearContainer&&); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const LinearContainer& x)const; // Comparison of abstract types is possible.
  bool operator!=(const LinearContainer& x)const; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member functions

  const Data& operator[](const ulong index) const; // (non-mutable version; concrete function must throw std::out_of_range when out of range)

  const Data& Front() const; // (non-mutable version; concrete function must throw std::length_error when empty)

  const Data& Back() const; // (non-mutable version; concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  void Traverse(TraverseFun& x); // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  void PreOrderTraverse(TraverseFun& x); // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  void PostOrderTraverse(TraverseFun& x); // Override PostOrderTraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableLinearContainer:LinearContainer<Data>, PreOrderMappableContainer<Data>, PostOrderMappableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~MutableLinearContainer();

  /* ************************************************************************ */

  // Copy assignment
  MutableLinearContainer& operator=(const MutableLinearContainer&)const; // Copy assignment of abstract types is not possible.

  // Move assignment
  MutableLinearContainer& operator=(MutableLinearContainer&&)const; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  Data operator[](ulong index); // (mutable version; concrete function must throw std::out_of_range when out of range)

  Data Front(); // (mutable version; concrete function must throw std::length_error when empty)

  Data Back(); // (mutable version; concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  void Map(MapFun& x); // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  void PreOrderMap(MapFun& x); // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  void PostOrderMap(MapFun& x); // Override PostOrderMappableContainer member

};

template <typename Data>
class SortableLinearContainer:MutableLinearContainer {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~SortableLinearContainer();

  /* ************************************************************************ */

  // Copy assignment
  SortableLinearContainer& operator=(const SortableLinearContainer&); // Copy assignment of abstract types is not possible.

  // Move assignment
  SortableLinearContainer& operator=(SortableLinearContainer&&); // Move assignment of abstract types is not be possible.

  /* ************************************************************************ */

  // Specific member function

  void Sort();

protected:

  // Auxiliary member functions

  // ...

};

/* ************************************************************************** */

}

//#include "linear.cpp"

#endif
