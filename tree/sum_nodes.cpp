#include <iostream>


int n;
int *nodes, *lefts, *rights, *numbers;
long long result = 0;

void dfs(int i, int parent = 0){
    numbers[i] = numbers[parent] * 10 + nodes[i];
    if(lefts[i]) dfs(lefts[i], i);
    if(rights[i]) dfs(rights[i], i);
    if(lefts[i]==0 && rights[i]==0) result += (long long) numbers[i];
}

int main(){

    std::cin >> n;
    nodes = new int[n+1];
    lefts = new int[n+1];
    rights = new int[n+1];
    numbers = new int[n+1];
    nodes[0] = 0;

    for(int i=0; i<n; ++i) numbers[i] = 0;
    for(int i = 1; i<n+1;++i){
        int v, l, r;
        std::cin>>v>>l>>r;
        nodes[i] = v;
        lefts[i] = l;
        rights[i] = r;
    }

    dfs(1);
    std::cout<<result;
}