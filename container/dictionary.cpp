#include "dictionary.hpp"
#include <stdexcept>
namespace lasd {

    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& c)
    {
        bool ret = true;
        c.Traverse(
            [this, &](const Data& d)
            {
                ret &= Insert(d);
            }
        );

        return ret;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& c)
    {
        bool ret = true;
        c.Map(
            [this, &](Data& d)
            {
                ret &= Insert(d);
            }
        );

        return ret;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data>& c)
    {
        bool ret = true;
        c.Traverse(
            [this, &](const Data& d)
            {
                ret &= Remove(d);
            }
        );

        return ret;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data>& c)
    {
        bool ret = false;
        c.Traverse(
            [this, &](const Data& d)
            {
                ret |= Insert(d);
            }
        );

        return ret;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& c)
    {
        bool ret = false;
        c.Map(
            [this, &](Data& d)
            {
                ret |= Insert(d);
            }
        );

        return ret;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data>& c)
    {
        bool ret = false;
        c.Traverse(
            [this, &](const Data& d)
            {
                ret |= Remove(d);
            }
        );

        return ret;
    }


    template<typename Data>
    Data OrderedDictionaryContainer<Data>::Min() const
    {
        if Empty()
        {
            throw std::length_error("Empty container!");
        }

        Data min;
        ulong i = 0;
        Traverse(
            [this, &](const Data& d)
            {
                if(i==0) min = d;

                if(data<min)
                {
                    min = d;
                }
            }
        );
        return min;
    }

    template<typename Data>
    Data OrderedDictionaryContainer<Data>::MinNRemove()
    {
        if Empty()
        {
            throw std::length_error("Empty container!");
        }

    }

    template<typename Data>
    void OrderedDictionaryContainer<Data>::RemoveMin()
    {
        if Empty()
        {
            throw std::length_error("Empty container!");
        }
    }

    template<typename Data>
    Data OrderedDictionaryContainer<Data>::Max() const
    {
        if Empty()
        {
            throw std::length_error("Empty container!");
        }
        Data max;
        ulong i = 0;
        Traverse(
            [this, &](const Data& d)
            {
                if(i==0) max = d;

                if(data>max)
                {
                    max = d;
                }
            }
        );
        return max;
    }  

    template<typename Data>
    Data OrderedDictionaryContainer<Data>::MaxNRemove()
    {
        if Empty()
        {
            throw std::length_error("Empty container!");
        }
    }  

    template<typename Data>
    void OrderedDictionaryContainer<Data>::RemoveMax()
    {
        if Empty()
        {
            throw std::length_error("Empty container!");
        }
    } 

    template<typename Data>
    Data OrderedDictionaryContainer<Data>::Predecessor(Data& d) const
    {
        Data x;
        ulong i = 0;
        Traverse(
            [this, &](const Data& d)
            {
                if(x ==d)
                    return;
                
                i++;
            }
        );

        ulong count = 0;
        Traverse(
            [this, &](const Data& d)
            {
                if(i-1 = count)
                {
                    x = data;
                    return;
                }

                if(count>= size)
                {
                    throw std::length_error("Predecessor not found!");
                }
            }
        )

        return x;
    }

    template<typename Data>
    Data OrderedDictionaryContainer<Data>::PredecessorNRemove(Data& d)
    {

    } 

    template<typename Data>
    void OrderedDictionaryContainer<Data>::RemovePredecessor(Data& d)
    {

    }  

    template<typename Data>
    Data OrderedDictionaryContainer<Data>::Successor(Data& d) const
    {
        Data x;
        ulong i = 0;
        Traverse(
            [this, &](const Data& d)
            {
                if(x ==d)
                    return;
                
                i++;
            }
        );

        ulong count = 0;
        Traverse(
            [this, &](const Data& d)
            {
                if(i+1 = count)
                {
                    x = data;
                    return;
                }

                if(count>= size)
                {
                    throw std::length_error("Successor not found!");
                }
            }
        )

        return x;
    }

    template<typename Data>
    Data OrderedDictionaryContainer<Data>::SuccessorNRemove(Data& d)
    {

    }  

    template<typename Data>
    void OrderedDictionaryContainer<Data>::RemoveSuccessor(Data& d)
    {

    } 


}
