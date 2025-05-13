#include "traversable.hpp"
namespace lasd {

    template <typename Data>
    template <typename Accumulator>
    Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> x,Accumulator acc) const
    {
        TraverseFun lambda = [&](const Data& d)
        {
            acc = x(d, acc);
        };
        Traverse(
            lambda
        );
        return acc;
    }

    template <typename Data>
    inline bool TraversableContainer<Data>::Exists(const Data& d) const noexcept 
    {
        bool exists = false;
        TraverseFun lambda = [&](const Data& data){
            if(d == data)
            {
                exists = true;
                return;
            }
        };
        Traverse(
            lambda
        );
        return exists;
    }

    
    template <typename Data>
    template <typename Accumulator>
    Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> x, Accumulator acc) const
    {
        TraverseFun lambda = [&](const Data& d)
        {
            acc = x(d, acc);
        };
        PreOrderTraverse(
            lambda
        );
        return acc;
    }

    template <typename Data>
    void PreOrderTraversableContainer<Data>::Traverse(TraverseFun& x) const
    {
        PreOrderTraverse(x);
        
    }

    template <typename Data>
    template <typename Accumulator>
    Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> x, Accumulator acc) const
    {
        TraverseFun lambda = [&](const Data& d)
        {
            acc = x(d, acc);
        };
        PostOrderTraverse(
           lambda
        );
        return acc;
    }

    template <typename Data>
    void PostOrderTraversableContainer<Data>::Traverse(TraverseFun& x) const
    {
        PostOrderTraverse(x);
    }

}
