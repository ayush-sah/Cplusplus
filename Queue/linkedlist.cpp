#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
}*list=NULL, *p, *q, *r, *s;

class queue{
    int action, value;

    public:
    queue(){
        do{
            cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter action you want to perform: ";
            cin >> action;
            switch (action)
            {
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
                cout << "Invalid input." << endl;
                break;
            }
        }while(action != 4);
    }
    void enqueue(){
        cout << "Enter value you want to insert: ";
        cin >> value;
        p = (struct node*)malloc(sizeof(node));
        q = (struct node*)malloc(sizeof(node));
        p->data = value;
        if(list==NULL){
            p->next = NULL;
            list = p;
        }
        else{
            q = list;
            while(q->next!=NULL)
                q = q->next;
            q->next = p;
            p->next = NULL;
        }
    }

    void dequeue(){
        if(list==NULL)
            cout << "Queue is empty nothing to delete." << endl;
        else{
            cout << list->data << " has been removed." << endl;
            list = list->next;
        }
    }

    void display(){
        if(list==NULL)
            cout << "No Element in the Queue.";
        else{
            p = list;
            cout << "Elements in the Queue are: ";
            while(p!=NULL){
                cout << p->data << " ";
                p = p->next;
            }
        }
    }
};

int main(){
    queue q;
}
