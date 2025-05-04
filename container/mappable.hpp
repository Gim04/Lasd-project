
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer:TraversableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~MappableContainer();

  /* ************************************************************************ */

  // Copy assignment
  MappableContainer& operator=(const MappableContainer&); // Copy assignment of abstract types is not possible.

  // Move assignment
  MappableContainer& operator=(MappableContainer&&); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MappableContainer& x)const; // Comparison of abstract types is not possible.
  bool operator!=(const MappableContainer& x)const; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  using MapFun = std::function<void(Data &)>;

  void Map(MapFun& x);

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer:MappableContainer<Data>, PreOrderMappableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~PreOrderMappableContainer();

  /* ************************************************************************ */

  // Copy assignment
  PreOrderMappableContainer& operator=(const PreOrderMappableContainer&); // Copy assignment of abstract types is not possible.

  // Move assignment
  PreOrderMappableContainer& operator=(PreOrderMappableContainer&&); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderMappableContainer& x)const; // Comparison of abstract types is not possible.
  bool operator!=(const PreOrderMappableContainer& x)const; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  void PreOrderMap(MapFun& x);

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  void Map(MapFun& x); // Override MappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer:MappableContainer<Data>, PostOrderTraversableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~PostOrderMappableContainer();

  /* ************************************************************************ */

  // Copy assignment
  PostOrderMappableContainer& operator=(const PostOrderMappableContainer&); // Copy assignment of abstract types is not possible.

  // Move assignment
  PostOrderMappableContainer& operator=(PostOrderMappableContainer&&); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderMappableContainer& x)const; // Comparison of abstract types is not possible.
  bool operator!=(const PostOrderMappableContainer& x)const; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  void PostOrderMap(MapFun& x);

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  void Map(MapFun& x); // Override MappableContainer member

};

/* ************************************************************************** */

}

//#include "mappable.cpp"

#endif
