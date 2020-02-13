#include<iostream>

using namespace std;

class queue{
    int *arr, size, front, rear;

    public:
    queue(){
        cout << "Enter size of queue: ";
        cin >> size;
        front = rear = -1;
        arr = new int[size];
        int action;
        do{
            cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter action you want to perform: ";
            cin >> action;
            switch (action){
            case 1:enqueue();break;
            case 2:dequeue();break;
            case 3:display();break;
            case 4:          break;
            default: cout << "Invalid input. Try Again" << endl;
            }
        }while(action != 4);
    }
    void enqueue(){
        int value;
        if((front == -1)&&(rear=-1)){
            front = rear = 0;
            cout << "Enter value: ";
            cin >> value;
            arr[rear] = value;
        }
        else if((rear+1)%size==front){
            cout << "Overflow.\n";
        }
        else{
            cout << "Enter value: ";
            cin >> value;
            ++rear %= size;
            arr[rear] = value;
        }
    }
    void dequeue(){
        if(rear==-1&&front==-1){
            cout << "Underflow\n";
        }
        else{
            if(rear==front){
                cout << arr[front] << " has been removed.\n";
                rear = front = -1;
            }
            else{
                cout << arr[front] << " has been removed.\n";
                ++front %=size;
            }
        }
    }
    void display(){
        if(front==-1)
            cout << "No data to display.\n";
        else{
            cout << "Queue is ";
            for(int i = front; i != (rear+1)%size; ++i %= size)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main(){
    queue q;
}
