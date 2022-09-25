typedef struct Node {
    int val;
    Node* next;
    Node* prev;
    
    Node(int val): val(val) {}
} Node;

class MyCircularQueue {
    int max_size;
    int size;
    Node* front;
    Node* rear;
public:
    MyCircularQueue(int k) {
        max_size = k;
        size = 0;
        front = NULL;
        rear = NULL;
    }
    
    bool enQueue(int value) {
        if (size < max_size) {
            Node* newNode = new Node(value);
            newNode->prev = rear;
            if (size == 0) {
                front = newNode;
            } else {
                rear->next = newNode;
            }
            size++;
            rear = newNode;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if (size > 0) {
            Node* f = front;
            front = front->next;
            size--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if (size > 0) return front->val;
        return -1;
    }
    
    int Rear() {
        if (size > 0) return rear->val;
        return -1;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == max_size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */