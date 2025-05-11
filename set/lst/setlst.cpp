#include "setlst.hpp"
#include <stdexcept>
namespace lasd {

    template<typename Data>
    SetLst<Data>::SetLst(const TraversableContainer<Data>& c) : List(c)
    {
       
        size = c.Size();
    } 

    template<typename Data>
    SetLst<Data>::SetLst(MappableContainer<Data>&& c): List(c)
    {
        size = c.Size();
    }


    template<typename Data>
    SetLst<Data>::SetLst(const SetLst<Data>& list) 
    {
        size = SetLst.Size();
        for(ulong i = 0; i<size; i++)
        {
            operator[](i) = list[i];
        }
    }

    template<typename Data>
    SetLst<Data>::SetLst(SetLst<Data>&& list)
    {
        size = SetLst.Size();
        for(ulong i = 0; i<size; i++)
        {
            operator[](i) = std::move(list[i]);
        }
    }

    template<typename Data>
    SetLst<Data>::~SetLst()
    {
        Clear();
        size = 0;
    }


    template<typename Data>
    SetLst<Data>& SetLst<Data>::operator=(const SetLst<Data>& lista)
    {
        iif(*this != lista)
        {
            Clear();

            if(lista.tail != nullptr)
            {
                tail = new Node(*lista.tail);
                head = lista.head->Clone(tail);
                size = lista.size;
            }
        }
        return *this;
    }

    template<typename Data>
    SetLst<Data>& SetLst<Data>::operator=(SetLst<Data>&& n)
    {
        std::swap(tail, n.tail);
        std::swap(head, n.head);
        std::swap(size, n.size);

        return *this;
    }


    template<typename Data>
    bool SetLst<Data>::operator==(const SetLst<Data>& list) const noexcept
    {
        if(size == n.size)
        {
            if(head == n.head)
            {
                return true;
            }
        }
        return false;
    }

    template<typename Data>
    bool SetLst<Data>::operator!=(const SetLst<Data>& list) const noexcept
    {
        return !(*this == list);
    }


    template<typename Data>
    Data SetLst<Data>::Min() const
    {
        if(size == 0)
        {
            throw std::length_error("Empty vector!");
        }
        Data min = operator[](0);
        for(ulong i = 1; i<size; i++)
        {
            if(min>operator[](i))
            {
                min = operator[](i);
            }
        }

        return min;
    }

    template<typename Data>
    Data SetLst<Data>::MinNRemove()
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

        Sort();

        return min;

    }

    template<typename Data>
    void SetLst<Data>::RemoveMin()
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
        Sort();

    }

    template<typename Data>
    Data SetLst<Data>::Max() const
    {   
        if(size == 0)
        {
            throw std::length_error("Empty vector!");
        }

        Data max = operator[](0);
        for(ulong i = 1; i<size; i++)
        {
            if(max<operator[](i))
            {
                max = operator[](i);
            }
        }

        return max;

    }  

    template<typename Data>
    Data SetLst<Data>::MaxNRemove()
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
        Sort();

        return max;
    }  

    template<typename Data>
    void SetLst<Data>::RemoveMax()
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
        Sort();
    } 

    template<typename Data>
    Data SetLst<Data>::Predecessor(Data& d) const
    {
        ulong index = 0;
        bool found = false;

        for(ulong i = 0; i<size; i++)
        {
            if(operator[](i) == d)
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

        return operator[](index-1);

    }

    template<typename Data>
    Data SetLst<Data>::PredecessorNRemove(Data& d)
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
        Sort();
        
        return predecessor;
    } 

    template<typename Data>
    void SetLst<Data>::RemovePredecessor(Data& d)
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
        Sort();
        
    }  

    template<typename Data>
    Data SetLst<Data>::Successor(Data& d) const
    {
        ulong index = 0;
        bool found = false;

        for(ulong i = 0; i<size; i++)
        {
            if(operator[](i) == d)
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

        return operator[](index+1);
    }

    template<typename Data>
    Data SetLst<Data>::SuccessorNRemove(Data& d)
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
        Sort();
        
        return successor;
    }  

    template<typename Data>
    void SetLst<Data>::RemoveSuccessor(Data& d)
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
        Sort();
    } 

    template<typename Data>
    bool SetLst<Data>::Insert(const Data& d)
    {
        if(Exists(d)) return false;
        size++;
        v.Resize(size);
        v[size-1] = d;
        Sort();

        return true;

    }

    template<typename Data>
    bool SetLst<Data>::Insert(Data&& d) 
    {
        if(Exists(d)) return false;
        size++;
        v.Resize(size);
        v[size-1] = d;
        Sort();

        return true;
    }

    template<typename Data>
    bool SetLst<Data>::Remove(const Data& d) 
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
    const Data& SetLst<Data>::operator[](const ulong index) const 
    {
        if(index>= size)
        {
            throw std::out_of_range("Size exdeed!");
        }

        ulong i = 0;
        Node* newHead = head;
        while(newHead != nullptr)
        {
            if(i == index)
            {
                return head->data;
            }
            newHead = newHead->next;
            i++;
        }
    }


    template<typename Data>
    bool SetLst<Data>::Exists(const Data& d) const noexcept 
    {
        for(ulong i = 0; i<size; i++)
        {
            if(operator[](i)== d)
            {
                return true
            }
        }
        return false;
    }


    template<typename Data>
    inline void SetLst<Data>::Clear() 
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    template<typename Data>
    void SetLst<Data>::Sort() noexcept 
    {
        QuickSort(0, size - 1);
    }

    template<typename Data>
    void SetLst<Data>::QuickSort(ulong p, ulong r) noexcept 
    {
        if (p < r) 
        {
            ulong q = Partition(p, r);
            QuickSort(p, q);
            QuickSort(q + 1, r);
        }
    }

    template<typename Data>
    ulong SetLst<Data>::Partition(ulong p, ulong r) noexcept 
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
