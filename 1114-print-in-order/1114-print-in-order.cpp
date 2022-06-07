class Foo {
private:
    int rank=1;
    mutex mtx;
    condition_variable cv;
    
public:
    Foo() {}

    void first(function<void()> printFirst) {
        unique_lock<mutex> lck(mtx);
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        rank=2;
        cv.notify_all();
        
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mtx);
        while(rank!=2) {
            cv.wait(lck);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        rank=3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mtx);
        while(rank!=3) {
            cv.wait(lck);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};