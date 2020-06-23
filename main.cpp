#include "Queue/queue.h"
#include <iostream>
#include <string>

/*Main function*/
using namespace std;

int main(void){

    Queue<int> q;
    Queue<double> q2;
    Queue<string> qs;
    
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    
    while(q.getSize())
        cout << q.dequeue() << endl;

    cout << endl;
    
    q2.enqueue(2.455);
    q2.enqueue(4.35);
    q2.enqueue(0.23546);
    q2.enqueue(5.3546);
    q2.enqueue(10.00201);
    
    while(q2.getSize())
        cout << q2.dequeue() << endl;

    cout << endl;

    qs.enqueue("Holi");
    qs.enqueue("Este es");
    qs.enqueue("Un mensaje");
    qs.enqueue("Del futuro");
    qs.enqueue("Adios");
    
    while(qs.getSize())
        cout << qs.dequeue() << endl;
    return 0;
}

