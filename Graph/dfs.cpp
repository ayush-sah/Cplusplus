#include<bits/stdc++.h>
using namespace std;

class graph_traversal{
    int nodes, **adj_mat, *answer;
    bool *check;
    public:
    void input(){
        cout << "Enter the number of nodes in the Graph: ";
        cin >> nodes;
        adj_mat = new int*[nodes];
        check = new bool[nodes];
        answer = new int[nodes];
        for(int i = 0; i < nodes; i++){
            adj_mat[i] = new int[nodes];
            for(int j = 0; j < nodes; j++){
                cout << char('A'+i) << " --> " << char('A'+j) << " (Enter 0 or 1): ";
                cin >> adj_mat[i][j];
            }
            cout << endl;
        }
    }

    void dfs(){
        int top = -1, *stack = new int[nodes], k = 0;
        check = new bool[nodes]{false};
        check[0] = true;
        push(stack, top, 0);
        cout << "\n<------------DFS------------>";
        while(top!=-1){
            cout << "\nPass = " << k << "  Top = " << top << "  Stack = ";
            for(int i = 0; i <= top; i++)
                cout << char(stack[i] + 'A') << " ";
            answer[k++] = pop(stack, top);
            for(int i = 0; i < nodes; i++){
                if(adj_mat[answer[k-1]][i]==1){
                    if(check[i]==false){
                        check[i] = true;
                        push(stack, top, i);
                    }
                }
            }
        }
        cout << "\nDFS Sequence = ";
        for(int i = 0; i < nodes; i++)
            cout << char(answer[i] + 'A') << " ";
        cout << endl << endl;
    }

    void push(int* s,int &t, int v){
        s[++t] = v;
    }

    int pop(int* s, int &t){
        return s[t--];
    }
};

int main(){
    graph_traversal ob;
    ob.input();
    ob.dfs();
}