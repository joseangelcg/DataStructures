#ifndef DDATA_NODE_H_
#define DDATA_NODE_H_

#include <iostream>

/*Helper class for queue node*/
template <class T>
class Ddata_node{
    private:
        T data;
        Ddata_node* next;
        Ddata_node* prev;
    public:
        Ddata_node(T);

        void set_data(T);
        void set_next(Ddata_node*);
        void set_prev(Ddata_node*);
        T get_data(void);
        Ddata_node* get_next(void);
        Ddata_node* get_prev(void);
};

template <class T>
Ddata_node<T>::Ddata_node(T data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

template <class T>
void Ddata_node<T>::set_data(T data){
    this->data = data;
}

template <class T>
void Ddata_node<T>::set_next(Ddata_node* next){
    this->next = next;
}

template <class T>
void Ddata_node<T>::set_prev(Ddata_node* prev){
    this->prev = prev;
}

template <class T>
T Ddata_node<T>::get_data(void){
    return this->data;
}

template <class T>
Ddata_node<T>* Ddata_node<T>::get_next(void){
    return this->next;
}

template <class T>
Ddata_node<T>* Ddata_node<T>::get_prev(void){
    return this->prev;
}

#endif /*DDATA_NODE_H_*/
