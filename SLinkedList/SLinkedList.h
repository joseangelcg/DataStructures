#ifndef SLINKEDLIST_H_
#define SLINKEDLIST_H_

#include <iostream>
#include <string>
#include "../prv/data_node.h"

/*SLinkedList class*/
template <class T>
class SLinkedList{
    private:
        data_node<T>* head;
        data_node<T>* search_node(T);

    public:
        SLinkedList();
        void Insert(T);
        void append(T);
        void Delete(T);
        bool search(T);
        void print(void);
};

template <class T>
SLinkedList<T>::SLinkedList(){
    this->head = NULL;
}

template <class T>
data_node<T>* SLinkedList<T>::search_node(T data)
{
    data_node<T>* temp = this->head;
    while(temp != NULL && temp->get_data() != data)
        temp = temp->get_next();

    return temp;
}

template <class T>
bool SLinkedList<T>::search(T data)
{
    data_node<T> *temp;

    temp = this->search_node(data);
    return (temp != NULL ? true : false);
}

template <class T>
void SLinkedList<T>::Insert(T data)
{
    data_node<T> *temp = new data_node<T>(data);

    temp->set_next(this->head);
    this->head = temp;
}

template <class T>
void SLinkedList<T>::append(T data)
{
    data_node<T> *temp = new data_node<T>(data);
    
    if(this->head == NULL)
    {
        this->Insert(data);
    }
    else
    {
        data_node<T> *last = this->head;

        while(last->get_next() != NULL)
            last= last->get_next();

        last->set_next(temp);
    }
}

template <class T>
void SLinkedList<T>::Delete(T data)
{
    data_node<T>* temp = this->head;
    data_node<T>* prev = NULL;

    while(temp != NULL)
    {
        if(temp->get_data() == data)
        {
            /*found it*/
            if(prev == NULL)
                this->head = temp->get_next();
            else
                prev->set_next(temp->get_next());

            /*deallocate node*/
            delete temp;

            return;
        }

        prev = temp;
        temp = temp->get_next();
    }
}

template <class T>
void SLinkedList<T>::print(void)
{
    data_node<T>* temp = this->head;

    while(temp != NULL)
    {
        std::cout << temp->get_data() << " =>";
        temp = temp->get_next();
    }
    std::cout << std::endl;
}

#endif /*SLINKEDLIST_H_*/
