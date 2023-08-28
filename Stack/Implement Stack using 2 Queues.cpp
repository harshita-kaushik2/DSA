// Push Algorithm : 
1. Push into q2
2. Pop every element from q1 to q2
3. Swap elements from q2 to q1.


class MyStack {
public:
    queue<int> q1, q2;
    MyStack() { }
    
    void push(int x) {
        q2.push(x);
        while( !q1.empty() ) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q2,q1);
    }
    
    int pop() {
        int a = q1.front();
        q1.pop();
        return a;
    }
    
    int top() {
       return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};