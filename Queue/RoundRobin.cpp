#include<iostream>
using namespace std;

/*
    multidimentional array
    0 - arrival time
    1 - burst time
    2 - copy of burst time
    3 - waiting time
*/

class queue{
    int **rr, num, tq, min, time, tbt, i, *cirq, front, rear;
    public:
    queue(){
        front = rear = -1;
        cout << "Enter the number of process: ";
        cin >> num;
        rr = new int*[num];
        tbt = 0;
        for(i = 0; i < num; i++){
            rr[i] = new int[4];
            cout << "Enter the arrival time for Process" << i+1 << ":";
            cin >> rr[i][0];
            cout << "Enter the burst time for Process" << i+2 << ":";
            cin >> rr[i][1];
            rr[i][2] = rr[i][1];
            tbt += rr[i][1];
            rr[i][3] = {0};
        }
        cout << "Enter time quantum: ";
        cin >> tq;
        cout << min;
        time = minimum(rr[0]);
        cirq = new int[num];
        while(time<tbt){
            for(i = 0; i < num; i++){
                if(rr[0][i] <= time)
                    enqueue(i);
            }
            for()
        }
    }
    int minimum(int *a){
        min = a[0];
        for(int j = 0; j < sizeof(a)/sizeof(int); j++){
            if (min > a[j])
                min = a[j];
        }
    }
    void enqueue(int a){
        if(front == -1){
            front = rear = 0;
            cirq[rear] = a;
        }
        else{
            ++rear %= num;
            cirq[rear] = a;
        }
    }
    void dequeue(int a){
        if(rear==front){
            rear = front = -1;
        }
        else{
            ++front %= num;
        }
        
    }

};

int main(){
    queue q;
}