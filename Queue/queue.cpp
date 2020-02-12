#include<iostream>

using namespace std;

class queue{
    int *arr, size, front, rear;

    public:
    queue(){
        cout << "Enter size of queue: ";
        cin >> size;
        front = 0;
        rear = -1;
        arr = new int[size];
        int action;
        do{
            cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter action you want to perform: ";
            cin >> action;
            switch (action)
            {
            case 1:
                enqueue();
                break;
            
            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;
            
            case 4:
                break;
            
            default:
                cout << "Invalid input." << endl;
                break;
            }
        }while(action != 4);
    }
    void enqueue(){
        int value;
        if(rear>=size-1)
            cout << "Overflow\n";
        else{
            cout << "Enter value you want to insert: ";
            cin >> value;
            arr[++rear] = value;    
        }
    }

    void dequeue(){
        if(front>rear){
            cout << "Underflow\n";
            front = 0;
            rear = -1;
        }
        else
            cout << arr[front++] << " has been removed.\n";
    }

    void display(){
        if(front>rear)
            cout << "No data to display.\n";
        else{
            cout << "Queue is ";
            for(int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        }
    }
};

int main(){
    queue q;
}