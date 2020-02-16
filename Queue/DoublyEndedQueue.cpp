#include<iostream>

using namespace std;

class queue{
    int *arr, size, front, rear, rev_front, rev_rear;

    public:
    queue(){
        cout << "Enter size of queue: ";
        cin >> size;
        front = 0; rear = -1;
        rev_front = size-1; rev_rear = size;
        arr = new int[size];
        for(int i = 0; i < size; i++)
            arr[i] = '\0';
        int action;
        do{
            cout << "\n1. Front Enqueue\n2. Rear Enqueue\n3. Front Dequeue\n4. Rear Dequeue\n5. Display\n6. Exit\nEnter action you want to perform: ";
            cin >> action;
            switch (action){
            case 1: front_enqueue(); break;
            case 2: rear_enqueue();  break;
            case 3: front_dequeue(); break;
            case 4: rear_dequeue();  break;
            case 5: display();       break;
            case 6: break;
            default:
                cout << "Invalid input." << endl;
                break;
            }
        }while(action != 6);
    }

    void front_enqueue(){
        int value;
        if(rear+1==rev_rear && arr[rear+1]!='\0'){
            if(rev_rear != size)
                cout << "Delete from rear side to add more elements.\n";
            else
                cout << "Overflow.\n";
        }
        else{
            cout << "Enter value you want to insert: ";
            cin >> value;
            arr[++rear] = value;    
        }
    }
    
    void rear_enqueue(){
        int value;
        if(rev_rear-1==rear && arr[rev_rear-1]!='\0'){
            if(rear!=-1)
                cout << "Delete from front side to add more elements.\n";
            else
                cout << "Overflow\n";
        }
        else{
            cout << "Enter value you want to insert: ";
            cin >> value;
            arr[--rev_rear] = value;    
        }
    }

    void front_dequeue(){
        if(front>rear)
            cout << "No Element to delete from the Front side.\n";
        else{
            cout << arr[front] << " has been removed.\n";
            arr[front++] = '\0';
        }
    }

    void rear_dequeue(){
        if(rev_front<rev_rear)
            cout << "No Element to delete from the Rear side.\n";
        else{
            cout << arr[rev_front] << " has been removed.\n";
            arr[rev_front--] = '\0';
        }
    }

    void display(){
        if(rear==-1 & rev_rear==-1)
            cout << "No data to Display.";
        else{
            cout << "Queue is ";
            for(int i = 0; i < size; i++){
                if (arr[i] == '\0')
                    cout << "NULL";
                else
                    cout << arr[i];
                cout << " ";
            }
        }
        cout << endl;
    }
};

int main(){
    queue q;
}