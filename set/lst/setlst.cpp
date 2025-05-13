#include "setlst.hpp"
#include <stdexcept>
namespace lasd {

    template<typename Data>
    SetLst<Data>::SetLst(const TraversableContainer<Data>& c) : List<Data>(c)
    {
       
        size = c.Size();
    } 

    template<typename Data>
    SetLst<Data>::SetLst(MappableContainer<Data>&& c): List<Data>(c)
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
            throw std::length_error("Empty List!");
        }
        return head->data;
    }

    template<typename Data>
    Data SetLst<Data>::MinNRemove()
    {
        if(size == 0)
        {
            throw std::length_error("Empty List!");
        }

        Data min = head->data;
        Node* newHead = head->next;
        delete head;
        size--;
        head = newHead;

        return min;

    }

    template<typename Data>
    void SetLst<Data>::RemoveMin()
    {
        if(size == 0)
        {
            throw std::length_error("Empty List!");
        }

        Node* newHead = head->next;
        delete head;
        size--;
        head = newHead;

    }

    template<typename Data>
    Data SetLst<Data>::Max() const
    {   
        if(size == 0)
        {
            throw std::length_error("Empty List!");
        }

        return tail->data;

    }  

    template<typename Data>
    Data SetLst<Data>::MaxNRemove()
    {
        if(size == 0)
        {
            throw std::length_error("Empty List!");
        }

        Node* newTail = head;
        while(newHead->next != tail)
        {
            newTail = newHead->next;
        }

        Data max = tail->data;
        newTail->next = nullptr;
        delete tail;
        size--;
        tail = newTail;

        return max;
    }  

    template<typename Data>
    void SetLst<Data>::RemoveMax()
    {
        if(size == 0)
        {
            throw std::length_error("Empty List!");
        }

        Node* newTail = head;
        while(newHead->next != tail)
        {
            newTail = newHead->next;
        }
        
        newTail->next = nullptr;
        delete tail;
        size--;
        tail = newTail;
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

        if(index==1)
        {
            return MinNRemove();
        }

        ulong i = 0;
        Data dat;
        Node* newHead = head;
        while(newHead != nullptr)
        {
            if(i == index-2)
            {
                dat = newHead->next->data;        //prec
                Node* curr = newHead->next->next; //curr 
                newHead->next = curr;             //prec di prec
                delete newHead->next;
                break;
            }
            newHead = newHead->next;
            i++;
        }

        size--;
        
        return dat;
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

        if(index==1)
        {
            RemoveMin()
            return;
        }
        ulong i = 0;    
        Node* newHead = head;
        while(newHead != nullptr)
        {
            if(i == index-2)
            {
                Node* curr = newHead->next->next; //curr 
                newHead->next = curr;             //prec di prec
                delete newHead->next;
                break;
            }
            newHead = newHead->next;
            i++;
        }

        size--;
        
        
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

        if(index == size-2)
        {
            return MaxNRemove();
        }

        ulong i = 0;
        Data dat;
        Node* newHead = head;
        while(newHead != nullptr)
        {
            if(i == index)
            {
                dat = newHead->next->data;        //succ
                Node* curr = newHead->next->next; //curr 
                newHead->next = curr;             //succ di succ
                delete newHead->next;
                break;
            }
            newHead = newHead->next;
            i++;
        }

    
        size--;
        
        return data;
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
            throw std::length_error("successor not found!");
        }

        if(index == size-2)
        {
            RemoveMax();
            return;
        }

        ulong i = 0;
        Node* newHead = head;
        while(newHead != nullptr)
        {
            if(i == index)
            {       
                Node* curr = newHead->next->next; //curr 
                newHead->next = curr;             //succ di succ
                delete newHead->next;
                break;
            }
            newHead = newHead->next;
            i++;
        }

    
        size--;
        
    } 

    template<typename Data>
    bool SetLst<Data>::Insert(const Data& d)
    {
        if(Exists(d)) return false;
        size++;

        Node* node = new Node(data);

        if(node->data < head->value)
        {
            node->next = head;
            head = node;
            return true;
        }else if(node->data > tail->data)
        {
            tail->next = node;
            tail = node;
            return true;
        }

        Node* prec = nullptr;
        Node* newHead = head;
        while(newHead != nullptr)
        {
            if(node->data < newHead->data)
            {       
                prec->next = node;
                node->next = newHead;
            }
            prec = newHead;
            newHead = newHead->next;
            i++;
        }

        return true;

    }

    template<typename Data>
    bool SetLst<Data>::Insert(Data&& d) 
    {
        if(Exists(d)) return false;
        size++;

        Node* node = new Node(data);

        if(node->data < head->value)
        {
            node->next = head;
            head = node;
            return true;
        }else if(node->data > tail->data)
        {
            tail->next = node;
            tail = node;
            return true;
        }

        Node* prec = nullptr;
        Node* newHead = head;
        while(newHead != nullptr)
        {
            if(node->data < newHead->data)
            {       
                prec->next = node;
                node->next = newHead;
            }
            prec = newHead;
            newHead = newHead->next;
            i++;
        }

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
        
        
        Node* node = GetNode(index);


        if(node == head)
        {
            RemoveMin();
            return true;
        }else if(node == tail)
        {
            RemoveMax();
            return true;    
        }

        Node* prec = nullptr;
        Node* newHead = head;
        while(newHead != nullptr)
        {
            if(node == newHead)
            {       
                prec->next = newHead->next;
                delete newHead;
                break;
            }
            prec = newHead;
            newHead = newHead->next;
            i++;
        }
        size--;
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
    List<Data>::Node* SetLst<Data>::GetNode(const ulong index)
    {
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

        return newHead;
    }

}
