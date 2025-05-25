#include "setlst.hpp"
#include <stdexcept>
namespace lasd {

    template<typename Data>
    SetLst<Data>::SetLst(const TraversableContainer<Data>& c) : List<Data>(c)
    {
       
        size = c.Size();
        Sort();

    } 

    template<typename Data>
    SetLst<Data>::SetLst(MappableContainer<Data>&& c): List<Data>(std::move(c))
    {
        size = c.Size();
        Sort();
    }


    template<typename Data>
    SetLst<Data>::SetLst(const SetLst<Data>& list) 
    {
        for(ulong i = 0; i<list.size; i++)
        {
            Insert(list[i]);
        }
        size = list.Size();
    }

    template<typename Data>
    SetLst<Data>::SetLst(SetLst<Data>&& list)
    {
        this->head = list.head;
        this->tail = list.tail;
        this->size = list.size;

        list.head = nullptr;
        list.tail = nullptr;
        list.size = 0;
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
        
        Clear();

        if(lista.tail != nullptr)
        {
            this->tail = new List<Data>::Node(*lista.tail);
            this->head = lista.head->Clone(this->tail);
            size = lista.size;
        }
            
        return *this;
    }

    template<typename Data>
    SetLst<Data>& SetLst<Data>::operator=(SetLst<Data>&& n)
    {
        std::swap(this->tail, n.tail);
        std::swap(this->head, n.head);
        std::swap(size, n.size);

        return *this;
    }


    template<typename Data>
    bool SetLst<Data>::operator==(const SetLst<Data>& list) const noexcept
    {
       if(size != list.size)
            return false;

        Node* current = this->head;
        Node* currentOther = list.head;

        while(current != nullptr && currentOther != nullptr)
        {
            if(current->data != currentOther->data)
                return false;
            current = current->next;
            currentOther = currentOther->next;
        }

        return (current == nullptr && currentOther == nullptr);
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
        return this->head->data;
    }

    template<typename Data>
    Data SetLst<Data>::MinNRemove()
    {
        if(size == 0)
        {
            throw std::length_error("Empty List!");
        }

        Data min = this->head->data;
        RemoveMin();
        return min;

    }

    template<typename Data>
    void SetLst<Data>::RemoveMin()
    {
        if(size == 0)
        {
            throw std::length_error("Empty List!");
        }

        if(size == 1)
        {
            this->head->next = nullptr;
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            size--;
            return;
        }

        Node* newHead = this->head->next;
        this->head->next = nullptr;
        delete this->head;
        this->head = newHead;
        size--;

    }

    template<typename Data>
    Data SetLst<Data>::Max() const
    {   
        if(size == 0)
        {
            throw std::length_error("Empty List!");
        }

        return this->tail->data;

    }  

    template<typename Data>
    Data SetLst<Data>::MaxNRemove()
    {
        if(size == 0)
        {
            throw std::length_error("Empty List!");
        }

        Data max = this->tail->data;
        RemoveMax();

        return max;
    }  

    template<typename Data>
    void SetLst<Data>::RemoveMax()
    {
        if(size == 0)
        {
            throw std::length_error("Empty List!");
        }

        if(size == 1)
        { 
            this->tail->next = nullptr;
            delete this->tail;
            this->head = nullptr;
            this->tail = nullptr;
            size--;
            return;
        }

        Node* newTail = this->head;
        while(newTail->next != this->tail)
        {
            newTail = newTail->next;
        }
        
        this->tail->next = nullptr;
        delete this->tail;
        newTail->next = nullptr;
        this->tail = newTail;
        size--;
    } 

    template<typename Data>
    Data SetLst<Data>::Predecessor(const Data& d) const
    {
        if(size == 0)
        {
            throw std::length_error("Predecessor not found!");
        }

        for(ulong i = size-1; i>0; i--)
        {
            if(operator[](i) < d)
            {
               return operator[](i);
            }
        }
        throw std::length_error("Predecessor not found!");

     
    }

