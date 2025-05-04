
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TraversableContainer:TestableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~TraversableContainer();

  /* ************************************************************************ */

  // Copy assignment
  TraversableContainer& operator=(const TraversableContainer&); // Copy assignment of abstract types is not possible.

  // Move assignment
  TraversableContainer& operator=(TraversableContainer&&); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const TraversableContainer& x)const; // Comparison of abstract types might be possible.
  bool operator!=(const TraversableContainer& x)const; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  using TraverseFun = std::function<void(const Data &)>;

  void Traverse(TraverseFun& x);

  template <typename Accumulator>
  using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

  template <typename Accumulator>
  Accumulator& Fold(FoldFun& x,Accumulator& acc);

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  bool Exists(const Data& d); // Override TestableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PreOrderTraversableContainer:TraversableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~PreOrderTraversableContainer();

  /* ************************************************************************ */

  // Copy assignment
  PreOrderTraversableContainer& operator=(const PreOrderTraversableContainer&); // Copy assignment of abstract types is not possible.

  // Move assignment
  PreOrderTraversableContainer& operator=(PreOrderTraversableContainer&&); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderTraversableContainer& x)const; // Comparison of abstract types might be possible.
  bool operator!=(const PreOrderTraversableContainer& x)const; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  void PreOrderTraverse(TraverseFun& x);

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  Accumulator& PreOrderFold(FoldFun& x, Accumulator& acc);

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  void Traverse(TraverseFun& x); // Override TraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderTraversableContainer:TraversableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~PostOrderTraversableContainer();

  /* ************************************************************************ */

  // Copy assignment
  PostOrderTraversableContainer& operator=(const PostOrderTraversableContainer&); // Copy assignment of abstract types is not possible.

  // Move assignment
  PostOrderTraversableContainer& operator=(PostOrderTraversableContainer&&); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderTraversableContainer& x) const; // Comparison of abstract types might be possible.
  bool operator!=(const PostOrderTraversableContainer& x) const; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  void PostOrderTraverse(TraverseFun& x);

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  Accumulator& PostOrderFold(FoldFun& x, Accumulator& acc);
  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  void Traverse(TraverseFun& x); // Override TraversableContainer member

};

/* ************************************************************************** */

}

//#include "traversable.cpp"

#endif
