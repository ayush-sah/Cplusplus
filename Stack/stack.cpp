#include<iostream>
#include<string>
using namespace std;

class stack{
    int size, *arr, top, action;
    string str;
    public:
        stack(){
            cout << "Enter size of array: ";
            cin >> size;
            arr = new int[size];
            top = -1;
            do{
                cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter action no. you want to perform: ";
                cin >> action;
                switch (action)
                {
                    case 1:
                        push();
                        break;
                    case 2:
                        pop();
                        break;
                    case 3:
                        display();
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Invalid input.";
                }
            }while(action != 4);
        }

        void push(){
            if(top==size-1)
                cout << "Stack overflow.";
            else{
                int value;
                cout << "Enter value you want to insert: ";
                cin >> value;
                arr[++top] = value;
                cout << "Value inserted.";
            }
        }

        void pop(){
            if(top==-1)
                cout << "Stack Underflow.";
            else{
                cout << "Deleted: " << arr[top--];
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

}