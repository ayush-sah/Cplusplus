#include<iostream>
using namespace std;

class Stack{
    char *stack;
    string str, exp;
    int top;
    public:
    Stack(){
        top = -1;
        cout << "Enter Infix Expression String: ";
        cin >> str;
        str+=')';
        stack = new char[str.length()];
        stack[++top] = '(';
        exp = "";
        for(int i = 0; i < str.length(); i++){

            if(str.at(i)=='(')
                push(str.at(i));

            else if(stack_opreations(str.at(i))==true){
                if(stack[top]!='(' && (value(str.at(i))<value(stack[top]))){
                    exp += pop();
                    push(str.at(i));
                }
                else
                    push(str.at(i));
            }

            else if(str.at(i)==')'){
                while(stack[top]!='(')
                    exp += pop();
                
                pop();
            }        

            else
                exp+=str.at(i);
        }
        cout << exp << endl;
    }
    bool stack_opreations(char c){
        if ((c=='+')||(c=='-')||(c=='*')||(c=='/')||(c=='^'))
            return true;
        else
            return false;
    }
    int value(char op){
        if(op=='^')
            return 4;
        else if(op=='/')
            return 3;
        else if(op=='*')
            return 2;
        else if(op=='+')
            return 1;
        else if(op=='-')
            return 0;
    }
    void push(char c){
        stack[++top] = c;
    }

    char pop(){
        return stack[top--];
    }
};

int main(){
    Stack s;
}