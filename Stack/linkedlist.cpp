#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
}*list=NULL, *p, *q, *r, *s;

class stack{
    int action, value;
    string str;
    public:
        stack(){
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
            cout << "Enter value you want to insert: ";
            cin >> value;
            p = (struct node*)malloc(sizeof(node));
            p->data = value;
            if(list==NULL)
                p->next = NULL;
            else
                p->next = list;
            list = p;
        }

        void pop(){
            if(list==NULL)
                cout << "Stack is empty nothing to delete.";
            else{
                cout << list->data << " has been popped." << endl;
                list = list->next;
            }
        }

        void display(){
        if(list==NULL)
            cout << "No Element in the stack.";
        else{
            p = list;
            cout << "Elements in the stack are: ";
            while(p!=NULL){
                cout << p->data << " ";
                p = p->next;
            }
        }
    }        
};

int main(){
    stack s;

}