#include<iostream>
using namespace std;

class arrays{
    private:
        int size, temp, arr[100], pass, i;
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
            pass=0;
        }

        void insertion_sort(){
            for(i = 1; i < size; i++){
              swap = false;
              temp = arr[i];
              int j = i-1;
              while(j>=0 && arr[j]>temp){
                arr[j+1]=arr[j];
                j--;
              }
            arr[j+1]=temp;
            cout << "Pass " << ++pass << ": ";
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
    ob.insertion_sort();
}
