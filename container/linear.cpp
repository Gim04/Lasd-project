#include "linear.hpp"
namespace lasd {

    template<typename Data>
    bool LinearContainer<Data>::operator==(const LinearContainer<Data>& c) const noexcept {
      if (size == c.size) {
        for (ulong index = 0; index < size; ++index) {
          if (operator[](index) != c.operator[](index)) {
            return false;
          }
        }
        return true;
      } else {
        return false;
      }
    }

    template<typename Data>
    inline bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& c) const noexcept {
      return !(*this == c);
    }


    template <typename Data>
    void LinearContainer<Data>::Traverse(TraverseFun& x) const
    {
        PreOrderTraverse(x);
    }

    template <typename Data>
    void LinearContainer<Data>::PreOrderTraverse(TraverseFun& x) const 
    {
        for(ulong i = 0; i<size; i++)
        {
            x(operator[](i));
        }
    }

    template <typename Data>
    void LinearContainer<Data>::PostOrderTraverse(TraverseFun& x) const 
    {
        for(ulong i = size-1; i>=0; i--)
        {
            x(operator[](i));
        }
    }

    template <typename Data>
    void MutableLinearContainer<Data>::Map(MapFun& x) const 
    {
        PreOrderMap(x);
    } 

    template <typename Data>
    void MutableLinearContainer<Data>::PreOrderMap(MapFun& x) const
    {
        for(ulong i = 0; i<size; i++)
        {
            x(operator[](i));
        }
    } 

  
    template <typename Data>
    void MutableLinearContainer<Data>::PostOrderMap(MapFun& x) const
    {
        for(ulong i = size-1; i>=0; i--)
        {
            x(operator[](i));
        }
    }

    template<typename Data>
    void SortableLinearContainer<Data>::Sort() noexcept 
    {
      QuickSort(0, size - 1);
    }
    
    template<typename Data>
    void SortableLinearContainer<Data>::QuickSort(ulong p, ulong r) noexcept 
    {
      if (p < r) 
      {
        ulong q = Partition(p, r);
        QuickSort(p, q);
        QuickSort(q + 1, r);
      }
    }
    
    template<typename Data>
    ulong SortableLinearContainer<Data>::Partition(ulong p, ulong r) noexcept 
    {
      Data x = this->operator[](p);
      ulong i = p - 1;
      ulong j = r + 1;
      do 
      {
        do { j--; }
        while (x < this->operator[](j));
        do { i++; }
        while (x > this->operator[](i));
        if (i < j) { std::swap(this->operator[](i), this->operator[](j)); }
      }
      while (i < j);
      return j;
    }
}
