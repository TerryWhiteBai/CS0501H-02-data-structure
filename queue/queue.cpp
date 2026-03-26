#include "queue.h"
#include <iostream>

int main(){
    Queue<int> test; 
    test.push(2);
    test.push(2);
    test.push(2);
    test.push(2);
    test.push(2);
    std::cout<<test.pop()<<std::endl;
}