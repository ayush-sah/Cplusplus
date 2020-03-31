#include<iostream>
using namespace std;


struct node{
    int data;
    struct node *lptr, *rptr;
}*list = NULL, *p, *q, *r, *s;

class bst{
    public:
    bst(){
        int action;
        do{
            cout << "\n1. Insert Element into Binary Search Tree.\n2. Display Binary Search Tree elements.\n3. Traversal of Binary Search Tree.\n4. Delete elements from Binary Search Tree\n5. Search an element.\n6. Exit\nEnter action you want to perform: ";
            cin >> action;
            switch (action)
            {
                case 1:
                    insert();
                    break;
                case 2:
                    cout << "Elements in the tree are: ";
                    display(list);
                    cout << endl;
                    break;
                case 3:
                    traversal();
                    break;
                case 4:
                    delete_e();
                    break;
                case 5:
                    search();
                    break;
                case 6:
                    break;
                default:
                    cout << "Invalid Input. Please try again." << endl;
                    break;
            }
        }while(action!=6);
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
    void display(struct node *l){
        if(l){
            display(l->lptr);
            cout << l->data << " ";
            display(l->rptr);
        }
    }
    void traversal(){
        int action, subaction;
        cout << "\n1. Inorder\n2. Preorder\n3. Postorder\nEnter the type of traversal you want to perform: ";
        cin >> action;
        cout << "\n1. with Recursion\n2. without Recursion\nEnter which type of traversal you want to perform: ";
        cin >> subaction;
        switch(action){
            case 1:
                switch(subaction){
                    case 1:
                        cout << "Inorder traversal: ";
                        inorder_rec(list);
                        break;
                    case 2:
                        inorder_nonrec(list);
                        break;
                    default:
                        cout << "Invalid option. Start Again.";
                }
                break;
            
            case 2:
                switch(subaction){
                    case 1:
                        cout << "Preorder traversal: ";
                        preorder_rec(list);
                        break;
                    case 2:
                        preorder_nonrec(list);
                        break;
                    default:
                        cout << "Invalid option. Start Again.";
                }
                break;
            case 3:
                switch(subaction){
                    case 1:
                        cout << "Postorder traversal: ";
                        postorder_rec(list);
                        break;
                    case 2:
                        postorder_nonrec(list);
                        break;
                    default:
                        cout << "Invalid option. Start Again.";
                }
                break;
            default:
                cout << "Invalid option. Start Again.";
        }
    }

    void inorder_rec(struct node *l){
        if(l){
            inorder_rec(l->lptr);
            cout << l->data << " ";
            inorder_rec(l->rptr);
        }
    }

    void inorder_nonrec(){
        if(list){
            p = list;
            while(p){
                if(p->lptr==NULL){
                    cout << p->data << " ";
                    p = p->rptr;
                }
                else{
                    q = p->lptr;
                    while((q->rptr) && (q->rptr!=p))
                        q = q->rptr;
                    
                    if(q->rptr!=p){
                        q->rptr = p;
                        p = p->lptr;
                    }
                    else{
                        cout << p->data << " ";
                        q->rptr = NULL;
                        p = p->rptr;
                    }
                }
            }
        }
    }

    void preorder_rec(struct node *l){
        if(l){
            cout << l->data << " ";
            preorder_rec(l->lptr);
            preorder_rec(l->rptr);
        }
    }

    void preorder_nonrec(){
        if(list){
            p = list;
            while(p){
                if(p->lptr==NULL){
                    cout << p->data << " ";
                    p = p->rptr;
                }
                else{
                    q = p->lptr;
                    while((q->rptr) && (q->rptr!=p))
                        q = q->rptr;
                    
                    if(q->rptr==p){
                        q->rptr = NULL;
                        p = p->rptr;
                    }
                    else{
                        cout << p->data << " ";
                        q->rptr = p;
                        p = p->lptr;
                    }
                }
            }
        }
    }

    void postorder_rec(struct node *l){
        if(l){
            postorder_rec(l->lptr);
            postorder_rec(l->rptr);
            cout << l->data << " ";
        }
    }

    void postorder_nonrec(){
        if(list){
            stack<node *> s1, s2;
            s1.push(list);
            
            while(!s1.empty()){
                p = s1.top();
                s1.pop();
                s2.push(p);

                if(p->lptr)
                    s1.push(p->lptr);
                if(p->rptr)
                    s1.push(p->rptr);
            }

            while(!s2.empty()){
                cout << s2.top()->data << " ";
                s2.pop();
            }
        }
    }

    void delete_e(){
        int key;
        cout << "Enter the element you want to delete: ";
        cin >> key;
        if (list == NULL)
        {
            cout<<"Tree empty"<<endl;
            return;
        }
        
    }

    void search(){
        int key, level = -1;
        cout << "Enter key you want to search: ";
        cin >> key;

        p = list;

        while(p){
            level++;
            if(p->data == key){
                cout << "Key found at level " << level << endl;
                return;
            }
            else if(p->data > key)
                p = p->lptr;
            else
                p = p->rptr;
        }
        cout << "Key not found." << endl;
    }
};

int main(){
    bst tree;
}