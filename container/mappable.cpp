#include "mappable.hpp"
namespace lasd {

    template <typename Data>
    void PreOrderMappableContainer<Data>::Map(MapFun x) 
    {
        PreOrderMap(x);
    }

    template <typename Data>
    void PostOrderMappableContainer<Data>::Map(MapFun x) 
    {
        PostOrderMap(x);
    }
}
