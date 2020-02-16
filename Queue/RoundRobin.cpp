#include<iostream>
using namespace std;

/*
    multidimentional array
    0 - arrival time
    1 - copy of arrival time
    2 - burst time
    3 - copy of burst time
    4 - waiting time
*/

class queue{
    int **rr, num, tq, min, time, tbt, i, *cirq, front, rear, process;
    public:
    queue(){
        front = rear = -1;
        cout << "Enter the number of process: ";
        cin >> num;
        rr = new int*[num];
        tbt = 0;
        time = 0;
        for(i = 0; i < num; i++){
            rr[i] = new int[10];
            cout << "Enter the arrival time for Process " << i+1 << ":";
            cin >> rr[i][0];
            rr[i][1] = rr[i][0];
            cout << "Enter the burst time for Process " << i+1 << ":";
            cin >> rr[i][2];
            rr[i][3] = rr[i][2];
            tbt += rr[i][2];
        }
        cout << "Enter time quantum: ";
        cin >> tq;
        cirq = new int[num];
        while(time<tbt){
            for(i = 0; i < num; i++){
                if(rr[i][3]>0){
                    if(rr[i][1] <= time)
                        enqueue(i);
                }
            }
            for(i=front;i!=rear;++i%=num){
                process = dequeue();
                if(rr[process][3]>=tq){
                    rr[process][3] -= tq;
                    cout << "P" << process+1 << "-->";
                    time += tq;
                    rr[process] += tq;
                }
                else{
                    time += rr[process][3];
                    rr[process][3] = 0;
                    cout << "P" << process+1 << "-->";
                }
            }
        }
    }
    /*
    int minimum(int *a){
        min = a[0];
        for(int j = 0; j < sizeof(a)/sizeof(int); j++){
            cout << a[j] << endl;
            if (min > a[j])
                min = a[j];
        }
    }
    */
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
    int dequeue(){
        int k = front;
        if(rear==front)
            rear = front = -1;
        else
            ++front %= num;
        return k;
    }

};

int main(){
    queue q;
}