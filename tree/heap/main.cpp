#include "heap.h"

bool _helper(int i){
        if(i == 0) return true;
        if(i%2 == 1)return false;
        return _helper(i/2);
    }

int main(){
    std::vector<int> input = {50, 23, 23, 4, 12, 9 ,24, 45, 65, 45};
    heap<int> test(input);

    test.push(1);
    test.pop();
    test.pop();
    test.print();

}