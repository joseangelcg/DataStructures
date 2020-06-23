#ifndef QUEUE_H_
#define QUEUE_H_

/*Queue class*/
class Queue{
    private:
        int size;
        void* head;
        void* tail;
    public:
        Queue();
        void enqueue(int);
        int dequeue(void);
        int peek(void);
        int getSize(void){return this->size;}
};


#endif /*QUEUE_H_*/
