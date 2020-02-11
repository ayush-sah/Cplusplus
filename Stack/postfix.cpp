#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class stack{
    private:
    string str[100];
    int arr, top, action, i, temp;
    public:
        stack(){
            cout << "Enter a string: ";
            i=0;
            
            while (cin.peek()!='\n')
                cin >> str[i++];
            str[i++]=')';

            top = -1;
            if ((isNumber((str[0] - '0'))==true) && (isNumber((str[1] - '0'))==true)){
                arr = new int[str.length()];
                for(i = 0; str[i] != ')'; i++){
                    if(isNumber(str[i] - '0')==true){
                        push(str[i] - '0');
                    }
                    else if((str[i] == '+')||(str[i] == '-')||(str[i] == '*')||(str[i] == '/')){
                        int a = pop();
                        int b = pop();
                        switch (str[i]){
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
}