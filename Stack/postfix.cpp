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
                for(i = 0; i < str.length(); i++){
                    temp = 0;
                    while(str.at(i)!=' '){
                        temp += str.at(0) - '0';
                    }
                    cout << temp;
                }
            }
            else
                cout << "Not a Postfix expression.\n";
        }
        void push(int n){
            if(top==str.length()-1);
            else{
                arr[++top] = n;
            }
        }

        void pop(){
            if(top==-1);
            else{
                top--;
            }
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