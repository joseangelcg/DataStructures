#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include "prv/data_node.h"

/*Stack class*/
template <class T>
class Stack{
    private:
        int size;
        void* head;
    public:
        Stack();
        void push(T);
        T pop(void);
        T top(void);
        int getSize(void){return this->size;}
        bool isEmpty(void){return (this->size == 0);}
};


template <class T>
Stack<T>::Stack(){
    this->size = 0;
    this->head = NULL;
}

template <class T>
void Stack<T>::push(T data){
    data_node<T>* temp =  new data_node<T> (data);
    
    if(this->size==0)
        this->head = temp;
    else
    {
        temp->set_next(((data_node<T>*)this->head));
        this->head = temp;
    }
    this->size++;
}

template <class T>
T Stack<T>::pop(void){

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
T Stack<T>::top(void){
    return ((data_node<T>*)this->head)->get_data();
}
#endif /*STACK_H_*/
