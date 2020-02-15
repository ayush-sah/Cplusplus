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
    int **rr, num, tq, min, time;
    public:
    queue(){
        cout << "Enter the number of process: ";
        cin >> num;
        rr = new int*[num];
        tbt = 0;
        for(int i = 0; i < num; i++){
            rr[i] = new int[4];
            cout << "Enter the arrival time for Process" << i+1 << ":";
            cin >> rr[i][0];
            cout << "Enter the burst time for Process" << i+2 << ":";
            cin >> rr[i][1];
            rr[i][2] rr[i][1];
            tbt += rr[i][1];
            cout << "Enter time quantum: ";
            cin >> tq;
        }
        rr[i][3] = {0};
        q = new int[num];
        while(tbt!=0){
            
        }
    }
    int minimum(int *a){
        min = a[0];
        for(int i = 0; i < a.length(); i++){
            if (min > a[i])
                min = a[i];
        }
    }

};

int main(){
    queue q;
}