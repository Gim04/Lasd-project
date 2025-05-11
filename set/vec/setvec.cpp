#include "setvec.hpp"
#include <stdexcept>
namespace lasd {

    template<typename Data>
    SetVec<Data>::SetVec(const TraversableContainer<Data>& c)
    {
        vec = Vector<Data>(c);
        size = vec.Size();
    } 

    template<typename Data>
    SetVec<Data>::SetVec(MappableContainer<Data>&& c)
    {
        vec = Vector<Data>(c);
        size = vec.Size();
    }

    /* ************************************************************************ */

    template<typename Data>
    SetVec<Data>::SetVec(const SetVec<Data>& v) 
    {
        size = SetVec.Size();
        for(ulong i = 0; i<size; i++)
        {
            vec[i] = v[i];
        }
    }

    template<typename Data>
    SetVec<Data>::SetVec(SetVec<Data>&& v)
    {
        size = SetVec.Size();
        for(ulong i = 0; i<size; i++)
        {
            vec[i] = std::move(v[i]);
        }
    }

    /* ************************************************************************ */

    template<typename Data>
    SetVec<Data>::~SetVec()
    {
        vec.Clear();
        size = 0;
    }

    /* ************************************************************************ */

    template<typename Data>
    SetVec<Data>& SetVec<Data>::operator=(const SetVec<Data>&)
    {

    }

    template<typename Data>
    SetVec<Data>& SetVec<Data>::operator=(SetVec<Data>&&)
    {

    }

  /* ************************************************************************ */

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

        //sort

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
        //sort

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
        //sort

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
    } 

    template<typename Data>
    Data SetVec<Data>::Predecessor(Data& d) const
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
            throw std::length_error("Value not found!");
        }

        if(index == 0)
        {
            throw std::length_error("Predecessor not found!");
        }

        return vec[index-1];

    }

    template<typename Data>
    Data SetVec<Data>::PredecessorNRemove(Data& d)
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
            throw std::length_error("Value not found!");
        }

        if(index == 0)
        {
            throw std::length_error("Predecessor not found!");
        }

        Data predecessor = vec[index-1];
        vec[index-1] = vec[size-1];
        vec.Resize(size-1);
        size--;
        //sort
        
        return predecessor;
    } 

    template<typename Data>
    void SetVec<Data>::RemovePredecessor(Data& d)
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
            throw std::length_error("Value not found!");
        }

        if(index == 0)
        {
            throw std::length_error("Predecessor not found!");
        }

        vec[index-1] = vec[size-1];
        vec.Resize(size-1);
        size--;
        //sort
        
    }  

    template<typename Data>
    Data SetVec<Data>::Successor(Data& d) const
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
            throw std::length_error("Value not found!");
        }

        if(index == size-1)
        {
            throw std::length_error("Successor not found!");
        }

        return vec[index+1];
    }

    template<typename Data>
    Data SetVec<Data>::SuccessorNRemove(Data& d)
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
            throw std::length_error("Value not found!");
        }

        if(index == size-1)
        {
            throw std::length_error("successor not found!");
        }

        Data successor = vec[index+1];
        vec[index+1] = vec[size-1];
        vec.Resize(size-1);
        size--;
        //sort
        
        return successor;
    }  

    template<typename Data>
    void SetVec<Data>::RemoveSuccessor(Data& d)
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
            throw std::length_error("Value not found!");
        }

        if(index == size-1)
        {
            throw std::length_error("Successor not found!");
        }

        vec[index+1] = vec[size-1];
        vec.Resize(size-1);
        size--;
        //sort
    } 

    template<typename Data>
    bool SetVec<Data>::Insert(const Data& d)
    {

    }

    template<typename Data>
    bool SetVec<Data>::Insert(Data&& d) 
    {

    }

    template<typename Data>
    bool SetVec<Data>::Remove(const Data& d) 
    {

    }


    template<typename Data>
    const Data& SetVec<Data>::operator[](const ulong index) const 
    {

    }


    template<typename Data>
    bool SetVec<Data>::Exists(const Data& d) const noexcept 
    {

    }


    template<typename Data>
    inline void SetVec<Data>::Clear() 
    {

    }

}
