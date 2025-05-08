#include "traversable.hpp"
namespace lasd {

    template <typename Data>
    template <typename Accumulator>
    Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> x,Accumulator acc) const
    {
        Traverse(
            [x, &acc](const Data& d)
            {
                acc = x(d, acc);
            }
        );
        return acc;
    }

    template <typename Data>
    inline bool TraversableContainer<Data>::Exists(const Data& d) const noexcept 
    {
        bool exists = false;
        Traverse([this, &](const Data& data)
            if(d == data)
            {
                exists = true;
                return;
            }
        );
        return exists;
    }

    
    template <typename Data>
    template <typename Accumulator>
    Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> x, Accumulator acc) const
    {
        PreOrderFold(
            [x, &acc](const Data& d)
            {
                acc = x(d, acc);
            }
        );
        return acc;
    }

    template <typename Data>
    void PreOrderTraversableContainer<Data>::Traverse(TraverseFun& x) const
    {
        PreOrderTraverse(
            [x, &acc](const Data& d)
            {
                acc = x(d, acc);
            }
        );
        return acc;
    }

    template <typename Data>
    template <typename Accumulator>
    Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> x, Accumulator acc) const
    {
        PostOrderFold(
            [x, &acc](const Data& d)
            {
                acc = x(d, acc);
            }
        );
        return acc;
    }

    template <typename Data>
    void PostOrderTraversableContainer<Data>::Traverse(TraverseFun& x) const
    {
        PostOrderTraverse(
            [x, &acc](const Data& d)
            {
                acc = x(d, acc);
            }
        );
        return acc;
    }

}
