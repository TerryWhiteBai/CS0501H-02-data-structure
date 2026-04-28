#include <iostream>
using namespace std;

int n, m;
bool *visited;
int **graph;

void dfs(int i){
    visited[i] = true;
    for(int j=1; j<n+1; ++j){
        if(graph[i][j] && !visited[j]){
            dfs(j);
        }
    }
}

int main(){
    cin>>n>>m;
    visited = new bool[n+1]();
    
    graph = new int*[n];
    for(int i=0;i<n+1;++i) graph[i] = new int[n+1](); 
    
    for(int i =0; i<m; ++i){
        int u,v;
        cin>>u>>v;
        graph[u][v]++;
        graph[v][u]++;
    }

    int result = 0;

    for(int i=1;i<n+1;++i){
        if(!visited[i]){
            result++;
            dfs(i);
        }
    }
    cout<<result;

}