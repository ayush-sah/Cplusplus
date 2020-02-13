#include<iostream>
using namespace std;

class queue{
    int **rr, num, *q, tbt;
    public:
    queue(){
        cout << "Enter the number of process: ";
        cin >> num;
        rr = new int*[num];
        tbt = 0;
        for(int i = 0; i < num; i++){
            rr[i] = new int[2];
            cout << "Enter the arrival time for Process" << i+1 << ":";
            cin >> rr[i][0];
            cout << "Enter the burst time for Process" << i+2 << ":";
            cin >> rr[i][1];
            tbt += rr[i][1];
        }
        q = new int[num];
        while(tbt!=0){
            
        }


    }

};

int main(){
    queue q;
}