//Write a program to implement circular queue using linked list

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
}*front=NULL, *rear=NULL, *p, *q, *r, *s;

class cirq{
    int action, value, element;
    public:
    cirq(){
        do{
            cout << endl << "1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter action you want to perform: ";
            cin >> action;
            switch (action){
                case 1:
                    enqueue();
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    break;
                default:
                    cout << "Invalid entry.\nTry again.\n";
                    break;
            }
        }while(action!=4);
    }

    
    void enqueue(){
        cout << "Enter value you want to insert: ";
        cin >> value;
        p = (struct node*)malloc(sizeof(node));
        q = (struct node*)malloc(sizeof(node));
        p->data = value;
        rear = p;
        if(front==NULL){
            p->next = p;
            front = p;
        }
        else{
            q = front;
            while(q->next!=front)
                q = q->next;
            q->next = p;
            p->next = front;
        }
    }
    
    void dequeue(){
        if(front==NULL)
            cout << "List is empty nothing to delete.";
        else{
            p = front;
            q = front;
            while(p->next!=front){
                p = p->next;
            }
            if(front == p){
                front = NULL;
                rear = NULL;
            }
            else{
                p->next = q->next;
                front =front->next;
            }
            cout << "Element has been deleted." << endl;
        } 
    }

    void display(){
        if(front==NULL)
            cout << "No Element in the Queue." << endl;
        else{
            p = front;
            cout << "Elements in the Queue are: ";
            do{
                cout << p->data << " ";
                p = p->next;
            }while(p!=front);
            cout << endl;
        }
    }
};

int main(){
    cirq ob;
}
