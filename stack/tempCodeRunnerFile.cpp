#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;

    int *golems = new int[n];
    for(int i=0;i<n;++i) cin>>golems[i];

    stack<int> survives;
    
    for(int i = 0; i<n; ++i){
        bool win = false;
        if(survives.empty()) {survives.push(golems[i]);continue;}
        if((survives.top() ^ golems[i]) >= 0 || survives.top()<0 && golems[i]>0) {survives.push(golems[i]);continue;}

        while(!survives.empty() && survives.top()>0 &&  golems[i]< 0){
            if(abs(survives.top()) > abs(golems[i])) {win = false; break;}
            else if(abs(survives.top()) == abs(golems[i])) {win = false; survives.pop();break;}
            else {survives.pop();win = true;}
        }

        if(win) survives.push(golems[i]);
    }

    int z = survives.size();

    if(z==0) cout<<"Empty";
    
    int *output = new int[z];
    for(int i = z-1; i>=0; --i){
        output[i] = survives.top();
        survives.pop();
    }

    for(int i = 0;i<z;++i) cout<<output[i]<<' ';
}