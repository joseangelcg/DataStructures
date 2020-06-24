#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include "prv/data_node.h"

/*Queue class*/
template <class T>
class Queue{
    private:
        int size;
        void* head;
        void* tail;
    public:
        Queue();
        void enqueue(T);
        T dequeue(void);
        T front(void);
        T back(void);
        int getSize(void){return this->size;}
        bool isEmpty(void){return (this->size == 0);}
};


template <class T>
Queue<T>::Queue(){
    this->size = 0;
    this->head = this->tail = NULL;
}

template <class T>
void Queue<T>::enqueue(T data){
    data_node<T>* temp =  new data_node<T> (data);
    
    if(this->size==0)
        this->head = this->tail = temp;
    else
    {
        ((data_node<T>*)this->tail)->set_next(temp);
        this->tail = temp;
    }
    this->size++;
}

template <class T>
T Queue<T>::dequeue(void){

    T ret;
    if(this->size>0){
        data_node<T>* temp;
        temp = (data_node<T>*)this->head;
        this->head = temp->get_next();
        
        ret = temp->get_data();
        delete temp;
        this->size--;
    }

    return ret;
}

template <class T>
T Queue<T>::front(void){
    return ((data_node<T>*)this->head)->get_data();
}

template <class T>
T Queue<T>::back(void){
    return ((data_node<T>*)this->tail)->get_data();
}
#endif /*QUEUE_H_*/