    template<typename Data>
    Data SetLst<Data>::PredecessorNRemove(const Data& d)
    {
        if(size == 0)
        {
            throw std::length_error("Predecessor not found!");
        }

        if(size == 1)
        {
            throw std::length_error("Predecessor not found!");
        }
        
        
        for(ulong i = size-1; i>0; i--)
        {
            if(operator[](i) < d)
            {
                Node* precN = GetNode(i);
                Node* precPrec = GetNode(i-1);
                Data prec = precN->data;
                precPrec->next = precN->next;
                precN->next = nullptr;
                delete precN;
                size--;
                Sort();
            
                return prec;
            }
            if(i==0)
            {
                break;
            }
        }
        throw std::length_error("Predecessor not found!");

    } 

    template<typename Data>
    void SetLst<Data>::RemovePredecessor(const Data& d)
    {
        if (size < 2) 
        {
            throw std::length_error("Predecessor not found!");
        }

        
        if (!(operator[](0) < d)) 
        {
            throw std::length_error("Predecessor not found!");
        }

        ulong i = 1;
        while (i < size && !(operator[](i) >= d)) 
        {
            i++;
        }

        ulong indexToRemove = i - 1;

        if (indexToRemove == 0) 
        {
            Node* toDelete = this->head;
            this->head = this->head->next;
            toDelete->next = nullptr;
            delete toDelete;
        } else 
        {
            Node* prev = GetNode(indexToRemove - 1);
            Node* toDelete = prev->next;
            prev->next = toDelete->next;
            if (toDelete == this->tail)     
            {
                this->tail = prev;
            }
            toDelete->next = nullptr;
            delete toDelete;
        }

        size--;

    }  

    template<typename Data>
    Data SetLst<Data>::Successor(const Data& d) const
    {
        if(size == 0)
        {
            throw std::length_error("Successor not found!");
        }

        for(ulong i = 0; i<size; i++)
        {
            if(operator[](i) > d)
            {
                return operator[](i);
            }
        }
        throw std::length_error("Successor not found!");
    }

    template<typename Data>
    Data SetLst<Data>::SuccessorNRemove(const Data& d)
    {
        if(size == 0)
        {
            throw std::length_error("Successor not found!");
        }

        Node* newHead = this->head;
        Node* prec = nullptr;

        while(newHead != nullptr)
        {
            if(d < newHead->data)
            {
                if(newHead == this->tail)
                {
                    prec->next = nullptr;
                    Data succ = this->tail->data;
                    delete this->tail;
                    this->tail = prec; 
                    size--;
                    Sort();
                    return succ;
                }else if(newHead == this->head)
                {
                    Data succ = this->head->data;
                    Node* oldHead = this->head;
                    this->head = this->head->next;
                    oldHead->next = nullptr;
                    delete oldHead;
                    size--;
                    Sort();
                    return succ;
                }else
                {
                    Data succ = newHead->data;
                    prec->next = newHead->next;
                    newHead->next = nullptr;
                    delete newHead;
                    size--;
                    Sort();
                    return succ;
                }
            }
            prec = newHead;
            newHead = newHead->next;
        }

        throw std::length_error("Successor not found!");

    }  

    template<typename Data>
    void SetLst<Data>::RemoveSuccessor(const Data& d)
    {
       if(size == 0)
        {
            throw std::length_error("Successor not found!");
        }

        Node* newHead = this->head;
        Node* prec = nullptr;

        while(newHead != nullptr)
        {
            if(d < newHead->data)
            {
                if(newHead == this->tail)
                {
                    prec->next = nullptr;
                    delete this->tail;
                    this->tail = prec;
                    size--;
                    Sort();
                    return;
                }else if(newHead == this->head)
                {
                    Node* oldHead = this->head;
                    this->head = this->head->next;
                    oldHead->next = nullptr;
                    delete oldHead;
                    size--;
                    Sort();
                    return;
                }else
                {
                    prec->next = newHead->next;
                    newHead->next = nullptr;
                    delete newHead;
                    size--;
                    Sort();
                    return;
                }
            }
            prec = newHead;
            newHead = newHead->next;
        }

        throw std::length_error("Successor not found!");
        
    } 

