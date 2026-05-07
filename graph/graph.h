#include <iostream>
#include <vector>
#include <queue>

class Edge{
public:
    int con_pt;
    Edge* next;
    Edge(int x): con_pt(x), next(nullptr){};
};

template <typename T>
class Vertex{
public:
    T data;
    Edge* e;
    Vertex(T x=0): data(x), e(nullptr){};
};

template <typename Tv>
class Graph{
private:
    std::vector<bool> visited;

    void _dfs(int i){
        if(visited[i]) return;
        visited[i] = true;
        std::cout<<i<<" : "<<datalist[i]->data<<'\n';

        Edge* p = datalist[i]->e;
        while(p){
            if(!visited[p->con_pt]){
                _dfs(p->con_pt);
            }
            p = p->next;
        }
    }


    void _bfs(int k){
        std::queue<int> q;
        q.push(k);
        visited[k] = true;
        while(!q.empty()){
            int i= q.front();
            q.pop();
            std::cout<<i<<" : "<<datalist[i]->data<<'\n';

            Edge* p = datalist[i]->e;
            while(p){
                if(!visited[p->con_pt]){
                    q.push(p->con_pt);
                    visited[p->con_pt] = true;
                }
                p = p->next;
            }
        }
    }
    

public:
    int n,m;
    std::vector<Vertex<Tv>*> datalist;
    Graph(){
        std::cin>>n>>m;
        visited = std::vector<bool>(n+1, false);
        datalist.reserve(n+1);
        for(int i=1; i<n+1; ++i){
            datalist[i] = new Vertex<Tv>;
            std::cin>>datalist[i]->data;
        }

        for(int i=0; i<m; ++i){
            int u, v;
            std::cin>>u>>v;
            Edge* tmp = new Edge(v);
            tmp->next = datalist[u]->e;
            datalist[u]->e = tmp;

            Edge* tmp2 = new Edge(u);
            tmp2->next = datalist[v]->e;
            datalist[v]->e = tmp2;
        }
        
    }

    void print(){
        for(int i=1; i<n+1;++i){
            std::cout<<i<<' ';
            Edge* p = datalist[i]->e;
            while(p){
                std::cout<<p->con_pt<<' ';
                p = p->next;
            }
            std::cout<<'\n';
            
        }
    }

    void add_edge(int u, int v){
            Edge* tmp = new Edge(v);
            tmp->next = datalist[u]->e;
            datalist[u]->e = tmp;

            Edge* tmp2 = new Edge(u);
            tmp2->next = datalist[v]->e;
            datalist[v]->e = tmp2; 
    }

    void dfs(){
        for(int i=1;i<n+1;++i){
            _dfs(i);
        }
        visited = std::vector<bool>(n+1, false);
    }

    void bfs(){
        for(int i=1;i<n+1;++i){
            if(!visited[i]) _bfs(i);
        }
        visited = std::vector<bool>(n+1, false);
    }
};