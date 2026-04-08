#include <iostream>
using namespace std;

class Treenode{
public:
    int val;
    Treenode *left = nullptr;
    Treenode *right;
    Treenode(int v = 0, Treenode *r = nullptr): val(v), right(r){}
};

int n;
Treenode *current = new Treenode();
int *nodes, *lefts, *rights;

void add_nodes(Treenode *p, int v){
    Treenode *node = new Treenode(v);
    p->right = node;
}

void dfs(int i = 1){
    add_nodes(current, nodes[i]);
    current = current->right;
    if(lefts[i]) dfs(lefts[i]);
    if(rights[i]) dfs(rights[i]);
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

    Treenode *head = current;
    dfs();
    Treenode *result = head->right;
    while(result != nullptr){
        cout<<result->val<<' ';
        result = result->right;
    }
}