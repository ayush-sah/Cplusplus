#include<iostream>
using namespace std;

struct poly1{
    int coeff, exponent;
    struct node *next;
}*list = NULL, *p, *q, *r, *s;

struct poly2{
    int coeff, exponent;
    struct node *next;
}*list = NULL, *p, *q, *r, *s;

struct ans{
    int coeff, exponent;
    struct node *next;
}*list = NULL, *p, *q, *r, *s;

class polynomial{
    string str[100];
    public:
    polynomial(){
        num = 0;
        cout << "Enter first Polynomial: ";
        while (cin.peek()!='\n'){
            if(cin.peek()=='+'){
                num++;
                str[num] = "";
            }
            cin >> c;
            str[num] += c;
        }
    }
    void insert_e(int c, int e, ){
        p = (struct node*)malloc(sizeof(node));
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
};

int main(){
    polynomial linkedList;
}