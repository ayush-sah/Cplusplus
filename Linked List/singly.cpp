#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
}*list=NULL, *p, *q, *r, *s;

class singly{
    int action, value, element;
    public:
    singly(){
        do{
            cout << endl << "1. Insert at Begining\n2. Insert at the End\n3. Insert Before an element.\n4. Insert after an element\n5. Delete at beginning\n6. Delete at end\n7. Delete Particular value\n8. Display\n10. Exit\nEnter action you want to perform: ";
            cin >> action;
            switch (action)
            {
                case 1:
                    insert_b();
                    break;
                case 2:
                    insert_e();
                    break;
                case 3:
                    insert_be();
                    break;
                case 4:
                    insert_ae();
                    break;
                case 5:
                    delete_b();
                    break;
                case 6:
                    delete_e();
                    break;
                case 7:
                    delete_v();
                    break;
                case 8:
                    display();
                    break;
                case 10:
                    break;
            default:
                break;
            }
        }while(action!=10);
    }

    void insert_b(){
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

    void insert_e(){
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
    void insert_be(){
        cout << "Enter element before you want to insert the value: ";
        cin >> element;
        cout << "Enter value you want to insert: ";
        cin >> value;
        p = (struct node*)malloc(sizeof(node));
        p->data = value;
        q = list;
     
        while((q->data != element) && (q->next != NULL)){
            r = q;
            q = q->next;
        }
        if(q->data==element)
         {
            if(list->data==element){
            p->next = q;
            list = p;
            }
            else{
            r->next = p;
            p->next = q;
            }
        }
        else{
            cout << "Data not found.";
        }
        
    }
    void insert_ae(){
        cout << "Enter element after you want to insert the value: ";
        cin >> element;
        cout << "Enter value you want to insert: ";
        cin >> value;
        p = (struct node*)malloc(sizeof(node));
        p->data = value;
        q = list;
        r = q->next;
        while((q->data != element) && (q->next != NULL)){
            q = r;
            r = r->next;
        }
        if(q->data != element)
            cout << "Data not found.";
        else if(r == NULL){
            q->next = p;
            p->next = NULL;
        }
        else{
            q->next = p;
            p->next = r;
        }
    }

    void delete_b(){
        if(list==NULL)
            cout << "List is empty nothing to delete.";
        else{
            list = list->next;
        } 
    }

    void delete_e(){
        p = list;
        if(list==NULL)
            cout << "List is empty nothing to delete.";
        else{
            while(p->next)
        }
    }

    void delete_v(){

    }

    void display(){
        if(list==NULL)
            cout << "No Element in the linked list.";
        else{
            p = list;
            cout << "Elements in the linked list are: ";
            while(p!=NULL){
                cout << p->data << " ";
                p = p->next;
            }
        }
    }

};
int main(){
    singly s;
}