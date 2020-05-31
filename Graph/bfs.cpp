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

    void bfs(){
        int front = 0, rear = -1, *queue = new int[nodes], k = 0;
        check = new bool[nodes]{false};
        check[0] = true;
        enqueue(queue, rear, 0);
        cout << "\n<------------BFS------------>";
        while(front < nodes){
            cout << "\nPass = " << front << "  Front = " << front << "  Rear = " << rear << "  Queue = ";
            for(int i = front; i <= rear; i++)
                cout << char(queue[i] + 'A') << " ";
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
            cout << char(answer[i] + 'A') << " ";
        cout << endl << endl;
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
    ob.input();
    ob.bfs();
}