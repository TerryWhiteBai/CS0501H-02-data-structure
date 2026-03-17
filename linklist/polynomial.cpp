#include <iostream>


class PolyNode{
    public:
    int coeff;
    int term;
    PolyNode* next;
    PolyNode(int co, int te): coeff(co),term(te),next(nullptr){};
};

void add_node(PolyNode* prev, int co, int te){
    PolyNode *current = new PolyNode(co ,te);
    prev->next = current; 
}


PolyNode* read_poly(){
    PolyNode* head = new PolyNode(0,0);
    PolyNode* p = head;
    while(true){
        int co,te;
        std::cin>>co>>te;
        if(te < 0) break;
        add_node(p, co, te);
        p = p->next;
    }
    std::cout<<"read successfully\n";
    return head->next;
}

void print_poly(PolyNode* poly){
    while(poly->next != nullptr){
        std::cout<<poly->coeff<<'x'<<poly->term<<" + ";
        poly = poly->next;
    }
    std::cout<<poly->coeff<<'x'<<poly->term;
}

PolyNode* plus_poly(PolyNode* a, PolyNode* b){
    PolyNode* result = new PolyNode(0,0);
    PolyNode* p = result;
    while(a!=nullptr || b!=nullptr){
        if(a == nullptr || a->term < b->term){
            add_node(p,b->coeff,b->term);
            b = b->next;
        }
        else if(b==nullptr || b->term < a->term){
            add_node(p,a->coeff,a->term);
            a = a->next;
        }
        else{
            add_node(p,a->coeff + b->coeff, a->term);
            a = a->next;
            b = b->next;
        }
        p = p->next;
    }
    return result->next;
}

//O(n)

int main(){
    PolyNode* a = read_poly();
    PolyNode* b = read_poly();

    print_poly(plus_poly(a,b));
}