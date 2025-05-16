#include "setvec.hpp"
#include <stdexcept>
namespace lasd {

    template<typename Data>
    SetVec<Data>::SetVec(const TraversableContainer<Data>& c)
    {
        vec = Vector<Data>(c);
        size = vec.Size();
        Sort();
    } 

    template<typename Data>
    SetVec<Data>::SetVec(MappableContainer<Data>&& c)
    {
        vec = Vector<Data>(std::move(c));
        size = vec.Size();
        Sort();
    }

    /* ************************************************************************ */

    template<typename Data>
    SetVec<Data>::SetVec(const SetVec<Data>& v) : vec(size)
    {
        size = v.Size();
        for(ulong i = 0; i<size; i++)
        {
            vec[i] = v[i];
        }
    }

    template<typename Data>
    SetVec<Data>::SetVec(SetVec<Data>&& v) : vec(std::move(v.vec))
    {
        size = v.Size();
        v.size = 0;
    }

    template<typename Data>
    SetVec<Data>::~SetVec()
    {
        vec.Clear();
        size = 0;
    }


    template<typename Data>
    SetVec<Data>& SetVec<Data>::operator=(const SetVec<Data>& v)
    {
        if(this != &v)
        {
            vec = v.vec;
            size = v.size;

        }

        return *this;
    }

    template<typename Data>
    SetVec<Data>& SetVec<Data>::operator=(SetVec<Data>&& v)
    {
        if(this != &v)
        {
            vec = std::move(v.vec);
            size = v.size;
            v.size = 0;

        }

        return *this;
    }


    template<typename Data>
    bool SetVec<Data>::operator==(const SetVec<Data>& v) const noexcept
    {
        return (size == v.size) && (vec == v);
    }

    template<typename Data>
    bool SetVec<Data>::operator!=(const SetVec<Data>&v) const noexcept
    {
        return !(*this == v);
    }


    template<typename Data>
    Data SetVec<Data>::Min() const
    {
        if(size == 0)
        {
            throw std::length_error("Empty vector!");
        }
        Data min = vec[0];
        for(ulong i = 1; i<size; i++)
        {
            if(min>vec[i])
            {
                min = vec[i];
            }
        }

        return min;
    }

    template<typename Data>
    Data SetVec<Data>::MinNRemove()
    {
        if(size == 0)
        {
            throw std::length_error("Empty vector!");
        }

        ulong index = 0;
        Data min = vec[0];
        for(ulong i = 1; i<size; i++)
        {
            if(min>vec[i])
            {
                min = vec[i];
                index = i;
            }
        }

        vec[index] = vec[size-1]; //swap with the element that must be removed
        vec.Resize(size-1); 

        size--;

        Sort();

        return min;

    }

    template<typename Data>
    void SetVec<Data>::RemoveMin()
    {
        if(size == 0)
        {
            throw std::length_error("Empty vector!");
        }

        ulong index = 0;
        Data min = vec[0];
        for(ulong i = 1; i<size; i++)
        {
            if(min>vec[i])
            {
                min = vec[i];
                index = i;
            }
        }

        vec[index] = vec[size-1]; //swap
        vec.Resize(size-1);
        size--;
        Sort();

    }

    template<typename Data>
    Data SetVec<Data>::Max() const
    {   
        if(size == 0)
        {
            throw std::length_error("Empty vector!");
        }

        Data max = vec[0];
        for(ulong i = 1; i<size; i++)
        {
            if(max<vec[i])
            {
                max = vec[i];
            }
        }

        return max;

    }  

    template<typename Data>
    Data SetVec<Data>::MaxNRemove()
    {
        if(size == 0)
        {
            throw std::length_error("Empty vector!");
        }

        ulong index = 0;
        Data max = vec[0];
        for(ulong i = 1; i<size; i++)
        {
            if(max<vec[i])
            {
                max = vec[i];
                index = i;
            }
        }

        vec[index] = vec[size-1];//swap
        vec.Resize(size-1);
        size--;
        Sort();

        return max;
    }  

    template<typename Data>
    void SetVec<Data>::RemoveMax()
    {
        if(size == 0)
        {
            throw std::length_error("Empty vector!");
        }

        ulong index = 0;
        Data max = vec[0];
        for(ulong i = 1; i<size; i++)
        {
            if(max<vec[i])
            {
                max = vec[i];
                index = i;
            }
        }

        vec[index] = vec[size-1];//swap
        vec.Resize(size-1);
        size--;
        Sort();
    } 

    template<typename Data>
    Data SetVec<Data>::Predecessor(const Data& d) const
    {
        
        if(size == 0)
        {
            throw std::length_error("Predecessor not found!");
        }

        for(ulong i = size-1; i>=0; i--)
        {
            if(vec[i] < d)
            {
               return vec[i];
            }
        }
        throw std::length_error("Predecessor not found!");

    }

