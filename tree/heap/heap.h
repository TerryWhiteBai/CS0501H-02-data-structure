#ifndef _heap_h
#define _heap_h

#include<iostream>
#include<utility>
#include<vector>
// minium heap

template<typename T>
class heap{
private:
    std::vector<T> data;

    int left_child(int i){return 2*i+1;}
    int right_child(int i){return 2*i+2;}
    int parent(int i){return (i-1)/2;}

    void heapify_down(int i){
        while(right_child(i) <= data.size()){
            int min_child = left_child(i);
            if(right_child(i) < data.size() && data[right_child(i)] < data[left_child(i)]) min_child++;

            if(data[i] > data[min_child]) std::swap(data[i], data[min_child]);
            else break;
            i = min_child;
        }
    }

    void heapify_up(int i){
        if(i==0) return;
        if(data[parent(i)] > data[i]){
            std::swap(data[i], data[parent(i)]);
            heapify_up(parent(i));
        }
    }

    bool _helper(int i){
        if(i == 0 || i==2) return true;
        else if(i%2 == 1)return false;
        else return _helper(i/2);
    }

public:
    heap(const std::vector<T> &input){
        data = input;
        for(int i = data.size()/2; i>=0; --i){
            heapify_down(i);
        }
    };


    void push(T val){
        data.push_back(val);
        heapify_up(data.size()-1);

    }

    void pop(){
        std::swap(data.front(), data.back());
        data.pop_back();
        heapify_down(0);
    }

    void print(){
        for(int i = 0; i<data.size();++i){
            if(_helper(i+2)){std::cout<<data[i]<<std::endl;}
            else std::cout<<data[i]<<' ';
        }
    }
    bool empty(){return data.size()==0;}

    T top(){
        if(empty()) throw std::out_of_range("It's empty")

    }
};




#endif