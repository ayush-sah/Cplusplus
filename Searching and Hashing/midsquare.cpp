#include<iostream>
#include<math.h>
using namespace std;

class hashing{
    private:
        int n, size, *arr, input, no_of_digits, divisor;
        unsigned long int index;
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

                index = input*input;

                while(int(log10(index)+1)>2){
                    index /= 10;

                    no_of_digits = log10(index);
                    divisor = pow(10.0,float(no_of_digits));
                    index %= divisor;

                    if(index<size)
                        break;
                }

                if(index>=size)
                    index = index%size;

                while(arr[index]!=-1){
                    if(index < size-2)
                        index++;
                    else
                        index = 0;
                }

                arr[index] = input;
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