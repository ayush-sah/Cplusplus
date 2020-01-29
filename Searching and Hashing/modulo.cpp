#include<iostream>
using namespace std;

class hashing{
    private:
        int n, size, arr[100], input, location;
    public:
        void modulo(){
            do{
                cout << "Enter the size of the array: ";
                cin >> size;
                cout << "Enter the no. of digits you want to insert: ";
                cin >> n;
            }while(n>size);

            for(int i = 0; i < size; i++)
                arr[i] = NULL;
                
            while(n--){
                cout << "\nEnter value you want to insert: ";
                cin >> input;
                location = input % size;
                while(arr[location]!=0){
                    if(location < size-2)
                        location++;
                    else
                        location = 0;
                }
                arr[location] =  input;
            }
            cout << "\n<---Index---><---Values--->\n";
            for(int i = 0; i < size; i++){
                cout << "Index no. " << i << " : \t" << arr[i] << endl;
            }
        }
};

int main(){
    hashing ob;
    ob.modulo();
}