#ifndef DLINKEDLIST_H_
#define DLINKEDLIST_H_

#include <iostream>
#include <string>
#include "../prv/Ddata_node.h"

/*DLinkedList class*/
template <class T>
class DLinkedList{
    private:
        Ddata_node<T>* head;
        Ddata_node<T>* search_node(T);

    public:
        DLinkedList();
        void Insert(T);
        void append(T);
        void Delete(T);
        bool search(T);
        void print(void);
};

template <class T>
DLinkedList<T>::DLinkedList(){
    this->head = NULL;
}

template <class T>
Ddata_node<T>* DLinkedList<T>::search_node(T data)
{
    Ddata_node<T>* temp = this->head;
    while(temp != NULL && temp->get_data() != data)
        temp = temp->get_next();

    return temp;
}

template <class T>
bool DLinkedList<T>::search(T data)
{
    Ddata_node<T> *temp;

    temp = this->search_node(data);
    return (temp != NULL ? true : false);
}

template <class T>
void DLinkedList<T>::Insert(T data)
{
    Ddata_node<T> *temp = new Ddata_node<T>(data);

    temp->set_next(this->head);
    temp->set_prev(NULL);
    this->head = temp;
}

template <class T>
void DLinkedList<T>::append(T data)
{
    Ddata_node<T> *temp = new Ddata_node<T>(data);
    
    if(this->head == NULL)
    {
        this->Insert(data);
    }
    else
    {
        Ddata_node<T> *last = this->head;

        while(last->get_next() != NULL)
            last= last->get_next();

        last->set_next(temp);
        temp->set_prev(last);
    }
}

template <class T>
void DLinkedList<T>::Delete(T data)
{
    Ddata_node<T>* temp = this->head;

    while(temp != NULL)
    {
        if(temp->get_data() == data)
        {
            /*found it*/
            if(temp->get_prev() == NULL)
            {
                this->head = temp->get_next();
                (this->head)->set_prev(NULL);
            }
            else if(temp->get_next() == NULL)
            {
                (temp->get_prev())->set_next(NULL);
            }
            else
            {
                (temp->get_prev())->set_next(temp->get_next());
                (temp->get_next())->set_prev(temp->get_prev());
            }
            /*deallocate node*/
            delete temp;

            return;
        }
        temp = temp->get_next();
    }
}

template <class T>
void DLinkedList<T>::print(void)
{
    Ddata_node<T>* temp = this->head;

    while(temp != NULL)
    {
        std::cout << temp->get_data() << " <=> ";
        temp = temp->get_next();
    }
    std::cout << std::endl;
}

#endif /*DLINKEDLIST_H_*/
