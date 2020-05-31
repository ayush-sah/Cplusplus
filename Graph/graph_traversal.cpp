#include<bits/stdc++.h>
using namespace std;

class graph_traversal{
    int nodes, **adj_mat, *answer;
    bool *check;
    public:
    void adjacency_matrix(){
        cout << "Enter the number of nodes in the Graph: ";
        cin >> nodes;
        adj_mat = new int*[nodes];
        check = new bool[nodes];
        answer = new int[nodes];
        cout << endl;
        for(int i = 0; i < nodes; i++){
            adj_mat[i] = new int[nodes];
            for(int j = 0; j < nodes; j++){
                cout << char('A'+i) << " --> " << char('A'+j) << " (Enter 0 or 1): ";
                cin >> adj_mat[i][j];
            }
            cout << endl;
        }
        cout << "\nAdjacency Matrix:   ";
        for(int i = 0; i < nodes; i++){
            cout << char('A'+i) << " ";
        }
        cout << endl;
        for(int i = 0; i < nodes; i++){
            cout << "\t\t  " << char('A'+i) << " ";
            for(int j = 0; j < nodes; j++)
                cout << adj_mat[i][j] << " ";
            cout << endl;
        }
    }

    void dfs(){
        int top = -1, *stack = new int[nodes], k = 0;
        check = new bool[nodes]{false};
        check[0] = true;
        push(stack, top, 0);
        cout << "\n\n<------------DFS------------>";
        while(top!=-1){
            cout << "\nPass = " << k << "  Top = " << top << "  Stack = ";
            for(int i = 0; i <= top; i++)
                cout << stack[i] << " ";
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
            cout << answer[i] << " ";
        cout << endl << endl;
    }

    void push(int* s,int &t, int v){
        s[++t] = v;
    }

    int pop(int* s, int &t){
        return s[t--];
    }

    void bfs(){
        int front = 0, rear = -1, *queue = new int[nodes], k = 0;
        check = new bool[nodes]{false};
        check[0] = true;
        enqueue(queue, rear, 0);
        cout << "\n\n<------------BFS------------>";
        while(front < nodes){
            cout << "\nPass = " << front << "  Front = " << front << "  Rear = " << rear << "  Queue = ";
            for(int i = front; i <= rear; i++)
                cout << queue[i] << " ";
            answer[k++] = dequeue(queue, front);
            for(int i = 0; i < nodes; i++){
                if(adj_mat[answer[k-1]][i]==1){
                    if(check[i]==false){
                        check[i] = true;
                        enqueue(queue, rear, i);
                    }
                }
            }
        }
        cout << "\nBFS Sequence = ";
        for(int i = 0; i < nodes; i++)
            cout << answer[i] << " ";
        cout << endl;
    }

    void enqueue(int* q, int &r, int v){
        q[++r] = v;
    }

    int dequeue(int* q, int &f){
        return q[f++];
    }

};

int main(){
    graph_traversal ob;
    ob.adjacency_matrix();
    ob.bfs();
    ob.dfs();
}