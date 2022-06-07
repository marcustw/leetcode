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
        lck.unlock();      
        cv.notify_all();
        
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this](){ return rank==2; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        rank=3;
        lck.unlock();      
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this](){ return rank==3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};