
#ifndef SETVEC_HPP
#define SETVEC_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetVec:virtual public Set<Data>, virtual public ResizableContainer{


private:

  Vector<Data> vec;

protected:

  using Container::size;

  // ...

public:

  // Default constructor
  SetVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  SetVec(const TraversableContainer<Data>& c); // A set obtained from a TraversableContainer
  SetVec(MappableContainer<Data>&& c); // A set obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  SetVec(const SetVec<Data>&);

  // Move constructor
  SetVec(SetVec<Data>&&);

  /* ************************************************************************ */

  // Destructor
  ~SetVec();

  /* ************************************************************************ */

  // Copy assignment
  SetVec<Data>& operator=(const SetVec<Data>&);

  // Move assignment
  SetVec<Data>& operator=(SetVec<Data>&&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const SetVec<Data>&) const noexcept;
  bool operator!=(const SetVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from OrderedDictionaryContainer)

  Data Min() const override;  
  Data MinNRemove() override;  
  void RemoveMin() override;  

  Data Max() const override;  
  Data MaxNRemove() override;  
  void RemoveMax()  override;  

  Data Predecessor(Data& d) const override;   
  Data PredecessorNRemove(Data& d) override;   
  void RemovePredecessor(Data& d) override; 

  Data Successor(Data& d) const override;   
  Data SuccessorNRemove(Data& d) override;   
  void RemoveSuccessor(Data& d) override;   

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data& d) override; // Copy of the value
  bool Insert(Data&& d) override; // Move of the value
  bool Remove(const Data& d) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data& operator[](const ulong index) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************** */

  // Specific member function (inherited from TestableContainer)

  bool Exists(const Data& d) const noexcept override;  // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!
  void Sort() noexcept;

  void QuickSort(ulong p, ulong r) noexcept;
   
  ulong Partition(ulong p, ulong r) noexcept;

};

/* ************************************************************************** */

}

#include "setvec.cpp"

#endif
