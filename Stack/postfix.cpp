#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class stack{
    private:
    string str[100];
    int *arr, top, action, i, temp, s;
    public:
        stack(){
            cout << "Enter a string: ";
            s=0;
            char c;
            str[0] = "";
            while (cin.peek()!='\n'){
                if(cin.peek()==' '){
                    s++;
                    str[s] = "";
                }
                cin >> c;
                str[s]+=c;
            }
            str[++s]=")";
            top = -1;
            if (isNumber(str[0])==1 && isNumber(str[1])==1){
                arr = new int[s+1];
                for(i = 0; str[i] != ")"; i++){
                    if(isNumber(str[i])==1){
                        push(stoi(str[i]));
                    }
                    else if((str[i] == "+")||(str[i] == "-")||(str[i] == "*")||(str[i] == "/")){
                        int a = pop();
                        int b = pop();
                        switch (char(str[i][0])){
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
                if(top == 0)
                    cout << "Answer = " << arr[0] << endl;
                else
                    cout << "Wrong Postfix operation.";
            }
            else
                cout << "Not a Postfix expression.\n";
        }
        void push(int n){
            if(top==s)
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
        bool isNumber(string s) 
        {
            for (int i = 0; i < s.length(); i++) 
                if (isdigit(s[i]) == false) 
                    return false; 
        
            return true; 
        }
};

int main(){
    stack s;
}