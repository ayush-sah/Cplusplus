#include<iostream>
#include<string>
using namespace std;

class stack{
    int size, top, action, i;
    string str;
    char *arr;

    public:
        void balancing(){
            top=-1;
            
            cout << "Enter a string: ";
            cin >> str;

            arr = new char[str.length()]; 

            for(i=0;i < str.length(); i++){
                if(top==-1 && str.at(i)==')'){
                    cout << "Invalid Input.\n";
                    break;
                }
                else{
                    if(str.at(i)=='(')
                        push(str.at(i));
                    else if(str.at(i)==')')
                        pop();
                }
            }
            if(i == str.length()){
                if (top==-1)
                    cout << "Balanced Paranthesis.\n";
                else
                    cout << "Paranthesis not Balanced.\n";
            }
        }
        void push(char c){
            if(top==size-1);
            else{
                arr[++top] = c;
            }
        }

        void pop(){
            if(top==-1);
            else{
                top--;
            }
        }

        void display(){
            if(top==-1)
                cout << "No values in the stack";
            else{
                cout << "Values inside the stack is: \n";
                for(int i=top;i >=0; i--)
                    cout << arr[i] << endl;
            }
        }
};

int main(){
    stack s;
    s.balancing();
}