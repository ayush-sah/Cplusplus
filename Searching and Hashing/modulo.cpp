#include<iostream>
using namespace std;

class hashing{
    private:
        int n, size, arr[100], input, index;
    public:
        void modulo(){
            do{
                cout << "Enter the size of the array: ";
                cin >> size;
                cout << "Enter the no. of digits you want to insert: ";
                cin >> n;
            }while(n>size);

            for(int i = 0; i < size; i++)
                arr[i] = 0;
                
            while(n--){
                cout << "\nEnter value you want to insert: ";
                cin >> input;
                index = input % size;
                while(arr[index]!=0){
                    if(index < size-2)
                        index++;
                    else
                        index = 0;
                }
                arr[index] =  input;
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
