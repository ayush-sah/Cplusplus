#include<iostream>
#include<string>
using namespace std;
class stack{
    string str;
    int *arr, top, action, i, temp;
    public:
        void postfix(){
            cout << "Enter a string: ";
            getline(cin, str);
            str +=')';
            top = -1;
            if ((isNumber((str.at(0) - '0'))==true) && (isNumber((str.at(1) - '0'))==true)){
                arr = new int[str.length()];
                for(i = 0; str.at(i) != ')'; i++){
                    if(isNumber(str.at(i) - '0')==true){
                        push(str.at(i) - '0');
                    }
                    else if((str.at(i)=='+')||(str.at(i)=='-')||(str.at(i)=='*')||(str.at(i)=='/')){
                        int a = pop();
                        int b = pop();
                        switch (str.at(i)){
                            case '+':
                                push(b+a);
                                break;
                            case '-':
                                push(b-a);
                                break;
                            case '*':
                                push(b*a);
                                break;
                            case '/':
                                push(b/a);
                                break;
                            
                            default:
                                break;
                        }
                    }
                }
                if(top == 0){
                    cout << "Answer= " << arr[0];
                }
                else{
                    cout << "Wrong Postfix operation.";
                }
            }
            else
                cout << "Not a Postfix expression.\n";
        }
        void push(int n){
            if(top==str.length()-1)
                cout << "Error push";
            else
                arr[++top] = n;
        }

        int pop(){
            if(top==-1)
                cout << "Error pop";
            else
                return arr[top--];
        }
        bool isNumber(int n){
            if ((n == 0)||(n == 1)||(n == 2)||(n == 3)||(n == 4)||(n == 5)||(n == 6)||(n == 7)||(n == 8)||(n == 9))
                return true;
            else
                return false;
        }
};

int main(){
    stack s;
    s.postfix();
}