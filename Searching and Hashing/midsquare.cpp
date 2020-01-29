#include<iostream>
#include<math.h>
using namespace std;

class hashing{
    private:
        int n, size, *arr, input;
        unsigned long int index;
    public:
        hashing(){
            do{
                cout << "Enter the size of the array: ";
                cin >> size;
                cout << "Enter the no. of digits you want to insert: ";
                cin >> n;
            }while(n>size);
            
            arr = new int[size];

            for(int i = 0; i < size; i++)
                arr[i] = -1;
        }

        void midsquare(){
            while(n--){
                cout << "\nEnter value you want to insert: ";
                cin >> input;
                
                if (input < 0){
                    cout << "Invalid Input. Try Again\n";
                    n++;continue;
                }

                index = input*input;

                while(int(log10(index)+1)>2){
                    index /= 10;
                    index %= int(pow(10.0,float(int(log10(index)))));
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
            display();
        }

        void display(){
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