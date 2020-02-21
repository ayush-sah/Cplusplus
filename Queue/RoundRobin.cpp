#include<iostream>
using namespace std;

/*
    multidimentional array
    0 - arrival time
    1 - copy of arrival time
    2 - burst time
    3 - copy of burst time
    4 - completion time
    5 - Turn Around Time
    6 - Waiting Time
*/

class queue{
    int **rr, num, tq, min, time, tbt, i, *cirq, front, rear, flag, tat, wt;
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
            cout << "\nEnter the arrival time for Process " << i+1 << ": ";
            cin >> rr[i][0];
            rr[i][1] = rr[i][0];
            cout << "Enter the burst time for Process " << i+1 << ": ";
            cin >> rr[i][2];
            rr[i][3] = rr[i][2];
            tbt += rr[i][2];
        }
        cout << "\nEnter time quantum: ";
        cin >> tq;
        cout << "\nThe values you entered are: " << endl;
        cout << "\t|\tPROCESS\t|\t|\tArrival\t|\t|\tBurst\t|" << endl;
        cout << "     ____________________________________________________________________" << endl << endl;
        for(int i = 0; i < num; i++)
            cout << "\t|\tP" << i+1 << "\t|\t|\t"<< rr[i][0] << "\t|\t|\t" << rr[i][2] <<"\t|"<< endl;
        cout << endl;
        cirq = new int[num];
        cout << "Execution queue is ";
        queuing();
        while(time<tbt){
            if((front==-1) && (rear==-1)){
                cout << "IDLE" << " ";
                time++;
            }
            else{
                if(rr[cirq[front]][3]>tq){
                    cout << "P" << cirq[front]+1 << " ";
                    rr[cirq[front]][3] -= tq;
                    time += tq;
                }
                else{
                    time += rr[cirq[front]][3];
                    rr[cirq[front]][3] = 0;
                    cout << "P" << cirq[front]+1 << " ";
                    rr[cirq[front]][4] = time;
                }
            }
            queuing();
            dequeue();
        }
        cout << endl;
        tat = wt = 0;
        for(int i = 0; i < num; i++){
            rr[i][5] = rr[i][4] - rr[i][0];
            tat += rr[i][5];
        }
        for(int i = 0; i < num; i++){
            rr[i][6] = rr[i][5] - rr[i][2];
            wt += rr[i][6];
        }
        cout << "Avg Turn Around time is " << tat/num << endl;
        cout << "Avg Waiting time is " << wt/num << endl;
    }

    void queuing(){
        for(int i = 0; i < num; i++){
            flag = 0;
            if((front!=-1)&&(rear!=-1)){
                for(int j = front; j != rear; ++j %= num){
                    if(cirq[j] == i)
                        flag = 1;
                }
                if(cirq[rear]==i)
                    flag = 1;
            }
            if(flag == 0){
                if((rr[i][3]>0) && (rr[i][1] <= time))
                    enqueue(i);
            }
        }
    }
    void display(){
        if(front==-1)
            cout << "No data to display.\n";
        else{
            cout << "Queue is ";
            for(int i = front; i != rear; ++i %= num)
                cout << cirq[i] << " ";
            cout << cirq[rear] << endl;
        }
    }
    void enqueue(int a){
        if((front==-1)&&(rear==-1)){
            front = rear = 0;
            cirq[rear] = a;
        }
        else{
            ++rear %= num;
            cirq[rear] = a;
        }
    }
    void dequeue(){
        if(rear==front)
            rear = front = -1;
        else
            ++front %= num;
    }

};

int main(){
    queue q;
}