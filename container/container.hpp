
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  ulong size;

protected:

  // ...

  /* ************************************************************************ */

  // Default constructor
  Container() = default;

public:

  // Destructor
  ~Container();

  /* ************************************************************************ */

  // Copy assignment
  Container& operator=(const Container& ); // Copy assignment of abstract types is not possible.

  // Move assignment
  Container& operator=(Container&&); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Container& x) const; // Comparison of abstract types is not possible.
  bool operator!=(const Container& x) const; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  bool Empty() const noexcept; // (concrete function should not throw exceptions)

  ulong Size() const noexcept; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

class ClearableContainer:Container {
  // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~ClearableContainer();

  /* ************************************************************************ */

  // Copy assignment
  ClearableContainer& operator=(const ClearableContainer&); // Copy assignment of abstract types is not possible.

  // Move assignment
  ClearableContainer& operator=(ClearableContainer&&); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ClearableContainer& x); // Comparison of abstract types is not possible.
  bool operator!=(const ClearableContainer& x); // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Clear();

};

/* ************************************************************************** */

class ResizableContainer:ClearableContainer {
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~ResizableContainer();

  /* ************************************************************************ */

  // Copy assignment
  ResizableContainer& operator=(const ResizableContainer&); // Copy assignment of abstract types is not possible.

  // Move assignment
  ResizableContainer& operator=(ResizableContainer&&); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ResizableContainer& x) const; // Comparison of abstract types is not possible.
  bool operator!=(const ResizableContainer& x) const; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  void Resize(ulong size);

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear(); // Override ClearableContainer member

};

/* ************************************************************************** */

}

#endif
