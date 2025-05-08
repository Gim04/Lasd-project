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

    template <typename Data>
    void  SortableLinearContainer<Data>::Sort() noexcept
    {
        
        for(i = 0; i<size-1; i++)
        {
            ulong min = i;
            for(j = i+1; j<size; j++)
            {
                if(operator[](j) < operator[](min))
                {
                    min = j;
                }
            }

            Data tmp = operator[](i);
            operator[](i) = operator[](min);
            operator[](min) = tmp;
        }    
    }
}
