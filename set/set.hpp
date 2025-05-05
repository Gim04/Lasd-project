
#ifndef SET_HPP
#define SET_HPP

/* ************************************************************************** */

#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Set: virtual public OrderedDictionaryContainer<Data>, virtual public LinearContainer<Data>, virtual public ClearableContainer{
 
private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~Set() = default;

  /* ************************************************************************ */

  // Copy assignment
  Set<Data>& operator=(const Set<Data>&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  Set<Data>& operator=(Set<Data>&&) = delete; // Move assignment of abstract types is not possible.

};

/* ************************************************************************** */

}

#endif
