#include <stdexcept>

#include "setvec.hpp"

namespace lasd {


template<typename Data>
SetVec<Data>::SetVec(const TraversableContainer<Data>& c) {
  buff = Vector<Data>(c);
  size = buff.Size();
  capacity = size;
  Sort();
}


template<typename Data>
SetVec<Data>::SetVec(MappableContainer<Data>&& c) {
    buff = Vector<Data>(std::move(c));
    size = buff.Size();
    capacity = size;
    Sort();
}


template<typename Data>
SetVec<Data>::SetVec(const SetVec<Data>& v) : buff(v.size)
{
  capacity = v.capacity;
  size = v.size;
  head = v.head;

  for(ulong i = 0; i < size; i++)
  {
    buff[i] = v[i];
  }
}


template<typename Data>
SetVec<Data>::SetVec(SetVec<Data>&& v) {
  std::swap(size, v.size);
  std::swap(capacity, v.capacity);
  std::swap(head, v.head);
  std::swap(buff, v.buff);
}


template<typename Data>
SetVec<Data>::~SetVec() {
  buff.Clear();
  size = 0;
}


template<typename Data>
SetVec<Data>& SetVec<Data>::operator=(const SetVec<Data>& v) {
  std::swap(*this, v);
  return *this;
}


template<typename Data>
SetVec<Data>& SetVec<Data>::operator=(SetVec<Data>&& v) {
  std::swap(size, v.size);
  std::swap(capacity, v.capacity);
  std::swap(head, v.head);
  std::swap(buff, v.buff);
  return *this;
}


template<typename Data>
bool SetVec<Data>::operator==(const SetVec<Data>& v) const {
  if (size != v.size) {
      return false;
  }

  for (unsigned long i = 0; i < size; ++i) {
      if (buff[(head+i)%capacity] != v.buff[(v.head+i)%v.capacity]) {
          return false;
      }
  }
  return true;
}


template<typename Data>
bool SetVec<Data>::operator!=(const SetVec<Data>& v) const {
  return !(*this == v);
}


template<typename Data>
const Data& SetVec<Data>::operator[](unsigned long index) const {
  if(size == 0) throw std::length_error("Empty set!");
  if (index >= size) {
      throw std::out_of_range("Out of Bounds!");
  }
  return buff[(head + index)%capacity];
}

template<typename Data>
const Data& SetVec<Data>::Front() const
{
    if (size == 0) {
        throw std::length_error("Empty set!");
    }
    return buff[head];
}

template<typename Data>
const Data& SetVec<Data>::Back() const
{
    if (size == 0) {
        throw std::length_error("Empty set!");
    }
    return buff[(head + size-1)%capacity];
}


template<typename Data>
Data SetVec<Data>::Min() const {
  if (size == 0) {
      throw std::length_error("Empty set!");
  }
  return buff[head];
}


template <typename Data>
Data SetVec<Data>::MinNRemove() {
  Data min = Min();
  RemoveMin();        
  return min;            
}

template <typename Data>
void SetVec<Data>::RemoveMin() {
  if (size == 0) {
      throw std::length_error("Empty set!");
  }

  head = (head + 1) % capacity;
  size--;
}


template<typename Data>
Data SetVec<Data>::Max() const {
  if (size == 0) {
      throw std::length_error("Empty set!");
  }
  return buff[(head + size-1)%capacity];
}


template<typename Data>
Data SetVec<Data>::MaxNRemove() {
  Data max = Max();      
  RemoveMax();           
  return max;            
}

 

template <typename Data>
void SetVec<Data>::RemoveMax() {
  if (size == 0) {
      throw std::length_error("Empty set");
  }
  size--;
}

 

template<typename Data>
Data SetVec<Data>::Predecessor(const Data& d) const {
  unsigned long precIndex = BinarySearchPredecessor(d);
  return buff[precIndex];
}

 

template<typename Data>
Data SetVec<Data>::PredecessorNRemove(const Data& d) {
  Data val = Predecessor(d);
  RemovePredecessor(d);
  return val;
}

 

template<typename Data>
void SetVec<Data>::RemovePredecessor(const Data& d) {
  unsigned long precIndex = BinarySearchPredecessor(d);

  unsigned long numLeft = (precIndex >= head) ? (precIndex - head) : (precIndex + capacity - head);
  unsigned long numRight = size-1 - numLeft;

  if (numLeft < numRight) {
      for (unsigned long i = precIndex; i != head; i = (i + capacity-1)%capacity) {
          buff[i] = std::move(buff[(i + capacity-1)%capacity]);
      }
      head = (head + 1)%capacity;
  } else {
      for (unsigned long i = precIndex; i != (head + size-1)%capacity; i = (i + 1)%capacity) {
          buff[i] = std::move(buff[(i + 1)%capacity]);
      }
  }
  size--;
}

 

template<typename Data>
Data SetVec<Data>::Successor(const Data& d) const {
  unsigned long succIndex = BinarySearchSuccessor(d);
  return buff[succIndex];
}

 

template<typename Data>
Data SetVec<Data>::SuccessorNRemove(const Data& d) {
  Data val = Successor(d);
  RemoveSuccessor(d);
  return val;
}

 
template<typename Data>
void SetVec<Data>::RemoveSuccessor(const Data& d) {
  unsigned long succIndex = BinarySearchSuccessor(d);

  unsigned long numLeft = (succIndex >= head) ? (succIndex - head) : (succIndex + capacity - head);
  unsigned long numRight = size-1 - numLeft;

  if (numLeft < numRight) {
      for (unsigned long i = succIndex; i != head; i = (i + capacity-1)%capacity) {
          buff[i] = std::move(buff[(i + capacity-1)%capacity]);
      }
      head = (head + 1)%capacity;
  } else {
      for (unsigned long i = succIndex; i != (head + size-1)%capacity; i = (i + 1)%capacity) {
          buff[i] = std::move(buff[(i + 1)%capacity]);
      }
  }
  size--;
}



template<typename Data>
bool SetVec<Data>::Insert(const Data& value) {
  if (buff.Empty()) {
      capacity = 1;
      buff = Vector<Data>(capacity);
      head = 0;
      buff[0] = value;
      size = 1;
      return true;
  }
  if(BinarySearch(value) == true) return false;

  if (size == capacity) {
      unsigned long newCapacity = capacity * 2;
      Vector<Data> newbuff = Vector<Data>(newCapacity);

      for (unsigned long i = 0; i < size; ++i) {
          unsigned long currentIndex = (head + i) % capacity;
          newbuff[i] = std::move(buff[currentIndex]);
      }
      buff.Clear();
      buff = newbuff;
      capacity = newCapacity;
      head = 0;
  }
  unsigned long insertIndex = size;
  for (unsigned long i = 0; i < size; ++i) {
      unsigned long currentIndex = (head + i) % capacity;
      if (value < buff[currentIndex]) {
          insertIndex = i;
          break;
      }
  }

  for (unsigned long i = size; i > insertIndex; --i) {
      buff[(head + i) % capacity] = std::move(buff[(head + i - 1) % capacity]);
  }
     
  unsigned long newIndex = (head + insertIndex) % capacity;
  buff[newIndex] = value;
  size++;
  return true;
}



template <typename Data>
bool SetVec<Data>::Insert(Data&& value) {
  if (buff.Empty()) {
      capacity = 1;
      buff = Vector<Data>(capacity);
      head = 0;
      buff[0] = std::move(value);
      size = 1;
      return true;
  }
  if(BinarySearch(value) == true) return false;

  if (size == capacity) {
      unsigned long newCapacity = capacity * 2;
      Vector<Data> newbuff = Vector<Data>(newCapacity);

      for (unsigned long i = 0; i < size; ++i) {
          unsigned long currentIndex = (head + i) % capacity;
          newbuff[i] = std::move(buff[currentIndex]);
      }
      buff.Clear();
      buff = newbuff;
      capacity = newCapacity;
      head = 0;
  }
  unsigned long insertIndex = size;
  for (unsigned long i = 0; i < size; ++i) {
      unsigned long currentIndex = (head + i) % capacity;
      if (value < buff[currentIndex]) {
          insertIndex = i;
          break;
      }
  }

  for (unsigned long i = size; i > insertIndex; --i) {
      buff[(head + i) % capacity] = std::move(buff[(head + i - 1) % capacity]);
  }  
  
  unsigned long newIndex = (head + insertIndex) % capacity;
  buff[newIndex] = std::move(value);
  size++;
  return true;
}



template <typename Data>
bool SetVec<Data>::Remove(const Data& value) {
  unsigned long left = 0;
  unsigned long right = size;
  unsigned long removeIndex;
  bool found = false;

  while (left < right) {
      unsigned long mid = (left + right)/2;
      unsigned long midIndex = (head + mid)%capacity;
      if (buff[midIndex] == value) {
          found = true;
          removeIndex = midIndex;
          break;
      } else if (buff[midIndex] < value) {
          left = mid + 1;
      } else {
          right = mid;
      }
  } 
  if(!found) return false; 

  unsigned long numLeft = (removeIndex >= head) ? (removeIndex - head) : (removeIndex + capacity - head);
  unsigned long numRight = size-1 - numLeft;

  if (numLeft < numRight) {
      for (unsigned long i = removeIndex; i != head; i = (i + capacity-1)%capacity) {
          buff[i] = std::move(buff[(i + capacity-1)%capacity]);
      }
      head = (head + 1)%capacity;
  } else {
      for (unsigned long i = removeIndex; i != (head + size-1)%capacity; i = (i + 1)%capacity) {
          buff[i] = std::move(buff[(i + 1)%capacity]);
      }
  }
  size--;
  return true;
}



template <typename Data>
bool SetVec<Data>::Exists(const Data& value) const noexcept {
  return BinarySearch(value);
}



template<typename Data>
void SetVec<Data>::Clear() {
  buff.Clear();
  size = 0;
  capacity = 0;
  head = 0;
}

template <typename Data>
void SetVec<Data>::Resize(unsigned long newCapacity) {
    Vector<Data> newbuff = Vector<Data>(newCapacity);
    unsigned long buffToCopy = (size < newCapacity) ? size : newCapacity;
    for (unsigned long i = 0; i < buffToCopy; ++i) {
        unsigned long srcIndex = (head + i) % capacity;
        newbuff[i] = std::move(buff[srcIndex]);
    }
    buff.Clear();
    buff = newbuff;
    capacity = newCapacity;
    head = 0;
    size = buffToCopy;
}


template<typename Data>
bool SetVec<Data>::BinarySearch(const Data& value) const {
  unsigned long left = 0;
  unsigned long right = size;

  while (left < right) {
      unsigned long mid = (left + right)/2;
      unsigned long midIndex = (head + mid)%capacity;
      if (buff[midIndex] == value) {
          return true;
      } else if (buff[midIndex] < value) {
          left = mid + 1;
      } else {
          right = mid;
      }
  }
  return false;
}


template<typename Data>
unsigned long SetVec<Data>::BinarySearchPredecessor(const Data& value) const {
  unsigned long left = 0;
  unsigned long right = size;
  unsigned long precIndex;
  bool found = false;

  while (left < right) {
      unsigned long mid = (left + right) / 2;
      unsigned long midIndex = (head + mid) % capacity;

      if (buff[midIndex] < value) {
          precIndex = midIndex;
          found = true;
          left = mid + 1;
      } else {
          right = mid;
      }
  }
  
  if(!found) throw std::length_error("Predecessor not found!");

  return precIndex;
}


template<typename Data>
unsigned long SetVec<Data>::BinarySearchSuccessor(const Data& value) const {
  unsigned long left = 0;
  unsigned long right = size;
  unsigned long succIndex;
  bool found = false;

  while (left < right) {
      unsigned long mid = (left + right) / 2;
      unsigned long midIndex = (head + mid) % capacity;

      if (buff[midIndex] > value) {
          succIndex = midIndex;
          found = true;
          right = mid;
      } else {
          left = mid + 1;
      }
  }
  
  if(!found) throw std::length_error("Successor not found!");

  return succIndex;
}

template <typename Data>
void SetVec<Data>::Sort() {
    if (size > 1) {
        QuickSort(0, size - 1);
    }
}

template <typename Data>
void SetVec<Data>::QuickSort(unsigned long left, unsigned long right) {
    if (left < right) {
        unsigned long pivotIndex = Partition(left, right);
        if (pivotIndex > 0) QuickSort(left, pivotIndex - 1); 
        QuickSort(pivotIndex + 1, right);
    }
}

template <typename Data>
unsigned long SetVec<Data>::Partition(unsigned long left, unsigned long right) {
    Data pivot = buff[(head + right) % capacity];
    unsigned long i = left;

    for (unsigned long j = left; j < right; ++j) {
        unsigned long jIndex = (head + j) % capacity;
        unsigned long iIndex = (head + i) % capacity;

        if (buff[jIndex] < pivot) {
            std::swap(buff[iIndex], buff[jIndex]);
            ++i;
        }
    }

    std::swap(buff[(head + i) % capacity], buff[(head + right) % capacity]);
    return i;
}

}
