#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

/*Helper class for queue node*/
template <class T>
class queue_node{
    private:
        T data;
        queue_node* next;
    public:
        queue_node(T);

        void set_data(T);
        void set_next(queue_node*);
        T get_data(void);
        queue_node* get_next(void);
};

template <class T>
queue_node<T>::queue_node(T data){
    this->data = data;
    this->next = NULL;
}

template <class T>
void queue_node<T>::set_data(T data){
    this->data = data;
}

template <class T>
void queue_node<T>::set_next(queue_node* next){
    this->next = next;
}

template <class T>
T queue_node<T>::get_data(void){
    return this->data;
}

template <class T>
queue_node<T>* queue_node<T>::get_next(void){
    return this->next;
}

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
        T peek(void);
        int getSize(void){return this->size;}
};


template <class T>
Queue<T>::Queue(){
    this->size = 0;
    this->head = this->tail = NULL;
}

template <class T>
void Queue<T>::enqueue(T data){
    queue_node<T>* temp =  new queue_node<T> (data);
    
    if(this->size==0)
        this->head = this->tail = temp;
    else
    {
        ((queue_node<T>*)this->tail)->set_next(temp);
        this->tail = temp;
    }
    this->size++;
}

template <class T>
T Queue<T>::dequeue(void){

    T ret;
    if(this->size>0){
        queue_node<T>* temp;
        temp = (queue_node<T>*)this->head;
        this->head = temp->get_next();
        
        ret = temp->get_data();
        delete temp;
        this->size--;
    }

    return ret;
}

template <class T>
T Queue<T>::peek(void){
    return ((queue_node<T>*)this->head)->get_data();
}



#endif /*QUEUE_H_*/