    template<typename Data>
    Data SetVec<Data>::PredecessorNRemove(const Data& d)
    {
        if(size == 0)
        {
            throw std::length_error("Predecessor not found!");
        }

        for(ulong i = size-1; i>=0; i--)
        {
            if(vec[i] < d)
            {
                Data predecessor = vec[i];
                vec[i] = vec[size-1];
                vec.Resize(size-1);
                size--;
                Sort();
            
                return predecessor;
            }
        }
        throw std::length_error("Predecessor not found!");

    } 

    template<typename Data>
    void SetVec<Data>::RemovePredecessor(const Data& d)
    {
        if(size == 0)
        {
            throw std::length_error("Predecessor not found!");
        }

        for(ulong i = size-1; i>=0; i--)
        {
            if(vec[i] < d)
            {
                vec[i] = vec[size-1];
                vec.Resize(size-1);
                size--;
                Sort();
        
            }
        }
        throw std::length_error("Predecessor not found!");

        
    }  

    template<typename Data>
    Data SetVec<Data>::Successor(const Data& d) const
    {
       
        if(size == 0)
        {
            throw std::length_error("Successor not found!");
        }

        for(ulong i = 0; i<size; i++)
        {
            if(vec[i] > d)
            {
                return vec[i];
            }
        }
        throw std::length_error("Successor not found!");
    
    }

    template<typename Data>
    Data SetVec<Data>::SuccessorNRemove(const Data& d)
    {
        if(size == 0)
        {
            throw std::length_error("Successor not found!");
        }

        for(ulong i = 0; i<size; i++)
        {
            if(vec[i] > d)
            {
                Data successor = vec[i];
                vec[i] = vec[size-1];
                vec.Resize(size-1);
                size--;
                Sort();
        
                return successor;
            }
        }
        throw std::length_error("Successor not found!");
    
    }  

    template<typename Data>
    void SetVec<Data>::RemoveSuccessor(const Data& d)
    {
        if(size == 0)
        {
            throw std::length_error("Successor not found!");
        }

        for(ulong i = 0; i<size; i++)
        {
            if(vec[i] > d)
            {
                vec[i] = vec[size-1];
                vec.Resize(size-1);
                size--;
                Sort();
            }
        }
        throw std::length_error("Successor not found!");
    
    } 

    template<typename Data>
    bool SetVec<Data>::Insert(const Data& d)
    {
        if(Exists(d)) return false;
        size++;
        vec.Resize(size);
        vec[size-1] = d;
        Sort();

        return true;

    }

    template<typename Data>
    bool SetVec<Data>::Insert(Data&& d) 
    {
        if(Exists(d)) return false;
        size++;
        vec.Resize(size);
        vec[size-1] = d;
        Sort();

        return true;
    }

    template<typename Data>
    bool SetVec<Data>::Remove(const Data& d) 
    {
        ulong index = 0;
        bool found = false;

        for(ulong i = 0; i<size; i++)
        {
            if(vec[i] == d)
            {
                index = i;
                found = true;
                break;
            }
        }
        if(!found)
        {
            return false;
        }
        vec[index] = vec[size-1];
        vec.Resize(size-1);
        size--;
        Sort();
        return true;

    }


    template<typename Data>
    const Data& SetVec<Data>::operator[](const ulong index) const 
    {
        if( index >= size)
        {
            throw std::out_of_range("Out of bound!");
        }

        return vec[index];
    }


    template<typename Data>
    bool SetVec<Data>::Exists(const Data& d) const noexcept 
    {
        for(ulong i = 0; i<size; i++)
        {
            if(vec[i]== d)
            {
                return true;
            }
        }
        return false;
    }

    template<typename Data>
    const Data& SetVec<Data>::Front() const
    {
        vec.Front();
    }   

    template<typename Data>
    const Data& SetVec<Data>::Back() const 
    {
        vec.Back();
    }

    template<typename Data>
    void SetVec<Data>::Resize(ulong size) 
    {
        vec.Resize(size);
    }

    template<typename Data>
    inline void SetVec<Data>::Clear() 
    {
        vec.Clear();
        size = 0;
    }

    template<typename Data>
    void SetVec<Data>::Sort() noexcept 
    {
        QuickSort(0, size - 1);
    }

    template<typename Data>
    void SetVec<Data>::QuickSort(ulong p, ulong r) noexcept 
    {
        if (p < r) 
        {
            ulong q = Partition(p, r);
            QuickSort(p, q);
            QuickSort(q + 1, r);
        }
    }

    template<typename Data>
    ulong SetVec<Data>::Partition(ulong p, ulong r) noexcept 
    {
        Data x = vec[p];
        ulong i = p - 1;
        ulong j = r + 1;
        do 
        {
            do { j--; }
            while (x < vec[j]);
            do { i++; }
            while (x > vec[i]);
            if (i < j) { std::swap(vec[i], vec[j]); }
        }
        while (i < j);
            return j;
    }

}
