#include<bits/stdc++.h>
using namespace std;

class toh{
    int n, *tower1, *tower2, *tower3, top1, top2, top3, moves, val;
    public:
    toh(){
        cout << "Enter the number of disks: ";
        cin >> n;
        tower1 = new int[n]{0};
        tower2 = new int[n]{0};
        tower3 = new int[n]{0};
        for(int i = 0; i < n; i++)
            tower1[i] = n-i;
        top1 = n-1;
        top2 = top3 = -1;
        moves = pow(2,n)-1;
        for(int i = 1; i <= moves; i++){
            cout << endl;
            cout << "<---Step - " << i-1 << "--->" << endl;
            display();
            if(i%3==1){
                if(tower1[top1]==0){
                    val = pop(tower3, top3);
                    push(tower1, top1, val);
                }
                else if(tower3[top3]==0){
                    val = pop(tower1, top1);
                    push(tower3, top3, val);
                }
                else if(tower1[top1] > tower3[top3]){
                    val = pop(tower3, top3);
                    push(tower1, top1, val);
                }
                else{
                    val = pop(tower1, top1);
                    push(tower3, top3, val);
                }
            }
            else if(i%3==2){
                if(tower1[top1]==0){
                    val = pop(tower2, top2);
                    push(tower1, top1, val);
                }
                else if(tower2[top2]==0){
                    val = pop(tower1, top1);
                    push(tower2, top2, val);
                }
                else if(tower1[top1] > tower2[top2]){
                    val = pop(tower2, top2);
                    push(tower1, top1, val);
                }
                else{
                    val = pop(tower1, top1);
                    push(tower2, top2, val);
                }
            }
            else if(i%3==0){
                if(tower2[top2]==0){
                    val = pop(tower3, top3);
                    push(tower2, top2, val);
                }
                else if(tower3[top3]==0){
                    val = pop(tower2, top2);
                    push(tower3, top3, val);
                }
                else if(tower2[top2] > tower3[top3]){
                    val = pop(tower3, top3);
                    push(tower2, top2, val);
                }
                else{
                    val = pop(tower2, top2);
                    push(tower3, top3, val);
                }
            }
        }
        cout << endl;
        cout << "<---Step - " << moves << "--->" << endl;
        display();
    }

    void push(int *tower, int &top, int val){
        tower[++top] = val;
    }

    int pop(int *tower, int &top){
        int x = tower[top];
        tower[top--] = 0;
        return x;
    }
    void display(){
        for(int i = n-1; i >= 0; --i){
            if(tower1[i]==0)
                cout << "\t   ";
            else
                cout << "\t  " << tower1[i];
            if(tower2[i]==0)
                cout << "\t\t    ";
            else
                cout << "\t\t   " << tower2[i];
            if(tower3[i]==0)
                cout << "\t\t     " << endl;
            else
                cout << "\t\t    " << tower3[i] << endl;
        }
        cout << "\tTower-1 \t Tower-2 \t Tower-3" << endl;
    }
};



int main(){
    toh ob;
}