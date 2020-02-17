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

        cout << "\nThe values you entered are: " << endl;
        cout << "\t|  PROCESS |\t| MACHINE 1 |\t| MACHINE 2 |" << endl;
        cout << "     ___________________________________________________" << endl << endl;
        for(int i = 0; i < num; i++)
            cout << "\t|    P" << table[i][0] << "    |\t|     "<<    table[i][1] << "     |\t|     " << table[i][2] << "     |" << endl;
        cout << endl;
        /*
        int count = 0;
        copy = table;
        while(count!=num){
            min = 2147483647;
            cout << "m " << min;
            for(int i = 0; i < num; i++){
                if(copy[i][1]<min && copy[i][1]!=0)
                    min = copy[i][1];
                if(copy[i][2]<min && copy[i][2]!=0)
                    min = copy[i][2];
            }
            cout << "min " << min << endl;
            for(int i = 0; i < num; i++){
                if(min==copy[i][1]){
                    front_enqueue(copy[i][0]);
                    count++;
                    delete[] copy[i];
                }
                else if(min==copy[i][2]){
                    rear_enqueue(copy[i][0]);
                    count++;
                    delete[] copy[i];
                }
            }
            cout << "count " << count << endl;
        }
        display();
        */

    }
    int minimum(){

    }
    void front_enqueue(int process){q[++rear] = process;}
    
    void rear_enqueue(int process){q[--rev_rear] = process;}

    void display(){
        for(int i = 0; i < num; i++)
            cout << q[i] << " ";
    }
};

int main(){
    queue q;
}