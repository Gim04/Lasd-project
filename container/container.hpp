
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  ulong size = 0;

protected:

  // ...

  /* ************************************************************************ */

  // Default constructor
  Container() = default;

public:

  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  Container& operator=(const Container& ) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  Container& operator=(Container&&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Container& x) const noexcept = delete; // Comparison of abstract types is not possible.
  bool operator!=(const Container& x) const noexcept = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  inline virtual bool Empty() const noexcept // (concrete function should not throw exceptions)
  {
    return (size == 0);
  }
  inline virtual ulong Size() const noexcept // (concrete function should not throw exceptions)
  {
    return size;
  }
};

/* ************************************************************************** */

class ClearableContainer : virtual public Container {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ClearableContainer& operator=(const ClearableContainer&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  ClearableContainer& operator=(ClearableContainer&&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ClearableContainer& x) const noexcept = delete; // Comparison of abstract types is not possible.
  bool operator!=(const ClearableContainer& x) const noexcept = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  inline virtual void Clear() = 0;

};

/* ************************************************************************** */

class ResizableContainer:ClearableContainer {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ResizableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ResizableContainer& operator=(const ResizableContainer&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  ResizableContainer& operator=(ResizableContainer&&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ResizableContainer& x) const noexcept = delete; // Comparison of abstract types is not possible.
  bool operator!=(const ResizableContainer& x)  const noexcept = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Resize(ulong size) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline virtual void Clear() override
  {
    Resize(0);
  }

};

/* ************************************************************************** */

}

#endif
