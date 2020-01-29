#include<iostream>
#include<math.h>
using namespace std;

class hashing{
    private:
        int n, size, *arr, input, no_of_digits, divisor;
        unsigned long int location;
    public:
        void midsquare(){
            do{
                cout << "Enter the size of the array: ";
                cin >> size;
                cout << "Enter the no. of digits you want to insert: ";
                cin >> n;
            }while(n>size);
            
            arr = new int[size];

            for(int i = 0; i < size; i++)
                arr[i] = -1;

            while(n--){
                cout << "\nEnter value you want to insert: ";
                cin >> input;

                location = input*input;

                while(int(log10(location)+1)>2){
                    location /= 10;

                    no_of_digits = log10(location);
                    divisor = pow(10.0,float(no_of_digits));
                    location %= divisor;

                    if(location<size)
                        break;
                }

                if(location>=size)
                    location = location%size;

                while(arr[location]!=-1){
                    if(location < size-2)
                        location++;
                    else
                        location = 0;
                }

                arr[location] = input;
            }

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
    ob.midsquare();
}