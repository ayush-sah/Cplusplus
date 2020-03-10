#include<iostream>
using namespace std;

struct node{
    int coeff, exponent;
    struct node *next;
}*poly1 = NULL, *poly2 = NULL, *poly3 = NULL, *p, *q;

class polynomial{
    string str[100];
    public:
    polynomial(){
        int size, c, e;

        cout << "Enter size of first Polynomial: ";
        cin >> size;
        while(size--){
            cout << "Enter co-efficient and exponent: ";
            cin >> c >> e;
            insert(c,e,&poly1);
        }

        cout << "\nEnter size of second Polynomial: ";
        cin >> size;
        while(size--){
            cout << "Enter co-efficient and exponent: ";
            cin >> c >> e;
            insert(c,e,&poly2);
        }

        cout << "The 1st polynomial is: ";
        display(&poly1);
        cout << "\t\t\t\t+" << endl;
        cout << "The 2nd polynomial is: ";
        display(&poly2);


        while(poly1 || poly2){
            if(poly1 && poly2){
                if(poly1->exponent > poly2->exponent){
                    insert(poly1->coeff,poly1->exponent,&poly3);
                    poly1 = poly1->next;
                }
                else if(poly1->exponent < poly2->exponent){
                    insert(poly2->coeff,poly2->exponent,&poly3);
                    poly2 = poly2->next;
                }
                else{
                    insert(poly1->coeff + poly2->coeff,poly2->exponent,&poly3);
                    poly1 = poly1->next;
                    poly2 = poly2->next;
                }
            }
            else{
                if(poly1){
                    insert(poly1->coeff,poly1->exponent,&poly3);
                    poly1 = poly1->next;
                }
                if(poly2){
                    insert(poly2->coeff,poly2->exponent,&poly3);
                    poly2 = poly2->next;
                }
            }
        }
        cout << "\t\t\t\t=" << endl;
        cout << "\tAfter adding : ";
        display(&poly3);
    }

    void insert(int c, int e, struct node **list){
        p = (struct node*)malloc(sizeof(node));
        p->coeff = c;
        p->exponent = e;
        p->next = NULL;
        if(*list==NULL){
            *list = p;
        }
        else{
            q = *list;
            while(q->next!=NULL)
                q = q->next;
            q->next = p;
        }
    }

    void display(struct node **list){
        p = *list;
        while(p->next!=NULL){
            cout << p->coeff << "x^" << p->exponent << " + ";
            p = p->next;
        }
        if(p->exponent==0)
            cout << p->coeff << endl;
        else
            cout << p->coeff << "x^" << p->exponent << endl;
    }
};

int main(){
    polynomial linkedList;
}