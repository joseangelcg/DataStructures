#ifndef DATA_NODE_H_
#define DATA_NODE_H_

#include <iostream>

/*Helper class for queue node*/
template <class T>
class data_node{
    private:
        T data;
        data_node* next;
    public:
        data_node(T);

        void set_data(T);
        void set_next(data_node*);
        T get_data(void);
        data_node* get_next(void);
};

template <class T>
data_node<T>::data_node(T data){
    this->data = data;
    this->next = NULL;
}

template <class T>
void data_node<T>::set_data(T data){
    this->data = data;
}

template <class T>
void data_node<T>::set_next(data_node* next){
    this->next = next;
}

template <class T>
T data_node<T>::get_data(void){
    return this->data;
}

template <class T>
data_node<T>* data_node<T>::get_next(void){
    return this->next;
}

#endif /*DATA_NODE_H_*/
