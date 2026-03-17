#include <iostream>
#include <string>
#include "myvector.h"

Vector<int> read_int(){
    Vector<int> results;
    std::string digits;
    std::cin>>digits;
    for(char c: digits){
        results.append((int)(c-'0'));
    }
    results.reverse();
    return results;
} 

Vector<int> plus_int(Vector<int> a, Vector<int>b){
    int carry = 0;
    int i,j;
    i = j = 0;
    Vector<int> result;
    while(i<a.size() || j<b.size() || carry){
        if(i>=a.size() && j < b.size()){
            result.append((b[j]+carry)%10);
            carry = (b[j]+carry)/10;
            ++j;
        }
        else if(i<a.size() && j>=b.size()){
            result.append((a[i] + carry)%10);
            carry = (a[i] + carry)/10;
            ++i;
        }
        else if(i<a.size() && j<b.size()){
            result.append((a[i] + b[j] + carry)%10);
            carry = (a[i] + b[j] + carry)/10; 
            ++i; ++j;
        }
        else{
            result.append(carry);
            carry = 0;
        }
    }
    return result;
}

void print_result(Vector<int> v){
    v.reverse();
    for(int i = 0; i<v.size();++i){
        std::cout<<v[i];
    }
}

int main(){
    Vector<int> a = read_int();
    Vector<int> b = read_int();

    print_result(plus_int(a,b));
}