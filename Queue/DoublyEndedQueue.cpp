//incomplete

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
            cout << "1. Front Enqueue\n2. Rear Enqueue\n3. Front Dequeue\n4. Rear Dequeue\n5. Display\n6. Exit\nEnter action you want to perform: ";
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
        }while(action != 4);
    }

    void front_enqueue(){
        int value;
        if(front == -1){
            front = rear = 0;
            cout << "Enter value: ";
            cin >> value;
            arr[rear] = value;
        }
        else{
            if(front==0)
                front = size;
            
            if((front-1)%size==rear){
                cout << "Overflow.\n";
            }
            else{
                cout << "Enter value: ";
                cin >> value;
                --front %= size;
                arr[front] = value;
            }
        }
    }

    void rear_enqueue(){
        int value;
        if(front == -1){
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

    void front_dequeue(){
        if(rear==-1&&front==-1){
            cout << "Underflow\n";
        }
        else{
            if(rear==front){
                cout << arr[front] << " has been removed.\n";
                rear = front = -1;
            }
            else{
                ++front %=size;
            }
        }
    }

    void rear_dequeue(){
        if(rear==-1&&front==-1){
            cout << "Underflow\n";
        }
        else{
            if(rear==front){
                cout << arr[front] << " has been removed.\n";
                rear = front = -1;
            }
            else{
                --rear %=size;
            }
        }
    }

    void display(){
        if(front==-1)
            cout << "No data to display.\n";
        else{
            int temp = front;
            cout << "Queue is ";
            do{
                cout << arr[temp] << " ";
                ++temp %= size;
            }while(temp!=(rear+1)%size);
        }
    }
};

int main(){
    queue q;
}
