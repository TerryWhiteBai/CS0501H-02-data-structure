#ifndef _queue_h
#define _queue_h
template <typename T>
class Queue{
private:
    int _front;
    int _rear;
    int _size;
    int _capacity;
    T *data; 
    void expand(){
        T *tmp = data;
        data = new T[_capacity*2];
        int i = 0;
        while(_rear%_capacity + 1 != _front){
            data[++i] = tmp[++_front];
        }
        _capacity *= 2;
        _front = 0;
        _rear = i;
        delete []data;
    }
public:
    Queue(): _front(0), _rear(0), _capacity(3),_size(0){
        data = new T[_capacity];
    }
    Queue(Queue& other){
        data = new T[other._capacity];
        _size = other._size;
        int p = other._front;

        for(int i=0;i<other._size;++i){
            data[i] = other.data[(p+1)%_capacity];
            ++p;
        }
    }
    ~Queue(){delete []data;}
    bool is_empty(){return _front==_rear;}
    bool is_full(){return _front == (_rear+1) % _capacity + 1;}
    void push(T a){
        if(is_full()) expand();
        data[_rear = (_rear + 1)%_capacity] = a;
        ++_size;
    }

    T pop(){
        _front = (_front+1)%_capacity;
        return data[_front];
        --_size;
    }

    T head(){return data[(_front+1)%_capacity];}
};
#endif