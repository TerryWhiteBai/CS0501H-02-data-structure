#include <iostream>
using namespace std;


int n;
int *nodes, *lefts, *rights;


bool is_rightest(int n){
    n = n + 1;
    while(true){
        if(n==1) return true;
        if(n % 2 == 1) return false;
        n /= 2;
    }
}

int main(){

    cin >> n;
    nodes = new int[n+1];
    lefts = new int[n+1];
    rights = new int[n+1];

    for(int i = 1; i<n+1;++i){
        int v, l, r;
        cin>>v>>l>>r;
        nodes[i] = v;
        lefts[i] = l;
        rights[i] = r;
    }

    for(int i =1; i<n+1; ++i){
        if(is_rightest(i)) cout<<0<<'\n';
        else cout<<i+1<<'\n';
    }
}