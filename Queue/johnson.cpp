#include<iostream>

using namespace std;

class queue{
    int **table, num, rear, rev_rear, min, **copy, *q;

    public:
    queue(){
        cout << "Enter the no. of processes: ";
        cin >> num;
        rear = -1;
        rev_rear = num;
        table = new int*[num];
        for(int i = 0; i < num; i++){
            table[i] = new int[3];
            table[i][0] = i+1;
            cout << "Enter execution time for Process " << table[i][0] << " on Machine 1 : ";
            cin >> table[i][1];
            cout << "Enter execution time for Process " << table[i][0] << " on Machine 2 : ";
            cin >> table[i][2];
        }
        copy = table;
        min = 0;
        for(int i = 0; i < num; i++){
            cout << copy[i][i];
        }

    }
    int minimum(){

    }
    void front_enqueue(int process){q[++rear] = process;}
    
    void rear_enqueue(int process){q[--rev_rear] = process;}

    void display(){
    }
};

int main(){
    queue q;
}