    template<typename Data>
    bool SetLst<Data>::Insert(const Data& d)
    {
       if (Exists(d)) return false;
        size++;

        Node* node = new typename List<Data>::Node(d);

        if (this->head == nullptr) {
            this->head = this->tail = node;
            return true;
        }

        if (d < this->head->data) {
            node->next = this->head;
            this->head = node;
            return true;
        }
        if (d > this->tail->data) {
            this->tail->next = node;
            this->tail = node;
            return true;
        }
        Node* current = this->head->next;
        Node* prec = this->head;

        while (current != nullptr && d > current->data) {
            prec = current;
            current = current->next;
        }

        node->next = current;
        prec->next = node;

        if(current == nullptr)
        {
            this->tail = node;
        }

        return true;
    }

    template<typename Data>
    bool SetLst<Data>::Insert(Data&& d) 
    {
        if (Exists(d)) return false;
        size++;

        Node* node = new typename List<Data>::Node(d);

        if (this->head == nullptr) {
            this->head = this->tail = node;
            return true;
        }

        if (d < this->head->data) {
            node->next = this->head;
            this->head = node;
            return true;
        }
        if (d > this->tail->data) {
            this->tail->next = node;
            this->tail = node;
            return true;
        }
        Node* current = this->head->next;
        Node* prec = this->head;

        while (current != nullptr && d > current->data) {
            prec = current;
            current = current->next;
        }

        node->next = current;
        prec->next = node;

        if(current == nullptr)
        {
            this->tail = node;
        }

        return true;
    }

    template<typename Data>
    bool SetLst<Data>::Remove(const Data& d) 
    {
        if (this->head == nullptr) 
        {
            return false;
        }

        Node* newHead = this->head;
        Node* prev = nullptr;

        while (newHead != nullptr && newHead->data < d) {
            prev = newHead;
            newHead = newHead->next;
        }

       
        if (newHead == nullptr || newHead->data != d)
            return false;

    
        if (newHead == this->head) {
            this->head = this->head->next;
            if (this->tail == newHead)
                this->tail = nullptr;
        }
     
        else if (newHead == this->tail) {
            this->tail = prev;
            prev->next = nullptr;
        }
        
        else {
            prev->next = newHead->next;
        }

        newHead->next = nullptr;
        delete newHead;
        --size;
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
        Node* newHead = this->head;
        while(newHead != nullptr)
        {
            if(i == index)
            {
                break;
            }
            newHead = newHead->next;
            i++;
        }

        return newHead->data;
    }


    template<typename Data>
    bool SetLst<Data>::Exists(const Data& d) const noexcept 
    {
        if(size == 0) return false;
        for(ulong i = 0; i<this->size; i++)
        {
            if(operator[](i)== d)
            {
                return true;
            }
        }
        return false;
    }


    template<typename Data>
    inline void SetLst<Data>::Clear() 
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }


    template<typename Data>
    typename SetLst<Data>::Node* SetLst<Data>::GetNode(const ulong index)
    {
        if(index >= size)
        {
            throw std::out_of_range("Out of range!");
        }
        ulong i = 0;
        Node* newHead = this->head;
        while(newHead != nullptr)
        {
            if(i == index)
            {
                return newHead;
            }
            newHead = newHead->next;
            i++;
        }

        return nullptr;
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
        Node* pivotNode = this->head;
        for (ulong k = 0; k < p; ++k) 
        {
            pivotNode = pivotNode->next;
        }
        Data x = pivotNode->data;

        ulong i = p - 1;
        ulong j = r + 1;

        while (true) 
        {

            do 
            {
                j--;
            } while (x < GetNode(j)->data);

            do 
            {
                i++;
            } while (x > GetNode(i)->data);

            if (i < j) 
            {
                Node* nodeI = GetNode(i);
                Node* nodeJ = GetNode(j);
                std::swap(nodeI->data, nodeJ->data);
            } else 
            {
                return j;
            }
        }
    }

}
