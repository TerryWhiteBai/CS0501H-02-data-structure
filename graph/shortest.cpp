#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, m, s, t;
    cin>>n>>m>>s>>t;

    queue<int> distance;
    queue<int> nodes;
    bool *visited = new bool[n+1]();
    int **graph = new int*[n+1];
    for(int i=0;i<n+1;++i) graph[i]= new int[n+1]();
    
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        graph[u][v]++;
        graph[v][u]++;
    }

    bool flag = false;

    nodes.push(s);
    distance.push(0);
    visited[s] = true;

    while(!nodes.empty()){
        int u = nodes.front();
        int p = distance.front();

        nodes.pop();
        distance.pop();
        if(u==t){
            flag = true;
            cout<<p;
            break;
        }

        for(int i=1;i<n+1;++i){
            if(i!=u && graph[u][i] && !visited[i]){
                visited[i] = true;
                nodes.push(i);
                distance.push(p+1);
            }
        }

    }

    if(!flag) cout<<-1;

}