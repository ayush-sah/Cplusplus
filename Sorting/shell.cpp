#include<iostream>
using namespace std;

class arrays{
    private:
        int size, temp, arr[100], pass, max;
        bool swap;
    public:
        void getdata(){
            cout <<"Enter the size of array: ";
            cin >> size;

            for(int i = 0; i < size; i++){
                cout << "Enter element no. " << i+1 << " : ";
                cin >> arr[i];
            }
            pass = -1;
            cout << endl;
            display();
        }
        void display(){
          cout << "Pass " << ++pass << ": ";
          for(int i = 0; i < size; i++){
              cout << arr[i] << " ";
          }
          cout << endl;
        }
        void shell_sort(){
          getdata();
          for(int increment = size/2; increment > 0; increment /= 2){
            for(int j = increment; j < size; j++){
              swap = false;
              for(int k = j - increment; k >= 0; k -= increment){
                if(arr[k+increment] > arr[k]){
                  break;
                }
                else{
                  temp = arr[k+increment];
                  arr[k+increment] = arr[k];
                  arr[k] = temp;
                  swap = true;
                }
              }
            }
            if(swap == true){
            display();
            }
          }
        }
};

int main(){
    arrays ob;
    ob.shell_sort();
}
