#include <vector>
using namespace std;
class MyQueue {
    vector<int> queue;
public:
    MyQueue() {
    }
    
    void push(int x) {
        queue.push_back(x);
    }
    
    int pop() {
        int temp = queue[0];
        queue.erase(queue.begin());
        return temp;
    }
    
    int peek() {
        if(!this->empty())return queue[0];
    }
    
    bool empty() {
        return queue.empty();
    }
};

/*
class MyQueue {
public:
    stack<int> st;
    MyQueue() {
    }
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> s;
        while(st.size()){
            s.push(st.top());
            st.pop();
        }
        int y = s.top();
        s.pop();
        while(s.size()){
            st.push(s.top());
            s.pop();
        }
        return y;
    }
    
    int peek() {
        stack<int> s;
        while(st.size()){
            s.push(st.top());
            st.pop();
        }
        int y = s.top();
        while(s.size()){
            st.push(s.top());
            s.pop();
        }
        return y;
    }
    
    bool empty() {
        if(st.size()==0) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */*/