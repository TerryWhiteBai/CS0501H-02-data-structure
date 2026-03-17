#ifndef _stack_h
#define _stack_h
#include <iostream>

template <typename T>
class Stack
{
private:
    int _top = -1;
    int capacity;
    T *data;

    void expand(){
        T* tmp = data;
        data = new T[capacity *= 2];
        for(int i=0; i<=_top+1; ++i) data[i] = tmp[i];
        delete []tmp;
    }

    void shrink(){
        T* tmp = data;
        data = new T[capacity /= 2];
        for(int i=0; i<=_top+1; ++i) data[i] = tmp[i];
        delete []tmp;
    }

public:
    Stack(int c = 3): capacity(c){
        data = new T[capacity];
    };

    bool is_empty(){return _top==-1;}

    int size(){return _top+1;}

        
    void push(T x){
        if(_top+1 == capacity) expand();
        data[++_top] = x;
    }

    T top(){
        if(is_empty()) throw "error";
        else return data[_top];
    }

    T pop(){
        return data[_top--];
    }

    void print(){
        for(int i=0; i<=_top; ++i){std::cout<<data[i]<<' ';}
    }
};
    

    
#endif