
#ifndef SETVEC_HPP
#define SETVEC_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetVec : virtual public Set<Data>, virtual public ResizableContainer {
	// Must extend Set<Data>,
  		//             ResizableContainer

private:

protected:

  using Container::size; // N elementi presenti

  Vector<Data> buff;
  unsigned long capacity = 0; // N elementi per cui è stata allocata memoria
  unsigned long head = 0; // Primo elemento

public:

  // Default constructor
  SetVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  SetVec(const TraversableContainer<Data>&); // A set obtained from a TraversableContainer
  SetVec(MappableContainer<Data>&&); // A set obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  SetVec(const SetVec&);

  // Move constructor
  SetVec(SetVec&&);

  /* ************************************************************************ */

  // Destructor
  virtual ~SetVec();

  /* ************************************************************************ */

  // Copy assignment
  SetVec& operator=(const SetVec&);

  // Move assignment
  SetVec& operator=(SetVec&&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const SetVec&) const;
  bool operator!=(const SetVec&) const;

  /* ************************************************************************ */

  // Specific member functions (inherited from OrderedDictionaryContainer)

  Data Min() const override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  Data MinNRemove() override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  void RemoveMin() override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  Data Max() const override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  Data MaxNRemove() override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  void RemoveMax() override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  Data Predecessor(const Data&) const override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(const Data&) override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  void RemovePredecessor(const Data&) override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  Data Successor(const Data&) const override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(const Data&) override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(const Data&) override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data&) override; // Override DictionaryContainer member (copy of the value)
  bool Insert(Data&&) override; // Override DictionaryContainer member (move of the value)
  bool Remove(const Data&) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data& operator[](unsigned long) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  const Data& Front() const override; // Override LinearContainer member (must throw std::length_error when empty)

  const Data& Back() const override; // Override LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************** */

  // Specific member function (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member
  
  void Resize(unsigned long) override;

protected:

  bool BinarySearch(const Data&) const;
  unsigned long BinarySearchPredecessor(const Data&) const;
  unsigned long BinarySearchSuccessor(const Data&) const;


  void Sort();
  void QuickSort(unsigned long left, unsigned long right);
  unsigned long Partition(unsigned long left, unsigned long right);

};

/* ************************************************************************** */

}

#include "setvec.cpp"

#endif
