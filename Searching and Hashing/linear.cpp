#include<iostream>
using namespace std;

class searching{
    private:
        int size, arr[100], key, i;
        bool found;
    public:
        void getdata(){
            cout <<"Enter the size of array: ";
            cin >> size;

            for(int i = 0; i < size; i++){
                cout << "Enter element no. " << i+1 << " : ";
                cin >> arr[i];
            }
            cout << endl;
        }
        void linear_search(){
            getdata();
            cout << "Enter a key element to search in the array: ";
            cin >> key;
            found = false;
            for(i = 0; i < size; i++)
            {
                if(arr[i]==key){
                    found = true;
                    break;
                }
            }
            if(found)
                cout << "Element is present at index number: " << i << " and location number: " << i+1 << endl;
            else
            {
                arr[size++] = key;
                cout << "Element not found in the array and has been added to the last of array.\nArray elements: ";
                display();
            }
        }
        void display(){
            for(i = 0; i < size; i++)\
                cout << arr[i] << " ";
            cout << endl;
        }
        
};

int main(){
    searching ob;
    ob.linear_search();
}