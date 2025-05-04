
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "testable.hpp"
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer:TestableContainer:TestableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~DictionaryContainer();

  /* ************************************************************************ */

  // Copy assignment
  DictionaryContainer<Data>& operator=(const DictionaryContainer<Data>&); // Copy assignment of abstract types is not possible.

  // Move assignment
  DictionaryContainer<Data>& operator=(DictionaryContainer<Data>&&); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const DictionaryContainer<Data>& x)const; // Comparison of abstract types is not possible.
  bool operator!=(const DictionaryContainer<Data>& x)const; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  bool Insert(const Data d); // Copy of the value
  bool Insert(const Data& d); // Move of the value
  bool Remove(const Data& d);

  bool InsertAll(const TraversableContainer<Data>); // Copy of the value; From TraversableContainer; True if all are inserted
  bool InsertAll(const MappableContainer<Data>&); // Move of the value; From MappableContainer; True if all are inserted
  bool RemoveAll(const TraversableContainer<Data>); // From TraversableContainer; True if all are removed

  bool InsertSome(const TraversableContainer<Data>); // Copy of the value; From TraversableContainer; True if some is inserted
  bool InsertSome(const MappableContainer<Data>&); // Move of the value; From MappableContainer; True if some is inserted
  bool RemoveSome(const TraversableContainer<Data>); // From TraversableContainer; True if some is removed

};

/* ************************************************************************** */

template <typename Data>
class OrderedDictionaryContainer:DictionaryContainer<Data> {

private:

protected:

public:

  // Destructor
  ~OrderedDictionaryContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  OrderedDictionaryContainer& operator=(const OrderedDictionaryContainer&); // Copy assignment of abstract types is not possible.

  // Move assignment
  OrderedDictionaryContainer& operator=(OrderedDictionaryContainer&&); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const OrderedDictionaryContainer& x) const; // Comparison of abstract types is not possible.
  bool operator!=(const OrderedDictionaryContainer& x) const; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  Data Min() const; // (concrete function must throw std::length_error when empty)
  Data MinNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMin(); // (concrete function must throw std::length_error when empty)

  Data Max() const; // (concrete function must throw std::length_error when empty)
  Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMax(); // (concrete function must throw std::length_error when empty)

  Data Predecessor(Data& d); // (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(Data& d); // (concrete function must throw std::length_error when not found)
  void RemovePredecessor(argument& d); // (concrete function must throw std::length_error when not found)

  Data Successor(Data& d); // (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(Data& d); // (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(Data& d); // (concrete function must throw std::length_error when not found)

};

/* ************************************************************************** */

}

//#include "dictionary.cpp"

#endif
