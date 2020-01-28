#include<iostream>
using namespace std;

class arrays{
    private:
        int size, temp, arr[100], pass, lock;
        bool swapping;
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
            quick_sort(0 , size-1);
        }
        void display(){
          cout << "Pass " << ++pass << ": ";
          for(int i = 0; i < size; i++){
              cout << arr[i] << " ";
          }
          cout << endl;
        }
        void quick_sort(int start, int end){
            if(start < end){
              lock = partition(start, end);
              quick_sort(start, lock-1);
              quick_sort(lock+1, end);
            }
        }
        int partition(int start,int end){
          int pivot = arr[start];
          int i = start;
          int j = end;
          while(i<j){
            while(arr[i] <= pivot)
                i++;

            while(arr[j] > pivot)
                j--;

            if(i < j){
              temp = arr[i];
              arr[i] = arr[j];
              arr[j] = temp;
            }
          }
          if(arr[start]!=arr[j]){
            temp = arr[start];
            arr[start] = arr[j];
            arr[j] = temp;
            display();
          }
          return j;
        }
};

int main(){
    arrays ob;
    ob.getdata();
}
