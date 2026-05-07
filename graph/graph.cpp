#include "graph.h"

int main(){
    Graph<int> mygraph;
    std::cout<<"\n";
    mygraph.print();
    std::cout<<"\n";
    mygraph.dfs();

    std::cout<<"\n";
    mygraph.bfs();

}