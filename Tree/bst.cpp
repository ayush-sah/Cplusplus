#include<iostream>
using namespace std;


struct node{
    int date;
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
                    display();
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
        }while(action!=6)
    }
    insert(){
        int value;
        cout << "Enter value you want to insert: ";
        cin >> value;

        if(list == NULL){
            
        }
    }
    display(){

    }
    traversal(){

    }
    delete_e(){

    }
    search(){

    }
}


int main(){
    bst tree;
}