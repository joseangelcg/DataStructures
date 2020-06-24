#include "Queue/queue.h"
#include "Stack/stack.h"
#include <iostream>
#include <string>

/*Main function*/
using namespace std;

int main(void){

    Queue<int> q;
    Queue<double> q2;
    Stack<string> st;
    
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    
    while(!q.isEmpty())
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

    st.push("Holi");
    st.push("Este es");
    st.push("Un mensaje");
    st.push("Del futuro");
    st.push("Adios");
    
    while(st.getSize())
    {
        cout << st.top() << endl;
        cout << st.pop() << endl;
    }
    return 0;
}

