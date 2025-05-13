
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
    Node* next = nullptr;

    /* ********************************************************************** */

    // Specific constructors
    Node(const Data& data) 
    {
      this->data = data;
      this->next = nullptr;
    }

    /* ********************************************************************** */

    // Copy constructor
    Node(const Node& n)
    {
      data = n.data;
    }

    // Move constructor
    Node(Node&& n);

    /* ********************************************************************** */

    // Destructor
    virtual ~Node();

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node& n) const noexcept
    {
      return (this->data == n.data) && (this->next == n.next);
    } 
    bool operator!=(const Node& n) const noexcept
    {
      return !(*this == n);
    }

    /* ********************************************************************** */

      virtual Node* Clone(Node* n);
  };

  Node* head = nullptr;
  Node* tail = nullptr;

public:

  // Default constructor
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  List(const TraversableContainer<Data>& x); // A list obtained from a TraversableContainer
  List(MappableContainer<Data>&& x); // A list obtained from a MappableContainer

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
  bool operator==(const List<Data>& n) const noexcept;
  bool operator!=(const List<Data>& n) const noexcept;

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

  void Map(MapFun& x) const override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  void PreOrderMap(MapFun& x) const override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  void PostOrderMap(MapFun& x) const override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  void Traverse(TraverseFun& x) const override; // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  void PreOrderTraverse(TraverseFun& x) const override; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  void PostOrderTraverse(TraverseFun& x) const override; // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override; // Override ClearableContainer member

protected:

  void PreOrderTraverse(TraverseFun x, const Node* n) const;
  void PostOrderTraverse(TraverseFun x, const Node* n) const;

  void PreOrderMap(MapFun x, Node* n) const ;
  void PostOrderMap(MapFun x, Node* n)const ;

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
