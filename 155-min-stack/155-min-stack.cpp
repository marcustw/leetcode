class MinStack {
public:
    class Node {
    public:
        int val;
        int minVal;
        Node* prev;
        
        Node(int val, int minVal, Node* prev) {
            this->val=val;
            this->minVal=minVal;
            this->prev=prev;
        }
        
    };
    
    MinStack::Node* cur=NULL;
    
    MinStack() {}
    
    void push(int val) {
        if (cur==NULL) {
            cur= new MinStack::Node(val, val, NULL);
        } else {
            cur= new MinStack::Node(val, min(cur->minVal, val), cur);
        }
    }
    
    void pop() {
        cur=cur->prev;
    }
    
    int top() {
        return cur->val;
    }
    
    int getMin() {
        return cur->minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */