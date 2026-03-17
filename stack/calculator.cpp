#include "stack.h"
#include <iostream>
#include <string>
#include <cmath>

enum token {OPAREN, ADD, SUB, MULTI, DIV, EXP, CPAREN, VALUE, EOL};
class Calculator{
private:
    std::string expression;
    int index;
    double value;
    Stack<token> opstack;
    Stack<double> datastack;

    token get_op(double &value); // related to index, get token
    void binary_op(token op); // calcualte and refresh datastack

public:
    Calculator(std::string exp): expression(exp), index(0), value(0){};
    ~Calculator(){};
    int result(){
        token lastop;
        while((lastop = get_op(value)) != EOL){
            switch (lastop){
                case VALUE: datastack.push(value);break;
                case OPAREN: opstack.push(OPAREN);break;
                case ADD: case SUB: while(!opstack.is_empty() && opstack.top() >= ADD) binary_op(opstack.pop()); opstack.push(lastop);break;
                case DIV: case MULTI: while(!opstack.is_empty() && opstack.top() >= MULTI) binary_op(opstack.pop()); opstack.push(lastop);break;
                case EXP: while(!opstack.is_empty() && opstack.top() > EXP) binary_op(opstack.pop()); opstack.push(lastop);break;
                case CPAREN: while(!opstack.is_empty() && opstack.top() != OPAREN) binary_op(opstack.pop()); opstack.pop();break;
                default: std::cout<<"something unknow"<<std::endl;exit(1);
            }
        }

        while(!opstack.is_empty()){
            binary_op(opstack.pop());
        } 
        return datastack.pop();
    };
};

token Calculator::get_op(double &value){
    value = 0;
    while(index < expression.length() && expression[index] == ' ') ++index;
    if(index == expression.length()) return EOL;

    if(expression[index] >= '0' && expression[index] <= '9'){
        while(index < expression.length() && expression[index] >= '0' && expression[index] <= '9'){
            value = value * 10 + (expression[index++] - '0');
        }
        return VALUE;
    }

    switch (expression[index++]){
        case '(': return OPAREN;
        case '+': return ADD;
        case '-': return SUB;
        case '*': return MULTI;
        case '/': return DIV;
        case '^': return EXP;
        case ')': return CPAREN;
    }
}

void Calculator::binary_op(token op){
    double a,b; 
    b = datastack.pop();
    a = datastack.pop();

    switch(op){
        case ADD: datastack.push(a+b);break;
        case SUB: datastack.push(a-b);break;
        case MULTI: datastack.push(a*b);break;
        case DIV: datastack.push(a/b);break;
        case EXP: datastack.push(std::pow(a,b));break;
    }
}


int main(){
    while(true){
        std::string expression;
        std::cout<<"write your express or press q to quit\n";
        getline(std::cin, expression);
        if(expression == "q") break;
        Calculator solver(expression);
        std::cout<<solver.result()<<std::endl;
    }
}