#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){
    string ss;
    getline(cin, ss);

    vector<char> result;
    for(int i = 0; i<ss.length(); ++i){

        if(result.empty()){
            result.push_back(ss[i]);continue;
        }
        
        if(result.back() == ss[i]){
            result.pop_back();
        }else{
            result.push_back(ss[i]);
        }
    }

    for(int i = 0; i<result.size();++i) cout<<result[i];
}