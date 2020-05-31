#include<bits/stdc++.h>
using namespace std;

class graph{
    int nodes, **adj_mat;
    public:
    void adjacency_matrix(){
        cout << "Enter the number of nodes in the Graph: ";
        cin >> nodes;
        adj_mat = new int*[nodes];
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
};

int main(){
    graph ob;
    ob.adjacency_matrix();
}