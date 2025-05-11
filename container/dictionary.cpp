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


}
