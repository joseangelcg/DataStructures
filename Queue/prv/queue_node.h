#ifndef QUEUE_NODE_H_
#define QUEUE_NODE_H_

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

#endif /*QUEUE_NODE_H_*/
