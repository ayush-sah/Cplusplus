#include<iostream>
#include<stack>
using namespace std;


struct node{
    int data;
    struct node *lptr, *rptr;
}*list = NULL, *p, *q, *r, *s;

class tree_sort{
    public:
    tree_sort(){
        int action;
        do{
            cout << "\n1. Insert Element.\n2. Sort and Display.\n3. Exit\nEnter action you want to perform: ";
            cin >> action;
            switch (action)
            {
                case 1:
                    insert();
                    break;
                case 2:
                    cout << "Sorted: ";
                    sort(list);
                    break;
                case 3:
                    cout << endl;
                    break;
                default:
                    cout << "Invalid Input. Please try again." << endl;
                    break;
            }
        }while(action!=3);
    }
    void insert(){
        int value;
        cout << "Enter value you want to insert: ";
        cin >> value;
        p = (struct node*)malloc(sizeof(node));
        p->data = value;
        p->lptr = NULL;
        p->rptr = NULL;
        if(list == NULL){
            list = p;
        }
        else{
            q = list;
            while(q->lptr || q->rptr){
                if(value < q->data){
                    if(q->lptr)
                        q = q->lptr;
                    else
                        break;
                }
                else if(value > q->data){
                    if(q->rptr)
                        q = q->rptr;
                    else
                        break;
                }
            }
            if(value < q->data)
                q->lptr = p;
            else if(value > q->data)
                q->rptr = p;
        }
    }

    void sort(struct node *l){
        if(l){
            sort(l->lptr);
            cout << l->data << " ";
            sort(l->rptr);
        }
    }
};

int main(){
    tree_sort obj;
}