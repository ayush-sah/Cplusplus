#include<iostream>
using namespace std;

class hashing{
    private:
        int n, size, *arr, input, index;
    public:
        hashing(){
            do{
                cout << "Enter the size of the array: ";
                cin >> size;
                cout << "Enter the no. of digits you want to insert: ";
                cin >> n;
            }while(n>size);
            
            arr = new int[size];

            for(int i = 0; i < size; i++)
                arr[i] = -1;
        }
        void modulo(){
            cout << endl;
            while(n--){
                cout << "Enter value you want to insert: ";
                cin >> input;
                
                if (input < 0){
                    cout << "Invalid Input. Try Again\n";
                    n++;continue;
                }
                
                index = input % size;
                
                linear_probing();
                arr[index] =  input;
            }
            display();
        }
        void linear_probing(){
            while(arr[index]!=-1){
                if(index < size-2)
                    index++;
                else
                    index = 0;
            }
        }
        /*
        void quadratic_probing(){
            int num = 0;
            while(arr[index]!=-1){
                index = input;
                index = input    + pow(index, ) 
            }
        }
        */
        void display(){
            cout << "\n<---Index---><---Values--->\n";
            for(int i = 0; i < size; i++){
                cout << "Index no. " << i << " : \t";
                
                if(arr[i]==-1)
                    cout << "NULL" << endl;
                else
                    cout << arr[i] << endl;
            }
        }
};

int main(){
    hashing ob;
    ob.modulo();
}