
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
class MappableContainer:virtual public TraversableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MappableContainer<Data>& operator=(const MappableContainer<Data>&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  MappableContainer<Data>& operator=(MappableContainer<Data>&&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MappableContainer& x)const noexcept = delete; // Comparison of abstract types is not possible.
  bool operator!=(const MappableContainer& x)const noexcept = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  using MapFun = std::function<void(Data &)>;

  virtual void Map(MapFun& x) = 0;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer: virtual public MappableContainer<Data>, virtual public PreOrderMappableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderMappableContainer<Data>& operator=(const PreOrderMappableContainer<Data>&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  PreOrderMappableContainer<Data>& operator=(PreOrderMappableContainer<Data>&&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderMappableContainer<Data>& x)const noexcept = delete; // Comparison of abstract types is not possible.
  bool operator!=(const PreOrderMappableContainer<Data>& x)const noexcept = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  virtual void PreOrderMap(MapFun& x) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  void Map(MapFun& x) override; // Override MappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer: virtual public MappableContainer<Data>, virtual public PostOrderTraversableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderMappableContainer<Data>& operator=(const PostOrderMappableContainer<Data>&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  PostOrderMappableContainer<Data>& operator=(PostOrderMappableContainer<Data>&&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderMappableContainer<Data>& x)const noexcept = delete; // Comparison of abstract types is not possible.
  bool operator!=(const PostOrderMappableContainer<Data>& x)const noexcept = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  virtual void PostOrderMap(MapFun& x) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  void Map(MapFun& x) override; // Override MappableContainer member

};

/* ************************************************************************** */

}

//#include "mappable.cpp"

#endif
