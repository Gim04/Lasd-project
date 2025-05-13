#include "list.hpp"
#include <stdexcept>
namespace lasd {

    template <typename Data>
    List<Data>::Node::Node(Node&& n)
    {
        std::swap(data, n.data);
        std::swap(next, n.next);
    }

    template <typename Data>
    List<Data>::Node::~Node()
    {
        delete next;
    }

    template <typename Data>
    List<Data>::List(const TraversableContainer<Data>& x)
    {
        TraverseFun lambda = [&](const Data& d)
        {
            InsertAtBack(d);
        };
        Traverse(
            lambda
        );
    }

    template <typename Data>
    List<Data>::List(MappableContainer<Data>&& x)
    {
        MapFun lambda = [&](const Data& d)
        {
            InsertAtBack(d);
        };
        Map(
            lambda
        );
    }

    template<typename Data>
    typename List<Data>::Node * List<Data>::Node::Clone(Node* tail) {
        if (next == nullptr) {
            return tail;
        } else {
            Node* node = new Node(data);
            node->next = next->Clone(tail);
            return node;
        }
    }

    template<typename Data>
    List<Data>::List (const List<Data>& node)
    {
        if(node.tail != nullptr)
        {
            tail = new Node(*node.tail);
            head = node.head->Clone(tail);
            size = node.size;
        }
    }

    template<typename Data>
    List<Data>::List (List<Data>&& node)
    {
        if(node.tail != nullptr)
        {
            std::swap(tail, node.tail);
            std::swap(head, node.head);
            std::swap(size, node.size);
        }
    }

    template<typename Data>
    List<Data>& List<Data>::operator=(const List<Data>& lista)
    {
        if(*this != lista)
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
    List<Data>& List<Data>::operator=(List<Data>&& n)
    {
        std::swap(tail, n.tail);
        std::swap(head, n.head);
        std::swap(size, n.size);

        return *this;
    }

    template<typename Data>
    bool List<Data>::operator==(const List<Data>& n) const noexcept
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
    bool List<Data>::operator!=(const List<Data>& n) const noexcept
    {
        return !(*this == n);
    }

    template <typename Data>
    void List<Data>::InsertAtFront(const Data& data)
    {
        Node * node = new Node(data);
        node->next = head;
        head = node;
        if(tail == nullptr)
        {
            tail = head;
        }
        size++;
    }

    template <typename Data>
    void List<Data>::InsertAtFront(Data&& data)
    {
        Node * node = new Node(std::move(data));
        node->next = head;
        head = node;
        if(tail == nullptr)
        {
            tail = head;
        }
        size++;
    }

    template <typename Data>
    void List<Data>::RemoveFromFront()
    {
        if(size == 0)
        {
            throw std::length_error("Empty!");
        }
        Node * newHead = head->next;
        delete head;
        head = newHead;
        size--;
    }

    template <typename Data>
    Data List<Data>::FrontNRemove()
    {
        if(size == 0)
        {
            throw std::length_error("Empty!");
        }

        Data data = head->data;
        Node * newHead = head->next;
        delete head;
        head = newHead;
        size--;

        return data;
    }

    template <typename Data>
    void List<Data>::InsertAtBack(const Data& data)
    {
        Node* newTail = new Node(data);
        if(tail != nullptr)
        {
            tail->next = newTail;
            tail = newTail;
            size++;
        }else
        {
            tail = newTail;
        }
        if(head == nullptr)
        {
            head = tail;
        }
      
    }

    template <typename Data>
    void List<Data>::InsertAtBack(Data&& data)
    {
        Node* newTail = new Node(std::move(data));
        if(tail != nullptr)
        {
            tail->next = newTail;
            tail = newTail;
            size++;
        }else
        {
            tail = newTail;
        }
        if(head == nullptr)
        {
            head = tail;
        }
    } 

    template <typename Data>
    void List<Data>::RemoveFromBack()
    {
        if(tail == nullptr) 
        {
            throw std::length_error("Empty List!");
        }

        Node* newHead = head;
        while(newHead->next != tail)
        {
            newHead = newHead->next;
        }
        delete tail;
        newHead->next = nullptr;
        size--;

    }

    template <typename Data>
    Data List<Data>::BackNRemove()
    {
        if(tail == nullptr) 
        {
            throw std::length_error("Empty List!");
        }

        Data ret = tail->data;

        Node* newHead = head;
        while(newHead->next != tail)
        {
            newHead = newHead->next;
        }
        delete tail;
        newHead->next = nullptr;
        size--;

        return ret;
    } 

    template <typename Data>
    Data& List<Data>::operator[](ulong index)
    {

        if(size == 0)
        {
            throw std::out_of_range("Size exdeed!");
        }

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

    template <typename Data>
    Data& List<Data>::Front()
    {
        if(size == 0)
        {
            throw std::length_error("Empty list!");
        }
        return this->head->data;
    }

    template <typename Data>
    Data& List<Data>::Back()
    {
        if(size == 0)
        {
            throw std::length_error("Empty list!");
        }
        return this->tail->data;
    }

    template <typename Data>
    const Data& List<Data>::operator[](const ulong index) const  
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

    template <typename Data>
    const Data& List<Data>::Front() const
    {   
        if(size == 0)
        {
            throw std::length_error("Empty list!");
        }
        return this->head->data;
    }

    template <typename Data>
    const Data& List<Data>::Back() const
    {
        if(size == 0)
        {
            throw std::length_error("Empty list!");
        }
        return this->tail->data;
    } 
 

    template <typename Data>
    void List<Data>::Map(MapFun x) 
    {
        PreOrderMap(x, head);
    }

 
    template <typename Data>
    void List<Data>::PreOrderMap(MapFun x)  
    {
        PreOrderMap(x, head);
    }

 
    template <typename Data>
    void List<Data>::PostOrderMap(MapFun x) 
    {
        PostOrderMap(x, head);
    }

    template <typename Data>
    void List<Data>::Traverse(TraverseFun x) const
    {
        PreOrderTraverse(x, head);
    }

    template <typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun x) const 
    {
        PreOrderTraverse(x, head);
    }

    template <typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun x) const
    {
        PostOrderTraverse(x, head);
    }

  
    template <typename Data>
    inline void List<Data>::Clear() 
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    template <typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun x, const Node* n) const
    {
        if(n != nullptr)
        {
            x(n->data);
            n = n->next;
        }

    }

    template <typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun x, const Node* n) const
    {
        if(n != nullptr)
        {
            PreOrderTraverse(x, n->next);
            x(n->data);
        }
    }
  
    template <typename Data>
    void List<Data>::PreOrderMap(MapFun x, Node* n) const 
    {
        if(n != nullptr)
        {
            x(n->data);
            n = n->next;
        }
    }

    template <typename Data>
    void List<Data>::PostOrderMap(MapFun x, Node* n) const 
    {
        if(n != nullptr)
        {
            PreOrderMap(x, n->next);
            x(n->data);
        }
    }

}
