#include "queue.h"
#include <iostream>

/*Helper class for queue node*/
class queue_node{
    private:
        int data;
        queue_node* next;
    public:
        queue_node(int);

        void set_data(int);
        void set_next(queue_node*);
        int get_data(void);
        queue_node* get_next(void);
};

queue_node::queue_node(int data){
    this->data = data;
    this->next = NULL;
}

void queue_node::set_data(int data){
    this->data = data;
}

void queue_node::set_next(queue_node* next){
    this->next = next;
}

int queue_node::get_data(void){
    return this->data;
}

queue_node* queue_node::get_next(void){
    return this->next;
}

/*Queue class*/
class Queue{
    private:
        int size;
        queue_node* head;
        queue_node* tail;
    public:
        Queue();
        void enqueue(int);
        int dequeue(void);
        int peek(void);
        int getSize(void){return this->size;}
};

Queue::Queue(){
    this->size = 0;
    this->head = this->tail = NULL;
}

void Queue::enqueue(int data){
    queue_node* temp =  new queue_node(data);
    
    if(this->size==0)
        this->head = this->tail = temp;
    else
        this->tail = temp;

    size++;
}

int Queue::dequeue(void){

    int ret = -1;
    if(this->size>0){
        queue_node* temp;
        temp = this->head;
        this->head = temp->get_next();
        
        ret = temp->get_data();
        delete temp;
        size--;
    }

    return ret;
}

int Queue::peek(void){
    return (this->head)->get_data();
}

/*Main function*/
int main(void){

    Queue q;
    
    q.enqueue(5);
    std::cout << q.peek() << std::endl;

    std::cout << q.getSize() << std::endl;
    return 0;
}
