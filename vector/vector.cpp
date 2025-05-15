#include "vector.hpp"
namespace lasd {

    template <typename Data>
    Vector<Data>::Vector(const ulong size)
    {
        this->size = size;
        buff = new Data[size];
    }

    template <typename Data>
    Vector<Data>::Vector(const TraversableContainer<Data>& c) : Vector(c.Size())
    {
        ulong i = 0;
        c.Traverse(
            [&](const Data& d)
            {
                buff[i] = d;
                i++;
            }
        );
    } 

    template <typename Data>
    Vector<Data>::Vector(MappableContainer<Data>&& c) : Vector(c.Size())
    {
    
        ulong i = 0;
        c.Map(
            [&](Data& d)
            {
                buff[i] = std::move(d);
                i++;
            }
        );
    }


    template <typename Data>
    Vector<Data>::Vector (const Vector<Data>& v)
    {
        size = v.size;
        buff = new Data[size];
        std::copy(v.buff, v.buff + size, buff);

    }

    template <typename Data>
    Vector<Data>::Vector (Vector<Data>&& v)
    {
        std::swap(size, v.size);
        std::swap(buff, v.buff);

    }

    template <typename Data>
    Vector<Data>::~Vector()
    {
        delete[] buff;
    }

    template <typename Data>
    Vector<Data>& Vector<Data>::operator=(const Vector<Data>& v)
    {
        Vector<Data>* vector = new Vector<Data>(v);
        std::swap(*vector, *this);
        delete vector;
        return *this;

    }

    template <typename Data>
    Vector<Data>&  Vector<Data>::operator=(Vector<Data>&& v)
    {
        std::swap(size, v.size);
        std::swap(buff, v.buff);
        return *this;
    }

    template <typename Data>
    bool Vector<Data>::operator==(const Vector<Data>& x) const noexcept
    {
        if(size == x.size)
        {
            for(ulong i = 0; i<size; i++)
            {
                if(buff[i] != x.buff[i])
                    return false;
            }
        }
        else
        {
            return false;
        }
        return true;
    }

    template <typename Data>
    bool Vector<Data>::operator!=(const Vector<Data>& x) const noexcept
    {
        return !(*this == x);
    }

    template <typename Data>
    Data& Vector<Data>::operator[](ulong index)
    {
        if(index<size)
        {
            return buff[index];
        }

        throw std::out_of_range("Out of bound!");
    }

    template <typename Data>
    Data& Vector<Data>::Front()
    {
        if(buff != nullptr)
        {
            return buff[0];
        }

        throw std::length_error("Empty vector!");
    }
  
    template <typename Data>
    Data& Vector<Data>::Back()
    {
        if(buff != nullptr)
        {
            return buff[size-1];
        }

        throw std::length_error("Empty vector!");
    }
    
  
    template <typename Data>
    const Data& Vector<Data>::operator[](const ulong index) const
    {
        if(index<size)
        {
            return buff[index];
        }

        throw std::out_of_range("Out of bound!");
    }
  
    template <typename Data>
    const Data& Vector<Data>::Front() const
    {
        if(buff != nullptr)
        {
            return buff[0];
        }

        throw std::length_error("Empty vector!");
    }
  
    template <typename Data>
    const Data& Vector<Data>::Back() const
    {
        if(buff != nullptr)
        {
            return buff[size-1];
        }

        throw std::length_error("Empty vector!");
    }
  
    template <typename Data>
    void Vector<Data>::Resize(ulong size) 
    {
        if (size == 0) 
        {
            Clear();
        } else if (this->size != size) 
        {
            Data * tmp = new Data[size] {};
            ulong minsize = (this->size < size) ? this->size : size;
            for (ulong index = 0; index < minsize; ++index) 
            {
                std::swap(buff[index], tmp[index]);
            }
            std::swap(buff, tmp);
            this->size = size;
            delete[] tmp;
        }
    }
  

    template <typename Data>
    inline void Vector<Data>::Clear() 
    {
        delete[] buff;
        buff = nullptr;
        size = 0;
    }
  
    template<typename Data>
    SortableVector<Data>::SortableVector(const ulong size): Vector<Data>(size) {}

    template<typename Data>
    SortableVector<Data>::SortableVector(const TraversableContainer<Data>& c): Vector<Data>(c) {}

    template<typename Data>
    SortableVector<Data>::SortableVector(MappableContainer<Data>&& c): Vector<Data>(std::move(c)) {}

    template<typename Data>
    SortableVector<Data>::SortableVector(const SortableVector<Data>& c): Vector<Data>(c) {}

    template<typename Data>
    SortableVector<Data>::SortableVector(SortableVector<Data>&& c): Vector<Data>(std::move(c)) {}

    template<typename Data>
    SortableVector<Data> & SortableVector<Data>::operator=(const SortableVector<Data> & c) 
    {
        Vector<Data>::operator=(c);
        return *this;
    }

    template<typename Data>
    SortableVector<Data> & SortableVector<Data>::operator=(SortableVector<Data> && c)
    {
        Vector<Data>::operator=(std::move(c));
        return *this;
    }

}
