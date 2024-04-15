#include<bits/stdc++.h> 
using namespace std;

class QueueNode {
public: 
    int val;
    QueueNode *next;
    QueueNode(int data) {
        val = data;
        next = NULL;
    }
};  

QueueNode *front = NULL, *rare = NULL;

class Queue {
public:
    int size = 0;
    bool Empty() {
        return front == NULL;
    }
    
    int Peek() {
        if(Empty()) {  
            cout << "Queue is Empty" << endl;
            return -1;
        } 
        else 
            return front->val;
    }
    
    void Enqueue(int value) {
        QueueNode *temp = new QueueNode(value); 
        if (front == NULL) {
            front = temp;
            rare = temp;
        } 
        else {
            rare->next = temp;
            rare = temp;
        }
        cout << value << " Inserted into Queue " << endl;
        size++;
    }

    
    void Dequeue() {
        if (front == NULL) 
            cout << "Queue is Empty" << endl;
        else { 
            cout << front->val << " Removed From Queue" << endl;
            QueueNode *temp = front;
            front = front->next;
            delete temp;
            size--;
        }  
    }
};

int main() {
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout << "The size of the Queue is " << Q.size << endl;
    cout << "The Peek element of the Queue is " << Q.Peek() << endl;
    return 0;
}
