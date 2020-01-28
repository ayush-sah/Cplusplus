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

        void sortdata(){
            pass=0;
            for(int i = 0; i < size; i++){
                swap = false; 
                for(int j = 0; j < (size-i)-1; j++){
                    if(arr[j]>arr[j+1]){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                        pass++;
                        swap = true;
                    }
                }
                if(pass==0){
                    cout << "Array is already sorted.";
                    break;
                }
                else if(swap==true){
                    cout << "Pass " << i+1 << ": "; 
                    for(int i = 0; i < size; i++)
                        cout << arr[i] << " ";  
                    cout << endl;
                }
                else
                    break;
            }
            cout << endl;
        }
};

int main(){
    arrays ob;
    ob.getdata();
    ob.sortdata();
}
