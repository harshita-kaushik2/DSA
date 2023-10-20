//Push Algo : 
1. All elements of s1 -> s2
2. Push new element in s1
3. All elements from s2 -> s1

Jo bhi naya element aaye usko sabse neeche bhejo. Upar walon ko hatao for the process.

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

//IMPROVED VERSION : 
