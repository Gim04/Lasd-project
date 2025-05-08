
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public MutableLinearContainer<Data>, virtual public ClearableContainer {


private:

  // ...

protected:

  using Container::size;

  struct Node {

    Data data;
    Node* next;

    /* ********************************************************************** */

    // Specific constructors
    Node(const Data& data) 
    {
      this->data = data;
      this->next = nullptr;
    }

    /* ********************************************************************** */

    // Copy constructor
    Node(const Node<Data>&);

    // Move constructor
    Node(Node<Data>&&);

    /* ********************************************************************** */

    // Destructor
    ~Node() = default;

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node<Data>& x) const noexcept
    {
      return (this->data == x.data);
    } 
    bool operator!=(const Node<Data>& x) const noexcept
    {
      return !(*this == x);
    }

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  // ...

public:

  // Default constructor
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  List(const TraversableContainer<Data>& x); // A list obtained from a TraversableContainer
  List(const MappableContainer<Data>& x); // A list obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  List (const List<Data>&);

  // Move constructor
  List (List<Data>&&);

  /* ************************************************************************ */

  // Destructor
  ~List() = default;

  /* ************************************************************************ */

  // Copy assignment
  List<Data>& operator=(const List<Data>&);

  // Move assignment
  List<Data>& operator=(List<Data>&&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const List<Data>& x) const noexcept;
  bool operator!=(const List<Data>& x) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void InsertAtFront(const Data& data); // Copy of the value
  void InsertAtFront(Data&& data); // Move of the value
  void RemoveFromFront(); // (must throw std::length_error when empty)
  Data FrontNRemove() ; // (must throw std::length_error when empty)

  void InsertAtBack(const Data& data); // Copy of the value
  void InsertAtBack(Data&& data); // Move of the value
  void RemoveFromBack(); // (must throw std::length_error when empty)
  Data BackNRemove(); // (must throw std::length_error when empty)

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

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  void Map(MapFun& x) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  void PreOrderMap(MapFun& x) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  void PostOrderMap(MapFun& x) override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  void Traverse(TraverseFun& x) override; // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  void PreOrderTraverse(TraverseFun& x) const override; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  void PostOrderTraverse(TraverseFun& x) override; // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
