#include<iostream>
using namespace std;

struct node{
    int coeff, exponent;
    struct node *next;
}*list[3], *p, *q, *r, *s;

class singly{
    int c, e, nodes1, nodes2, i;
    public:
    singly(){
        i = 0;
        list = NULL;
        cout << "Enter no. of nodes int 1st equation: ";
        cin >> nodes1;
        while(nodes1--){
            cout << "Enter coeff: ";
            cin >> c;
            cout << "Enter its exponent: ";
            cin >> e;
            insert_e();
            cout << endl;
        }
        i++;
        cout << "Enter no. of nodes int 2nd equation: ";
        cin >> nodes2;
        while(nodes2--){
            cout << "Enter coeff: ";
            cin >> c;
            cout << "Enter its exponent: ";
            cin >> e;
            insert_e();
            cout << endl;
        }
        i++;
        display();

    }
    /*
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
    */
    void insert_e(){
        p = (struct node*)malloc(sizeof(node));
        p->coeff = c;
        p->exponent = e;
        if(list==NULL){
            p->next = NULL;
            list[i] = p;
        }
        else{
            q = list[i];
            while(q->next!=NULL)
                q = q->next;
            q->next = p;
            p->next = NULL;
        }
    }
    /*
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
            cout << "Element has been deleted." << endl;
        } 
    }

    void delete_e(){
        p = list;
        if(list==NULL)
            cout << "List is empty nothing to delete.";
        else{
            while(p->next != NULL){
                q = p;
                p = p->next;
            }
            q->next = NULL;
            cout << "Element has been deleted." << endl;
        }
    }

    void delete_v(){
        p = list;
        q = p;
        if(list==NULL)
            cout << "List is empty nothing to delete.";
        else{
            cout << "Enter value you want to delete: ";
            cin >> value;
            while(p->data != value && p->next!=NULL){
                q = p;
                p = p->next;
            }
            if(p->data != value)
                cout << "Element not found.";
            else{
                if(p==q)
                    list = p->next;
                else
                    q->next = p->next;
                
                cout << "Element has been deleted." << endl;
            }
        }
    }
    */

    void display(){
        if(list[0]==NULL)
            cout << "No Element in the linked list.";
        else{
            p = list[0];
            cout << "Elements in the linked list are: ";
            while(p!=NULL){
                cout << p->coeff << " ";
                p = p->next;
            }
        }
    }
    /*
    void count(){
        int count = 0;
        p = list;
        while(p != NULL){
            count++;
            p = p->next;
        }
        cout << "Count = " << count << endl;
    }

    void reverse(){
        if(list==NULL)
            cout << "No Element in the linked list.";
        else{
            struct node *temp;
            q = s = list;
            temp = NULL;
            r = q->next;
            while(r->next!=NULL){
                temp = q;
                q = r;
                r = q->next;
                q->next = temp;
            }
            list = q;
            s->next = NULL;
            cout << "Linked List has been reversed.";
        }
    }

    void sort(){
        p = list;
        int temp;
        while(p->next!=NULL){
            q = p->next;
            while(q->next!=NULL){
                if(p->data > q->data){
                    temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
                q = q->next;
            }
            p = p->next;
        }
    }
    */
};

int main(){
    singly linkedList;
}