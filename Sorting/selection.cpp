#include<iostream>
using namespace std;

class arrays{
    private:
        int size, temp, arr[100], pass;
        bool swap;
    public:
        void getdata(){
            cout <<"Enter the size of array: ";
            cin >> size;

            for(int i = 0; i < size; i++){
                cout << "Enter element no. " << i+1 << " : ";
                cin >> arr[i];
            }
            cout << "Pass 0: ";
            for(int i = 0; i < size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        void selection_sort(){
            int max;
            for(int i = 0; i < size; i++){
                max = 0;
                for(int j = 1; j < size - i; j++){
                    if(arr[j]>arr[max]){
                        max = j;
                    }
                }
                    temp = arr[size-i];
                    arr[size-i] = arr[max];
                    arr[max] = temp;
                    
                    cout << "Pass " << i+1 << ": "; 
                    for(int i = 0; i < size; i++)
                        cout << arr[i] << " ";  
                    cout << endl;
                
            }
            cout << endl;
        }
};

int main(){
    arrays ob;
    ob.getdata();
    ob.selection_sort();
}
