#include "Queue/queue.h"
#include <iostream>
/*Main function*/
int main(void){

    Queue q;
    
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    
    while(q.getSize())
        std::cout << q.dequeue() << std::endl;

    return 0;
}

