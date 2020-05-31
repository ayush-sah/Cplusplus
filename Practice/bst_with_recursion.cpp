#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
}*list = NULL, *p, *q, *r, *s;

class BST{
    public:
    BST(){
        int action;
        do{
            cout << "\n1. Add Element to BST\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Exit\nEnter action you want to perform: ";
            cin >> action;
            switch (action){
            case 1:
                add();
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorder(list);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorder(list);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postorder(list);
                cout << endl;
                break;
            case 5:
                break;
            default:
                cout << "INVALID INPUT";
                break;
            }
        }while(action!=5);
    }

    void add(){
        int value;
        cout << "Enter data you want to insert: ";
        cin >> value;
        p = (struct node*)malloc(sizeof(node));
        p->data = value;
        p->left = NULL;
        p->right = NULL;
        if(list == NULL){
            list = p;
        }
        else{
            q = list;
            while(q->left || q->right){
                if(q->data > value){
                    if(q->left)
                        q = q->left;
                    else
                        break;
                }
                else if(q->data < value){
                    if(q->right)
                        q = q->right;
                    else
                        break;
                }
                else{
                    cout << "Same value cannot be entered twice in BST.";
                    return;
                }
            }
            if(q->data > value)
                q->left = p;
            else if(q->data < value)
                q->right = p;
        }
    }

    void inorder(struct node *l){
        if(l){
            inorder(l->left);
            cout << l->data << " ";
            inorder(l->right);
        }
    }
    void postorder(struct node *l){
        if(l){
            postorder(l->left);
            postorder(l->right);
            cout << l->data << " ";
        }
    }
    void preorder(struct node *l){
        if(l){
            cout << l->data << " ";
            preorder(l->left);
            preorder(l->right);
        }
    }
};



int main(){
    BST recursion;
}