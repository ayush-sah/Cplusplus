#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
}*list=NULL, *p, *q, *r, *s;

class linkedlist{
    int action, value, element;
    public:
    linkedlist(){
        do{
            cout << endl << "1. Insert\n2. Display\n3. Exit\nEnter action you want to perform: ";
            cin >> action;
            switch (action)
            {
                case 1:
                    insert();
                    break;
                case 2:
                    display();
                    break;
                case 3:
                    break;
            default:
                break;
            }
        }while(action!=3);
    }
    void insert(){
        int v;
        cout << "Enter value you want to insert: ";
        cin >> v;
        v%2==0?insert_e(v):insert_b(v);
    }
    void insert_b(int value){
        p = (struct node*)malloc(sizeof(node));
        p->data = value;
        if(list==NULL)
            p->next = NULL;
        else
            p->next = list;
        list = p;
    }

    void insert_e(int value){
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
    void display(){
        if(list==NULL)
            cout << "No Element in the linked list." << endl;
        else{
            p = list;
            cout << "Elements in the linked list are: ";
            while(p!=NULL){
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
};

int main(){
    linkedlist obj;
}