
#ifndef SETLST_HPP
#define SETLST_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetLst: virtual public Set<Data>, virtual public List<Data>{

private:

  // ...

protected:

  using Container::size;

  // ...

public:

  // Default constructor
  SetLst() = default;

  /* ************************************************************************ */

  // Specific constructors
  SetLst(const TraversableContainer<Data>& c); // A set obtained from a TraversableContainer
  SetLst(MappableContainer<Data>&& c); // A set obtained from a MappableContainer


  /* ************************************************************************ */

  // Copy constructor
  SetLst(const SetLst<Data>&);

  // Move constructor
  SetLst(SetLst<Data>&&);

  /* ************************************************************************ */

  // Destructor
  ~SetLst();

  /* ************************************************************************ */

  // Copy assignment
  SetLst<Data>& operator=(const SetLst<Data>&);

  // Move assignment
  SetLst<Data>& operator=(SetLst<Data>&&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const SetLst<Data>&) const noexcept;
  bool operator!=(const SetLst<Data>&) const noexcept;

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

  List<Data>::Node* GetNode(const ulong index);

};

/* ************************************************************************** */

}

#include "setlst.cpp"

#endif
