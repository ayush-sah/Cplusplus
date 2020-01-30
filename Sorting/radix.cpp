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
		if(arr[i]<0){
			cout << "Invalid input." << endl;
			i--;		
		}
            }
            pass = 0;
            cout << endl;
            display();
        }
        void display(){
          cout << "Pass " << pass++ << ": ";
          for(int i = 0; i < size; i++){
              cout << arr[i] << " ";
          }
          cout << endl;
        }
        int get_max(){
          max = arr[0];
          for(int i = 1; i < size; i++){
            if (max < arr[i])
              max = arr[i];  
          }
        }
        void radix_sort(){

          getdata();
          get_max();
          
          for(int pos = 1; max/pos>0; pos*=10){
            int temp_arr[size];
          
            int freq[10] = {0};
            for(int i = 0; i < size; i++)
              ++freq[(arr[i]/pos)%10];

            for(int i = 1; i <= 9; i++)
              freq[i] += freq[i-1];

            for(int i = size - 1; i >= 0; i--)
              temp_arr[--freq[(arr[i]/pos)%10]] = arr[i];

            for(int i = 0; i < size; i++)
              arr[i] = temp_arr[i];

              display();
          }
        }
};

int main(){
    arrays ob;
    ob.radix_sort();
}
  
